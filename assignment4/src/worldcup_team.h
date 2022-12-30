/*
 * Purpose: Header file storing the definitions for worldcuo_team.c
 * Author: Sinthuja Jeevarjhan
 * Date: Nov 28
 * Professor Beldman
 * Assignment 5: Modified World Cup Assignment
 */
#ifndef ASSIGNMENT5_WORLDCUP_TEAM_H
#define ASSIGNMENT5_WORLDCUP_TEAM_H
//include the libraries that are required in worldcup_team.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The following are function prototypes for the functions in worldcup_team.c
//method to clear the input stream
void clearTeam(void);

//method to check if the colour is valid
int checkColour(char colour);

//method to check if the seeding is valid
int checkSeeding(char colour, int num);

//method to read input from the user
void read_lineTeam(char str[], int n);

//method to check if the team code is valid
int checkTeamCode(int code);

//method to check if the team name is valid
int checkTeamName(char name[]);

//structure that defines the structure for a team
struct team *findTeam(int code);

//insert command
void insertTeam(void);

//search command
void searchTeam(void);

//update command
void updateTeam(void);

//print command
void printTeam(void);

//delete command
void deleteTeam(void);


#endif //ASSIGNMENT5_WORLDCUP_TEAM_H
