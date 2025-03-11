🏆 World Cup Database 🌍

✨ Overview

Welcome to the World Cup Database! This program is designed to store and manage information about teams (nations) participating in the World Cup. It allows users to add, update, search, and remove teams from the database.

The application is structured to handle up to 31 teams, supporting operations like adding a team, updating team details, searching for a team, and printing the list of teams with their respective information.

🛠 Features

Add a Team 📝

Add a team by providing a team code, name, seeding, and kit color.
Ensure no duplicate teams are added based on team code or name.
Update a Team ✏️

Modify an existing team's details, including name, seeding, and color.
Search for a Team 🔍

Search for a team by its code and view its details.
Print All Teams 📜

View a list of all teams with their details, such as team code, name, seeding, and primary kit color.

📂 Code Structure

The code defines a team structure to store each team's data:

code: Team code (integer between 0 and 31)
teamName: Name of the team (string)
seeding: Group seeding (2-character array: letter and number)
colour: Primary kit color (string)
The main operations available in the program are:

i: Insert a new team into the database.
p: Print all stored teams.
u: Update an existing team’s details.
s: Search for a team by its code.
q: Quit the program.
🖥 Technologies Used
C Programming Language 🖥️
The program is written in C, leveraging core language features such as structures, arrays, and file handling.

String Handling 📚

Utilizes string.h for operations like string comparison, copying, and reading input.

🎯 Key Functions

Insert a Team
Checks: Team code, name, seeding, and color must be unique and valid.
Prompts: User provides team code, name, group seeding (A-H, 1-4), and primary kit color (R, O, Y, G, B, I, V).
Search for a Team
Search: Look up a team by its code and display its details.
Update a Team
Modify: Change a team's name, seeding, and color.
Print All Teams
Display: List all the teams currently in the database with their codes, names, seedings, and kit colors.

🔧 Additional Notes

Validation: Each operation (insert, update, etc.) ensures that inputs like team codes, names, seedings, and colors are valid.
Edge Cases: Handles cases like invalid team codes, duplicate entries, and incorrect seedings or colors.
