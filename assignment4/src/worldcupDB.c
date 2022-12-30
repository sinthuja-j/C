/*
 * Purpose: Class storing the main function to execute the program
 * Author: Sinthuja Jeevarjhan
 * Date: Nov 28
 * Professor Beldman
 * Assignment 5: Modified World Cup Assignment
 */
//include the header file that stores the function prototypes for this file
#include "worldCupDB.h"

int main() {
    //infinite loop that prompts the user for input from the main menu
    while (1) {
        //store the user input
        char choice, teamChoice, playerChoice;
        //Main menu- prompt the user for a command
        printf("\nEnter command (h,q,t,p): ");
        scanf("%c", &choice);
        getchar(); // get the existing whitespace from the input stream
        //quit if the user enters q
        if (choice == 'q') {
            return 0;
        }
        //switch that contains the menu options
        switch (choice) {
            //help function- teaches the user how to use the program
            case 'h':
                printf("Welcome to the World Cup Database program!\n");
                printf("When viewing the teams (t) database, you can insert new teams (i), delete teams (d), update teams (u), search for teams (s) as well as print them (p)!\n");
                printf("When viewing the players (p) database, you can insert new players (i), delete players (d), update players (u), search for players (s) as well as print them (p)!\n");
                printf("In the main menu you can press h to access this help menu, q to quit the program, c to control the teams and p to control the players\n");
                break;
                //commands to control the teams
            case 't':
                //prompt the user for a team command
                printf("Enter a team command (i,s,u,p,d): ");
                scanf("%c", &teamChoice);
                //switching holding the team commands
                switch (teamChoice) {
                    //insert command
                    case 'i':
                        //call the insert command from worldcup_team
                        insertTeam();
                        break;
                        //search command
                    case 's':
                        //call the search command from worldcup_team
                        searchTeam();
                        break;
                        //update command
                    case 'u':
                        //call the update command from worldcup_team
                        updateTeam();
                        break;
                        //print command
                    case 'p':
                        //call the print command from worldcup_team
                        printTeam();
                        break;
                        //delete command
                    case 'd':
                        //call the delete command from worldcup_team
                        deleteTeam();
                        break;
                }
                //clear the input stream- call the clear function from the player file
                clearPlayer();
                break;
                //commands to control the players
            case 'p':
                //prompt the user to enter a player command
                printf("Enter a player command (i,s,u,p,d): ");
                scanf("%c", &playerChoice);
                //switch to hold all the player commands
                switch (playerChoice) {
                    case 'i':
                        //insert player command
                        //call the insert command from worldcup_player
                        insertPlayer();
                        break;
                    case 's':
                        //search command
                        //call the search command from worldcup_player
                        playerSearch();
                        break;
                    case 'u':
                        //update command
                        //call the update command from worldcup_player
                        playerUpdate();
                        break;
                    case 'p':
                        //print command
                        //call the command command from worldcup_player
                        playerPrint();
                        break;
                    case 'd':
                        //delete command
                        //call the insert command from worldcup_player
                        deletePlayer();
                        break;
                }
                clearPlayer();
                break;
        }

    }
    return 0;
}
