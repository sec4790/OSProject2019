/**This is the source code for COSC 4302 Summer 2019
Contributors: Sarah Baker, Brittany Thibodeaux, and Muhammad Ghazi

Design and implement a simple, interactive shell program that prompts the user for a command,
parses the command and then executes it with a child process. 

*/

/**Directives*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



//defs
#define LINE_LEN 80;
#define MAX_ARGS 64
#define MAX_ARG_LENGTH	16;
#define MAX_PATHS	64;
#define MAX_PATH_LEN 96;
#define WHITESPACE " .,\t\n"

#ifndef NULL
#define NULL
#endif

/**
The C data structure used to save arguments
*/
struct command_t{
	char *name;
	int argc;
	char *argv[MAX_ARGS];
};

char *lookupPath(char **, char **);
int parseCommand(char *, struct command_t);
int parsePath(char **);
void printPrompt();
void readCommand(char *);

/**
Build the prompt string to have the machine name,
current directory, or other desired information
*/
void printPrompt(){
	char *promptString = "Simple Shell";
	printf("%s", promptString);
}

/**T
his code uses any set of I/O functions, such as those in the stdio library to read the entire command line into 
the buffer. This implememntation is greatly simplified, but it does the job}*/
void readCommand(char *buff){
	
	gets(buff);
}

/**
Determine command name and construct the parameter list. This funciton
will build argv[] and set the argc value. argc is the number of "tokens" or words
on the command line argv[] is an array of strings (pointers to char*). The last element in 
argv[] must be NULL. As we scan the command line from the left, the firs ttoken
goes in argv[0], the second in argv[1], and so on. Each time we add a token to 
argv[], we increment argc.
*/
int parseCommand(char *cLine, struct command_t *cmd){
	int argc;
	char **clPtr;
	/**Initialization*/
	clPtr = &cLine; //cLine is the command line
	argc = 0;
	cmd->argv[argc] = (char *) malloc(MAX_ARG_LEN);
	/**Fill argv[]*/
	while((cmd->argv[argc] = strsep(clPtr, WHITESPACE)) != NULL) {
		cmd->argv[++argc] = (char *) malloc(MAX_ARG_LEN); //increment
	}
	/**set the command name and argc*/
	cmd->argc = argc-1;
	cmd->name = (char *) malloc(sizeof(cmd->argv[0]));
	strcpy(cmd->name, cmd->argv[0]);
	return 1;
}


/*
This funciton searches the directories identified ;by the dir
argument to see if argv[0] (the file name) appears there. Allocate a new string,
place the full path name in it, then return the string
*/
char *lookupPath(char **argv, char **dir){
	
	char *result;
	char pName[MAX_PATH_LEN];

	//check to see if file name is already an absolute path name
	//we need to add stuff in here
	if(*argv[0] == '/'){
		return argv[0];
	}//look in PATH directories.
	//Use access() to see if the file is in a dir
	for(i = 0; i < MAX_PATHS; i++){
		... //we need to add stuff in here
	}
	
	//FILE NAME NOT FOUND
	fprintf(stderr, "%s: command not found\n", argv[0]);
	return NULL;
}

/**
This function reads the PATH variable for this environment, then
builds an array, dirs[], of the directores in PATH
*/
int parsePath(char *dirs[]){

	char *pathEnvVar;
	char *thePath;
	
	for(i = 0; i < MAX_ARGS; i++){
		dirs[i] = NULL;
	}
	pathEnvVar = (char *) getenv("PATH");
	thePath = (char *) malloc(strlen(pathEnvVar) + 1);
	strcpy(thePath, pathEnvVar);
	
	/**Lop to parse thePath. Look for a ':' delimiter between
	each path name*/
	//we need to add the loop here
}


/**
This function creates a child process and
executes the command
*/
void executeCommand(char *name, char **argc){
	
	/**Create child and execute command*/
	int child_PID;
	
	if((childPID = fork() == 0){
		execv();//something should probably go in there.
		exit(0);
	}
	else if((childPID = fork() < 0)){
		printf("error with fork\n\n");
		exit(1);
		
	}
	/**ELSE Wait for child to terminate*/
	//code here
}


int main(){
	/**Initialize variables*/
	char *pathv[MAX_PATHS];
	char cLine[LINE_LEN];
	struct command_t command;
	//blah blah here
	
	/**Get directory paths from PATH*/
	parsePath(pathv);
	while(TRUE){
		printPrompt();
	
		/**read command line and parse it*/
		readCommand(cLine);
		parseCommand(commanLine, &command);
		
		/**strcmp compares strings. if the command is "exit" then exit*/
		if(strcmp(command.name, "exit") == 0){
			exit(0)
		}
	
		/**Get the full pathname for the file*/
		command.name = lookupPath(command.argv, pathv);
		if(command.name == NULL){
			/**Report error*/
			fprintf(stderr, "Command not known");
			continue;
	}
	
	//Execute command here
	executeCommand(command.name, command.argv)//add some params
	}
	
	

	return 1;
	
}


