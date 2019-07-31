/* 
COSC 4302
Group Project
Sarah Baker, Muhammad Ghazi, Brittany Thibodeaux
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define variables
#define LINE_LEN 	80;
#define MAX_ARGS 	64
#define MAX_ARG_LENGTH	16;
#define MAX_PATHS	64;
#define MAX_PATH_LEN 	96;
#define WHITESPACE 	" .,\t\n"

#ifndef NULL
#define NULL ...
#endif

//pg 81
struct command_t{
	char *name;
	int argc;
	char *argv[MAX_ARGS];
};

// Function prototypes
char *lookupPath(char **, char **);
int parseCommand(char *, struct command_t);
int parsePath(char **);
void printPrompt();
void readCommand(char *);

int main(){
	// Shell Initialization
	char commandLine[LINE_LEN];
	struct command_t command;
	// TODO finish listing variables
	
	// TODO figure out pathv variable initialization
	parsePath(pathv); // Get directory paths from PATH
	
	while(TRUE){
		printPrompt();
	
		// Read command line and parse
		readCommand(commandLine);
		parseCommand(commandLine, &command);
	}
	
	// Get full pathname for the file
	command.name = lookupPath(command.argv, pathv);
	if(command.name == NULL){
		// Report error
		fprintf(stderr, "Command not known");
		continue;
	}
	
	else {
		// Execute command 
		executeCommand() // Add some params
	}

	// Shell termination
	return 0;
	
}

int parsePath(char *dirs[]){
	// Read the PATH variable for the environment then build dirs[], an array of
	// directories in PATH
	
	char *pathEnvVar;
	char *thePath;
	
	for(int i = 0; i < MAX_ARGS; i++){
		dirs[i] = NULL;
	}
	pathEnvVar = (char *) getenv("PATH");
	thePath = (char *) malloc(strlen(pathEnvVar) + 1);
	strcpy(thePath, pathEnvVar);
	
	/**Lop to parse thePath. Look for a ':' delimiter between
	each path name*/
	while(int i = 0; i < MAX_ARGS; i++) {
		dirs[i] = strsep(thePath, ":");
	} // TODO Verify this solution
}

void printPrompt(){
	char *promptString = "% ";
	printf("%s", promptString);
}

void readCommand(char *buff){
	// Read entire command line into the buffer
	// TODO get buffer
}

int parseCommand(char *cLine, struct command_t *cmd){
	int argc;
	char **clPtr;
	
	// Initialize
	clPtr = &cLine; 	//cLine is the command line
	argc = 0;
	cmd->argv[argc] = (char *) malloc(MAX_ARG_LEN);
	
	// Fill argv[]
	while((cmd->argv[argc] = strsep(clPtr, WHITESPACE)) != NULL) {
		cmd->argv[++argc] = (char *) malloc(MAX_ARG_LEN);
	}
	// Set command name and argc
	cmd->argc = argc-1;
	cmd->name = (char *) malloc(sizeof(cmd->argv[0]));
	strcpy(cmd->name, cmd->argv[0]);
	return 1;
}


//look up path
//p 81
char *lookupPath(char **argv, char **dir){
	/*This funciton searches the directories identified ;by the dir
argument to see if argv[0] (the file name) appears there. Allocate a new string,
	place the full path name in it, then return the string*/
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




//execute
void executeCommand(char *name, char **argc){
	
	/**Create child and execute command*/
	int child_PID 0;
	
	if((childPID = fork()){
		execv();//something should probably go in there.
		exit(0);
	}
	else {
		//do something else
	}
	/**Terminate child process*/
}




