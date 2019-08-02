# COSC4302 Operating Systems Group Project Summer 2019

Instructor: Dr. Sun

This is the README file for said project

Project members are as follows:
-Sarah Baker
-Muhammad Ghazi
-Brittany Thibodeaux

Project Description:
As assigned, our project is to implement Lab Exercise 2.1, page 76 from our TextBook, Operating Systems by Gary Nutt.
The full assignment question is as follows:	
"Starting with the code in Section 2.4, design and implement a simple, interactive shell program
that prompts the user for a command, parses the command, and then executes it with
a child process. In your solution you are req uired to usc execv ( ) instead of execv p ( ) ,
which means that you will have to read the PATH environment variable, then search each
directory in the PATH for the command file name that appears on the command line."

Objective & Purpose: 
-Understand OS processes by:
--Creating a simple minishell that is interactive and able to process input/instructions
--Understanding how a command line shell works.
--Understanding the commands fork, read, execv and wait.
--Utilizing child processes to complete tasks/instructions
--Feel comfortable compiling simple C++/C programs 

Getting Started:
-Required Linux based enviroment needed, with a compatible compiler such as G++ & Gcc installed.
-If you need to modify the source code, NotePad++ is recommended as a freesource text editor that is available in Linux 

Prerequisites:
-PC Hardware that is either capable of running a Linux distro natively or can host a Linux VM on its native OS. If using the latter, VirtualBox is recommended

Deployment & Production:
-We want the program to display a writing prompt for a user to input commands and parameters.
-When the user inputs commands with parameters, our shell will read the command from the command line, and then parse the command using a child process. 
-Then the shell will open the file that contains the set of commands by looking up the path and parsing the path.
-For every command that is given by the user, the shell will:
--Read a command from the file
--Parse the command
--Create a new process to execute the command

After the commands are completed, the process will terminate

Organized With Private GitHub Repository

Versioning:
N/A

Authors:
-Sarah Baker
-Muhammad Ghazi
-Brittany Thibodeaux
See also the list of project members who participated in this project.

License
This project is licensed under the MIT License - see the LICENSE.md file for details
