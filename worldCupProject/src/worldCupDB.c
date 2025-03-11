/*
 * Assignment 4: World Cup Database
 * Professor Beldman
 * Author: Sinthuja Jeevarajhan
 * Date: Nov 10 2022
 * Purpose: Database storing all teams (nations) which will be used throughout the World Cup. Can perform multiple functions to add, update, search and remove teams
 *
 */

#include <stdio.h>
//Include string.h for the string compare and string copy function
#include<string.h>

//method to remove extra spaces and store in a character array
void read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /* terminates string */
}
//method to clear the spaces after character input
void clear(void) {
    while (getchar() != '\n');
}
//Structure for each team, stores the team code, char array for team name, seeding and char array of the colour
struct team {
    int code;
    char teamName[25];
    char seeding[2];
    char colour[10];
} team[31]; //stores a maximum of 31 teams
//Function to check if the code is valid or if the team already exists
int checkCode(int code, int numTeam) {
    int i = 0;
    if (code < 0 || code > 31) {
        //output this message if the code is invalid
        printf("Error: Code must be between 0 and 31\n");
        return 0;
    }
    while (i <= numTeam) {
        if (team[i].code == code) {
            //output this message if the team code already exists
            printf("Error: Team %d already exists.\n", code);
            return 0;
        }
        i++;
    }
    return 1;

}

//Function to check if the name is valid or if the team name already exists
int checkName(char name[], int numTeam) {
    int i = 0;
    while (i <= numTeam + 1) {
        if (strcmp(team[i].teamName, name) == 0) {
            //output this message if team name exists
            printf("Error: Team already exists.\n");
            return 0;
        }
        i++;
    }
    return 1;
}

//Function to check if the seeding is valid or if the seeding already exists
int checkSeeding(char seedLetter, int seedInt, int numTeam) {
    if (seedLetter != 'A' && seedLetter != 'B' && seedLetter != 'C' && seedLetter != 'D' && seedLetter != 'E' &&
        seedLetter != 'F' && seedLetter != 'G' && seedLetter != 'H') {
        //output this message if the letter of the seed is incalid
        printf("Error: Seed must be between A-H\n");
        return 0;
    }
    if (seedInt < 1 || seedInt > 4) {
        //output this message if the number is invalid
        printf("Error: Seed must be between 1-4\n");
        return 0;
    }
    int i = 0;
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
    while (i <= numTeam + 1) {
        if (team[i].seeding[0] == seedLetter) {
            if (team[i].seeding[1] == seedNewLetter) {
                //output if the seeding already exists
                printf("Error: Seeding already exists.\n");
                return 0;
            }
        }
        i++;
    }
    return 1;
}

//function to check if the colour is invalid
int checkColour(char colour) {
    if (colour != 'R' && colour != 'O' && colour != 'Y' && colour != 'G' && colour != 'B' && colour != 'I' &&
        colour != 'V') {
        printf("Error: Colour must be Red, Green, Blue, Yellow, Green or Violet\n");
        return 0;
    }
    return 1;
}

