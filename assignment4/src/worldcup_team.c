/*
 * Purpose: Stores the functions that are specific to teams
 * Author: Sinthuja Jeevarjhan
 * Date: Nov 28
 * Professor Beldman
 * Assignment 5: Modified World Cup Assignment
 */
//include the header which stores the definitions for this class
#include "worldcup_team.h"
//structure to hold the teams
struct team *teams = NULL;
//declare variables to be used throughout program
 int seedInt, playerCode;
 char seedLetter, colour, team[25];
 struct team *newPlayer, *checkPlayer, *curPlayer, *prevPlayer;
//structure for the team
struct team {
    int code; //unique code specific to each team
    char teamName[25]; //team name max 25 characters
    char seeding[2]; //team seeding
    char colour[10]; //team colour
    struct team *next; //pointer to the next node
};

//function to clear the input stream
void clearTeam(void) {
    while (getchar() != '\n');
}
//function to check if the colour is valid
int checkColour(char colour) {
    //colour must be part of the rainbow
    if (colour != 'R' && colour != 'O' && colour != 'Y' && colour != 'G' && colour != 'B' && colour != 'I' &&
        colour != 'V') {
        //if they enter the wrong colour- prompt user with error message and return false
        printf("Error: Colour must be Red, Green, Blue, Yellow, Green or Violet\n");
        return 0;
    }
    return 1;
}
//function to check if the seeding is valid
int checkSeeding(char seedLetter, int seedInt) {
    //temp pointer to iterate the linked list
    struct team *p;
    //seeding letter must be between A-H
    if (seedLetter != 'A' && seedLetter != 'B' && seedLetter != 'C' && seedLetter != 'D' && seedLetter != 'E' &&
        seedLetter != 'F' && seedLetter != 'G' && seedLetter != 'H') {
        //output this message if the letter of the seed is invalid
        printf("Error: Seed must be between A-H\n");
        return 0;
    }
    //seeding number must be between 1-4
    if (seedInt < 1 || seedInt > 4) {
        //output this message if the number is invalid
        printf("Error: Seed must be between 1-4\n");
        return 0;
    }
    //letter to hold the int conversion
    char seedNewLetter;
    //convert the number to ASCII code of integer to store in char array
    if (seedInt == 1) {
        seedNewLetter = 49;
    }
    if (seedInt == 2) {
        seedNewLetter = 50;
    }
    if (seedInt == 3) {
        seedNewLetter = 51;
    }
    if (seedInt == 4) {
        seedNewLetter = 52;
    }
    //iterate through the linked list to check if the seeding already exists
    for (p= teams; p!= NULL ; p=p->next) {
        //if the seeding letter matches
        if (p != NULL && seedLetter == p->seeding[0]) {
            //and the seeding int also matches
            if (seedNewLetter == p->seeding[1]) {
                //the seeding exists- output error message and return false
                printf("Error team already exists!");
                return 0;
            }
        }
    }
    //else the seeding is valid- return true
    return 1;
}
//function to read input from the user
void read_lineTeam(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /* terminates string */
}
//function to check if the team code is valid
int checkTeamCode(int code) {
    //temp pointer to iterate through the linked list
    struct team *p;
    //code can't be less than 0
    if (code < 0) {
        printf("Error: Code can't be less than 0");
        return 0;
    }
    //iterate through linked list to see if code exists
    for (p= teams; p!= NULL ; p=p->next) {
        if (p!= NULL && code== p->code) {
            printf("Error %d team already exists!", code);
            return 0;
        }
    }
    //return true if code is unique and valid
    return 1;


}
//function to check if the team name is valid
int checkTeamName(char name[]) {
    //temp pointer to iterate through the linked list
    struct team *p;
    //iterate through linked list to see if the team name exists
    for (p= teams; p!= NULL ; p=p->next) {
        if (p!= NULL && name== p->teamName) {
            printf("Error: team already exists!");
            return 0;
        }
    }
    //return true if the team name is unique
    return 1;
}
//function to find team from linked list
struct team *findTeam(int code) {
    //temp pointer to iterate through the linked list
    struct team *p;
    //iterate through linked list to see if team exists
    for (p= teams; p!= NULL ; p=p->next) {
        if (p!= NULL && code == p->code) {
            return p;
        }
    }
    //return null if team doesn't exist- and prompt user with error message
    printf("Error: Team doesn't exist");
    return NULL;
}
//insert function- called from worldCupDB.c
void insertTeam(void) {
    //create a new node
    newPlayer= malloc(sizeof(struct team));
    newPlayer->next= NULL;
    //if there is no space to hold the new node- there is no space to store a new team
    if (newPlayer == NULL) {
        //prompt user with error message
        printf("Database is full, can't add more teams.\n");
        return;
    }
    //prompt user input- team code
    printf("Please enter a team code: ");
    scanf("%d", &playerCode);
    //call checkCode function to see if team exists or it is invalid
    if (checkTeamCode(playerCode) == 0) {
        //if function returns false- bring the user to the main menu
        //deallocate memory
        free(newPlayer);
        getchar();
        return;
    }
    newPlayer->code= playerCode;
    //prompt user input- team name
    printf("Enter team name: ");
    //store the team name
    fgets(team, 25, stdin);
    //clear the input buffer
    read_lineTeam(team, 25);
    //call CheckName function- if function is false return the user to the main menu
    if (checkTeamName(team) == 0) {
        //deallocate memory
        free(newPlayer);
        return;
    }
    //copy the team node to the new node
    strncpy(newPlayer->teamName, team, 25);
    //prompt teh user for the seeding letter
    printf("Enter a letter between A-H for the seeding: ");
    scanf("%c", &seedLetter);
    getchar();
    //prompt the user for the seeding integer
    printf("Enter a number between 1-4 for the seeding: ");
    scanf("%d", &seedInt);
    //call checkSeeding- if function returns false, bring the user to the main menu
    if (checkSeeding(seedLetter, seedInt) == 0) {
        //deallocate memory
        free(newPlayer);
        return;
    }
    //store the seeding letter in the new node
    newPlayer->seeding[0]= seedLetter;
    //store the seeding number in new node- convert to character
    if (seedInt == 1) {
        newPlayer->seeding[1] = 49;
    }
    if (seedInt == 2) {
        newPlayer->seeding[1] = 50;
    }
    if (seedInt == 3) {
        newPlayer->seeding[1] = 51;
    }
    if (seedInt == 4) {
        newPlayer->seeding[1] = 52;
    }
    getchar();
    //prompt the user to enter a colour
    printf("Enter the colour for your team (R,O,Y,G,B,I,V): ");
    scanf("%c", &colour);
    getchar();
    //call the checkColour function- if return false, bring the user to the main menu
    if (checkColour(colour) == 0) {
        free(newPlayer);
        return;
    }
    //conver the colour letter to word and store in new node
    if (colour == 'R') {
        strncpy(newPlayer->colour, "RED", 10);
    }
    if (colour == 'O') {
        strncpy(newPlayer->colour, "ORANGE", 10);
    }
    if (colour == 'Y') {
        strncpy(newPlayer->colour, "YELLOW", 10);
    }
    if (colour == 'G') {
        strncpy(newPlayer->colour, "GREEN", 10);
    }
    if (colour == 'B') {
        strncpy(newPlayer->colour, "BLUE", 10);
    }
    if (colour == 'I') {
        strncpy(newPlayer->colour, "INDIGO", 10);
    }
    if (colour == 'V') {
        strncpy(newPlayer->colour, "VIOLET", 10);
    }
    //add the new node to the list
    newPlayer->next= curPlayer;
    if (prevPlayer == NULL) {
        teams= newPlayer;
    } else {
        prevPlayer->next= newPlayer;
    }
    //bring the user back to the main menu
    return;
}
//search function- called in worldCupDB
void searchTeam(void) {
    //prompt the user to enter a team code
    printf("Enter team code: ");
    scanf("%d", &newPlayer->code);
    //find the team in the linked list
    checkPlayer= findTeam(newPlayer->code);
    //if the team doesn't exist
    if (checkPlayer == NULL) {
        //deallocate memory
        free(newPlayer);
        return;
    }
    //print the team to the user
    printf("Team Code\t\tTeam Name\t\t\t\t\t\t\t\tGroup Seeding\tPrimary Kit Colour\n");
    printf("%d\t\t\t\t%-24s\t\t\t\t\t%c%c\t\t\t\t%s\n", checkPlayer->code, checkPlayer->teamName, checkPlayer->seeding, checkPlayer->colour);

}
//update function- called in worldCupDB
void updateTeam(void) {
    //prompt the user to enter a team code
    printf("Enter team code: ");
    scanf("%d", &newPlayer->code);
    //find the team
    checkPlayer= findTeam(newPlayer->code);
    //if the team exists
    if (checkPlayer != NULL) {
        //prompt the user to enter a new team name
        printf("Enter team name: ");
        fgets(team, 25, stdin);
        read_lineTeam(team, 25);
        //call CheckName function- if function is false return the user to the main menu
        if (checkTeamName(team) == 0) {
            printf("Team already exists");
            free(newPlayer);
            return;
        }
        //replace the existing team name
        strncpy(checkPlayer->teamName, team, 25);
        //prompt the user to enter a new seeding
        printf("Enter a letter between A-H for the seeding: ");
        scanf("%c", &seedLetter);
        printf("Enter a number between 1-4 for the seeding: ");
        scanf("%d", &seedInt);
        //call checkSeeding- if function returns false, bring the user to the main menu
        if (checkSeeding(seedLetter, seedInt) == 0) {
            printf("Error: Invalid or seeding exists");
            free(newPlayer);
            return;
        }
        if (seedInt == 1) {
            checkPlayer->seeding[1] = 49;
        }
        if (seedInt == 2) {
            checkPlayer->seeding[1] = 50;
        }
        if (seedInt == 3) {
            checkPlayer->seeding[1] = 51;
        }
        if (seedInt == 4) {
            checkPlayer->seeding[1] = 52;
        }
        //replace existing seeding
        checkPlayer->seeding[0]= seedLetter;
        getchar();
        //prompt the user to enter a new colour
        printf("Enter the colour for your team (R,O,Y,G,B,I,V): ");
        scanf("%c", &colour);

        //call the checkColour function- if return false, bring the user to the main menu
        if (checkColour(colour) == 0) {
            printf("Error: Invalid colour");
            free(newPlayer);
            return;
        }
        //replace the current colour
        if (colour == 'R') {
            strncpy(checkPlayer->colour, "RED", 10);
        }
        if (colour == 'O') {
            strncpy(checkPlayer->colour, "ORANGE", 10);
        }
        if (colour == 'Y') {
            strncpy(checkPlayer->colour, "YELLOW", 10);
        }
        if (colour == 'G') {
            strncpy(checkPlayer->colour, "GREEN", 10);
        }
        if (colour == 'B') {
            strncpy(checkPlayer->colour, "BLUE", 10);
        }
        if (colour == 'I') {
            strncpy(checkPlayer->colour, "INDIGO", 10);
        }
        if (colour == 'V') {
            strncpy(checkPlayer->colour, "VIOLET", 10);
        }

    //otherwise the team doesn't exist- output error message
    } else {
        printf("Error: This team does not exist");
        return;
    }

}
//print function- called in worldCupDB
void printTeam(void) {
    //temp pointer to iterate through the linked list
    struct team *p;
    //print all the teams to the user
    printf("Team Code\t\tTeam Name\t\t\t\t\t\t\t\tGroup Seeding\tPrimary Kit Colour\n");
    for (p=teams; p!= NULL; p=p->next) {
        printf("%d\t\t\t\t%-24s\t\t\t\t\t%c%c\t\t\t\t%s\n", p->code, p->teamName, p->seeding, p->colour);

    }

}
//delete function- called in worldCupDB
void deleteTeam(void) {
    //prompt the user to enter a team code
    printf("Enter team code: ");
    scanf("%d", &newPlayer->code);
    //check if the team exists
    for (curPlayer= teams, prevPlayer= NULL; curPlayer != NULL && curPlayer->code != newPlayer->code; prevPlayer= curPlayer, curPlayer= curPlayer->next);
    //cur points to the node to be deleted and prev points to the previous node

    //if there was no node found- deallocate memory
    if (curPlayer == NULL) {
        free(curPlayer);
        free(newPlayer);
        printf("Error: Team &d does not exist", newPlayer->code);
        return;
    }
    //bypass the node being remove- point cur's next pointer to the node after the node deleted
    prevPlayer->next= curPlayer->next;
    //deallocate memory
    free(curPlayer);
}
