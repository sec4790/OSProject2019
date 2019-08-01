
/* 
COSC 4302
Group Project
Sarah Baker, Muhammad Ghazi, Brittany Thibodeaux
 */

/**Directives*/

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

// Function prototypes
char *lookupPath(char **, char **);
int parseCommand(char *, struct command_t);
int parsePath(char **);
void printPrompt();
void readCommand(char *);


int main(){
	// Shell initialization
    char commandLine[LINE_LEN];
    struct command_t command;
    char *pathv[MAX_PATH_LEN] = getenv("PATH");
    int i;
    // List any remaining variables

    // Get directory paths from PATH
    parsePath(pathv); 

    while(TRUE) {
        printPrompt();

        // Read command line and parse
        readCommand(commandLine);
        parseCommand(commandLine, &command);

        // Get full pathname for the file
        command.name = lookUpPath(command.argv, pathv);
        if(command.name == NULL) {
            // Report error
            continue;
        }

        // Create child and execute command
 
	if((childPID = fork())==0) {
		execv(command.name, command.argv);
		printf("Unknown command\n");
		exit(0);
            }
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


/**
Build the prompt string to have the machine name,
current directory, or other desired information
*/

void printPrompt(){
	char *promptString = "% ";
	printf("%s", promptString);
}


void readCommand(char *buffer) {
    // Read entire command line into the buffer
    fgets(commandLine, LINE_LEN, stdin);
}

// TODO Verify that this function works in this shell as well
int parseCommand(char *cLine, struct command_t *cmd) {
    int argc;
    char **clPtr;

    // Initialize
    clPtr = &cLine;     // cLine is command line
    argc = 0;
    cmd->argv[argc] = (char *)malloc(MAX_ARG_LEN);

    // Fill argv[] 
    while((cmd->argv[argc] = strsep(clPtr, WHITESPACE)) != NULL) {
        cmd->argv[++argc] = (char *)malloc(MAX_ARG_LEN);
    }

    // Set command name and argc
    cmd->argc = argc - 1;
    cmd->name = (char *)malloc(sizeof(cmd->argv[0]));
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
	char *tempDir = (char *)malloc ( MAX_PATH_LEN);

	//check to see if file name is already an absolute path name
	if(*argv[0] == '/'){
		return argv[0];
	}//look in PATH directories.
	//Use access() to see if the file is in a dir
	for(i = 0; i < MAX_PATHS; i++){
		if(dirs[i] == NULL)
			continue;
		
		strcpy(tempDir,dirs[i]);
		strncat(tempDir,"/",1);
		strncat(tempDir,argv[0],strlen(argv[0]));
		
		if(access(tempDir, F_OK) == 0) {
			return tempDir;
		}
	}
	
	//FILE NAME NOT FOUND
	fprintf(stderr, "%s: command not found\n", argv[0]);
	return NULL;
}



}


