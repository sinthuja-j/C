🌍⚽ World Cup Database - Advanced Version 🏆

Overview

This project is an advanced version of the World Cup Database program, designed to handle both teams and players. It allows users to perform various operations such as adding, updating, searching, deleting, and printing information about teams and players participating in the World Cup.

Features

Team Management:

Insert, update, search, delete, and print teams participating in the World Cup.
Each team includes details such as team code, name, seeding, and kit color.
Player Management:

Insert, update, search, delete, and print player information.
Each player is associated with a specific team and can be added or updated in the database.
Main Menu System:

Easy-to-use interface to interact with both team and player databases.
Access help (h), manage teams (t), or manage players (p).

Commands 📋

Main Menu
h - Show help information
q - Quit the program
t - Manage teams
p - Manage players

Team Management (t)

i - Insert a new team
s - Search for a team by code
u - Update a team's information
p - Print all team details
d - Delete a team

Player Management (p)

i - Insert a new player
s - Search for a player by code
u - Update a player's information
p - Print all player details
d - Delete a player

How to Use 💡

Start the Program: When you run the program, you will be greeted with the main menu. Here, you can choose to manage teams or players or access help.

Team and Player Commands:

For teams, you can insert new teams, search for existing teams, update team information, print team details, and delete teams.
For players, similar commands are available to manage player information.
Helpful Feedback: The program provides user-friendly prompts to guide you through each operation, ensuring smooth management of team and player databases.

🛠️ Technology Used

C Programming: Used for building the database system and implementing all functions.
Modular Design: Functions for handling team and player operations are separated into different files for clarity and better maintenance.

📂 Project Structure

worldCupDB.h: Header file containing function prototypes for managing the team and player operations.
worldCupTeam.c: Contains functions for team management (insert, update, search, delete, print).
worldCupPlayer.c: Contains functions for player management (insert, update, search, delete, print).
main.c: Main program with the interactive menu and user inputs.
