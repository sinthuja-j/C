/*
 * Purpose: Header file storing the defintions for worldcup_player.c
 * Author: Sinthuja Jeevarjhan
 * Date: Nov 28
 * Professor Beldman
 * Assignment 5: Modified World Cup Assignment
 */

#ifndef ASSIGNMENT5_WORLDCUP_PLAYER_H
#define ASSIGNMENT5_WORLDCUP_PLAYER_H
//include the libraries that are required in worldcup_player.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//list of function prototypes that are required in worldcup_player.c
//clear funtion- clears the input stream
void clearPlayer(void);
//insert player function
void insertPlayer(void);
//checks if club is valid
int checkClub(int club);
//checks if player code is value
int checkPlayerCode(int code);
//structure that defines player structure
struct player *findPlayer(int code);
//function that reads input from the user
void read_linePlayer(char str[], int n);
//returns structure for finding the team
struct team *findTeam(int code);
//search function
void playerSearch(void);
//update function
void playerUpdate(void);
//print function
void playerPrint(void);
//delete function
void deletePlayer(void);

#endif //ASSIGNMENT5_WORLDCUP_PLAYER_H
