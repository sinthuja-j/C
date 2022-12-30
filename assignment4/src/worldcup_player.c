/*
 * Purpose: Stores the functions that are specific to players
 * Author: Sinthuja Jeevarjhan
 * Date: Nov 28
 * Professor Beldman
 * Assignment 5: Modified World Cup Assignment
 */
//include the header which stores the definitions for this class
#include "worldcup_player.h"

//structure to hold the players
extern struct player *players = NULL;
//Declare variables used throughout the program
struct player *cur, *prev, *new_node, *check;
int code, age;
char playerName[50], club[50];
//sturucture of a player
extern struct player {
    int code; //unique player code
    char playerName[50]; //player name up to 50 characters
    int age; //age 17-99
    char club[50]; //club name up to 50 characters
    int team_code; //tean code
    struct player *next; //pointer to the next node
};

//function to clear the input stream
void clearPlayer(void) {
    while (getchar() != '\n');
}

//function to check if the players age is valid
int checkAge(int age) {
    //age must be between 17 and 99
    if (age < 17 || age > 99) {
        //output message if age is invalid
        printf("Error: Age must be between 17 and 99\n");
        return 0;
    }
    //return true if age is valid
    return 1;
}

//function to read input from the user
void read_linePlayer(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /* terminates string */
}

//function to check if the player code is valid
int checkPlayerCode(int code) {
    struct player *p;
    //player code is valid
    if (code < 0) {
        printf("Error: Code can't be less than 0");
        return 0;
    }
    //iterate through linked list to see if code exists
    for (p = players; p != NULL; p = p->next) {
        if (p != NULL && code == p->code) {
            //if code exists- return false and output error message
            printf("Error %d player already exists!", code);
            return 0;
        }
    }
    //return true if code is valid
    return 1;

}

//function to find the player
struct player *findPlayer(int code) {
    struct player *p;
    //iterates through linked list to find player
    for (p = players; p != NULL; p = p->next) {
        if (p != NULL && code == p->code) {
            //if player found return it
            return p;
        }
    }
    //else player doesn't exist- return null
    printf("Error: Player doesn't exist");
    return NULL;
}

//insert function- called in worldCupDB.c
void insertPlayer(void) {
    //allocate space for new node
    new_node = malloc(sizeof(struct player));
    //if there is no space for new node- quit and output error message
    if (new_node == NULL) {
        printf("Database is full, can't add more teams.\n");
        return;
    }
    //prompt the user to enter player code
    printf("Please enter a player code: ");
    scanf("%d", &code);
    //call checkCode function to see if team exists or it is invalid
    if (checkPlayerCode(code) == 0) {
        //if function returns false- bring the user to the main menu
        free(new_node);
        getchar();
        return;
    }
    new_node->code = code;
    //prompt the user to enter player name
    printf("Enter player name: ");
    fgets(playerName, 50, stdin);
    read_linePlayer(playerName, 50);
    strncpy(new_node->playerName, playerName, 50);

    printf("Please enter an age for the player: ");
    scanf("%d", &age);
    //call CheckAge function- if function is false return the user to the main menu
    if (checkAge(age) == 0) {
        //if function returns true- bring the user to the main menu
        free(new_node);
        getchar();
        return;
    }
    new_node->age = age;
    //prompt the user to enter a club name
    printf("Enter club name: ");
    fgets(club, 50, stdin);
    read_linePlayer(club, 50);

    strncpy(new_node->club, club, 50);
    //prompt the user to enter a team code
    printf("Enter team code: ");
    scanf("%d", &new_node->team_code);
    //add the new node (player) to the linked list of players
    new_node->next = cur;
    if (prev == NULL) {
        players = new_node;
    } else {
        prev->next = new_node;
    }
}

//search function- called in worldCupDB
void playerSearch(void) {
    //prompt user to enter player code
    printf("Enter player code: ");
    scanf("%d", &new_node->code);
    //find if player exists
    check = findPlayer(new_node->code);
    //if player doesn't exist quit and output error message
    if (check == NULL) {
        free(new_node);
        printf("Error: Player &d does not exist", new_node->code);
        return;
    }
    //else output the player details
    printf("Player Code\t\tPlayer Namet\t\t\t\t\t\t\t\t\t\t\t\t\t\tAge\t\tProfessional Club Affiliation\n");
    printf("%d\t\t\t\t%-50s\t\t\t\t\t\%d\t\t\t\t\t%-50s\n", check->code, check->playerName, check->age, check->club);

}

//update function- called in worldCupDB
void playerUpdate(void) {
    //prompt the user to enter player code
    printf("Enter player code: ");
    scanf("%d", &new_node->code);
    //find if the player exists
    check = findPlayer(new_node->code);
    //if it exists
    if (check != NULL) {
        //prompt the user to enter a new player name
        printf("Enter player name: ");
        fgets(playerName, 50, stdin);
        read_linePlayer(playerName, 50);

        strncpy(check->playerName, playerName, 50);
        //prompt the user to enter a new age
        printf("Enter player age: ");
        scanf("%d", &check->age);
        //prompr the user to enter a club name
        printf("Enter club name: ");
        fgets(club, 50, stdin);
        read_linePlayer(club, 50);

        strncpy(check->club, club, 50);


    } else {
        //otherwise output error message- team doesn't exist
        printf("Error: This team does not exist");
        return;
    }

}

//print function- called in worldCupDB
void playerPrint(void) {
    struct player *p;
    //print all the players to the user- iterate through the linked list
    printf("Player Code\t\tPlayer Name\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAge\t\tProfessional Club Affiliation\n");
    for (p = players; p != NULL; p = p->next) {
        printf("%d\t\t\t\t%-50s\t\t\t\t\t%d\t\t\t\t%-50s\n", p->code, p->playerName, p->age, p->club);

    }

}

//delete function- called in worldCupDB
void deletePlayer(void) {
    //prompt the user to enter player code
    printf("Enter player code: ");
    scanf("%d", &new_node->code);
    //find the node to be deleted
    for (cur = players, prev = NULL; cur != NULL && cur->code != new_node->code; prev = cur, cur = cur->next);
    //cur points to the node to be deleted and prev points to the previous node
    //if the node doesn't exist- quit and print error message
    if (cur == NULL) {
        free(new_node);
        printf("Error: Team &d does not exist", new_node->code);
        return;
    }
    //otherwise bypass the node and deallocate the memory of the node
    prev->next = cur->next;
    free(cur);

}