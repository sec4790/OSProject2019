# OSProject2019

Contributors: Muhammad Ghazi, Brittany Thibodeaux, Sarah Baker

This is the readmefile for the Operating Systems project.

Objective: Create a mini-shell.

Purpose: Understand OS processes.

We want the program to display a writing prompt for a user to input commands and parameters.

When the user inputs commands with parameters, our shell will read the command from the command line, and then parse the command. 

Then the shell will open the file that contains the set of commands by looking up the path and parsing the path.

For every command that is given by the user, the shell will
-- read a command from the file
-- parse the command
-- create a new process to execute the command

After the commands are completed, the process will terminate gracefully.