//Main function
int main() {
    //Declare variables used throughout the program
    int code, seedInt, check, i;
    int numTeam = -1;
    char choice, seedLetter, colour, seedNewLetter, name[25];
    //Infinite loop, breaks if user enters 'q'
    while (1) {
        //Prompt the user to enter an operation
        printf("\nEnter command (i,p,u,s,q): ");
        scanf("%c", &choice);
        clear();
        //quit if the user enters q
        if (choice == 'q') {
            return 0;
        }
        //switch that executes according to the specfic operation
        switch (choice) {
            //insert option- allows the user to add a team to the database
            case 'i' :
                //Executes if the maximum number of teams are stored
                if (numTeam == 31) {
                    printf("Number of teams limit reached maximum.");
                    break;
                }
                //Prompt the user to enter a team code
                printf("Please enter a team code (0-31): ");
                scanf("%d", &code);
                //call checkCode function to see if team exists or it is invalid
                if (checkCode(code, numTeam + 1) == 0) {
                    //if function returns true- bring the user to the main menu
                    getchar();
                    break;
                }

                //prompt the user to enter a team name
                printf("Enter team name: ");
                //scanf("%[^\n]%*c", name);
                fgets(name, 25, stdin);
                read_line(name, 25);
                //call CheckName function- if function is true return the user to the main menu
                if (checkName(name, numTeam) == 0) {
                    break;
                }
                //prompt the user to enter the seeding
                printf("Enter a letter between A-H for the seeding: ");
                scanf("%c", &seedLetter);
                clear();
                printf("Enter a number between 1-4 for the seeding: ");
                scanf("%d", &seedInt);
                //call checkSeeding- if function returns true, bring the user to the main menu
                if (checkSeeding(seedLetter, seedInt, numTeam) == 0) {
                    break;
                }


                //convert the integer in seeding to character ascii code to store in char array
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
                //prompt the user to enter a colour for their team
                getchar();
                printf("Enter the colour for your team (R,O,Y,G,B,I,V): ");
                scanf("%c", &colour);
                getchar();
                //call the checkColour function- if return true, bring the user to the main menu
                if (checkColour(colour) == 0) {
                    break;
                }



                numTeam++;
                //convert the character colour code to the word form, store in the correct position in the structure
                if (colour == 'R') {
                    strncpy(team[numTeam].colour, "RED", 10);
                }
                if (colour == 'O') {
                    strncpy(team[numTeam].colour, "ORANGE", 10);
                }
                if (colour == 'Y') {
                    strncpy(team[numTeam].colour, "YELLOW", 10);
                }
                if (colour == 'G') {
                    strncpy(team[numTeam].colour, "GREEN", 10);
                }
                if (colour == 'B') {
                    strncpy(team[numTeam].colour, "BLUE", 10);
                }
                if (colour == 'I') {
                    strncpy(team[numTeam].colour, "INDIGO", 10);
                }
                if (colour == 'V') {
                    strncpy(team[numTeam].colour, "VIOLET", 10);
                }
                //Using the string copy function to copy the team name into the structure element
                strncpy(team[numTeam].teamName, name, 25);
                //store all the users values in the correct position in the structure
                team[numTeam].code = code;
                team[numTeam].seeding[0] = seedLetter;
                team[numTeam].seeding[1] = seedNewLetter;
                break;
                //search function- outputs the team details if team exists
            case 's':
                i = 0;
                check = 0;
                //Prompt the user to enter the team code for the team they're searching for
                printf("Enter team code: ");
                scanf("%d", &code);

                //search the structure database for the code
                while (team[i].code != code) {
                    i++;
                }
                //if the code is found- set flag to false
                if (team[i].code == code) {
                    check = 1;
                }
                if (check == 0) {
                    //output error message if team wasn't found
                    printf("Error: Team %d, not found\n", code);
                    //Bring the user back to the main menu
                    break;
                }
                //Print the team details to the screen- with appropriate tabbing
                printf("Team Code\t\tTeam Name\t\t\t\t\t\t\t\tGroup Seeding\tPrimary Kit Colour\n");
                printf("%d\t\t\t\t%-24s\t\t\t\t\t%c%c\t\t\t\t%s\n", team[i].code, team[i].teamName, team[i].seeding[0],
                       team[i].seeding[1], team[i].colour);
                getchar();
                break;
                //Update function- allows the user to update details of an existing team
            case 'u':
                check = 0;
                //prompt the user to enter the team code they're trying to update
                printf("Enter team code: ");
                scanf("%d", &code);
                //search for the team code
                for (int i = 0; i < numTeam + 1; i++) {
                    //if the team code is found
                    if (team[i].code == code) {
                        check = 1;
                        //prompt the user to enter new team name
                        printf("Enter new team name: ");
                        fgets(name, 25, stdin);
                        read_line(name, 25);
                        //scanf("%[^\n]%*c", name);
                        if (checkName(name, numTeam) == 0) {
                            break;
                        }
                        //prompt the user to enter nwew seeding details
                        printf("Enter a letter between A-H for the seeding: ");
                        scanf("%c", &seedLetter);
                        clear();
                        printf("Enter a number between 1-4 for the seeding: ");
                        scanf("%d", &seedInt);
                        //ensure new seeding is unique
                        if (checkSeeding(seedLetter, seedInt, numTeam) == 0) {
                            break;
                        }
                        //convert seeding integer to ASCII
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
                        getchar();
                        //prompt the user to enter a new colour
                        printf("Enter the colour for your team (R,Y,G,B,I,V): ");
                        scanf("%c", &colour);
                        getchar();
                        //ensure the colour is valid
                        if (checkColour(colour) == 0) {
                            break;
                        }
                        //copy the colour to the structure element
                        if (colour == 'R') {
                            strncpy(team[i].colour, "RED", 10);
                        }
                        if (colour == 'O') {
                            strncpy(team[i].colour, "ORANGE", 10);
                        }
                        if (colour == 'Y') {
                            strncpy(team[i].colour, "YELLOW", 10);
                        }
                        if (colour == 'G') {
                            strncpy(team[i].colour, "GREEN", 10);
                        }
                        if (colour == 'B') {
                            strncpy(team[i].colour, "BLUE", 10);
                        }
                        if (colour == 'I') {
                            strncpy(team[i].colour, "INDIGO", 10);
                        }
                        if (colour == 'V') {
                            strncpy(team[i].colour, "VIOLET", 10);
                        }

                        //copy the new team details to the structure element
                        strncpy(team[i].teamName, name, 25);
                        team[i].seeding[0] = seedLetter;
                        team[i].seeding[1] = seedNewLetter;
                    }
                }
                if (check == 0) {
                    //if team wasn't found output this message
                    getchar();
                    printf("Error: Team %d, not found\n", code);
                }
                break;
                //print function- prints all of the team details from the database
            case 'p':
                i = 0;
                printf("Team Code\t\tTeam Name\t\t\t\t\t\t\t\tGroup Seeding\tPrimary Kit Colour\n");
                while (i <= numTeam) {
                    printf("%d\t\t\t\t%-24s\t\t\t\t\t%c%c\t\t\t\t%s\n", team[i].code, team[i].teamName,
                           team[i].seeding[0], team[i].seeding[1], team[i].colour);
                    i++;
                }
                break;

                //if the operation was invalid, output
            default:
                printf("Error: Invalid input, please enter (i,s,u,p,q)\n");

        }
    }
    return 0;
}
