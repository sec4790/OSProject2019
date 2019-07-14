/**This is the source code. Insert skeleton here*/
//the include stuff
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
#define NULL ...
#endif

//pg 81
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

//writing prompt
//pg 79
void printPrompt(){
	promptString = ...; //make something up here
	printf("%s", promptString);
}

//read command
// p 79
//we will probably need to change this
void readCommand(char *buff){
	/**This code uses any set o fI/O functions, such as those in the stdio library to read the entire command line into 
the buffer. This implememntation is greatly simplified, but it does the job}*/
	gets(buff);
}

//parse command
// p 63
int parseCommand(char *cLine, struct command_t *cmd){
	int argc;
	char **clPtr;
	/**Initialization*/
	clPtr = &cLine; //cLine is the command line
	argc = 0;
	cmd->argv[argc] = (char *) malloc(MAX_ARG_LEN);
	/**Fill argv[]*/
	while((cmd->argv[argc] = strsep(clPtr, WHITESPACE)) != NULL) {
		cmd->argv[++argc] = (char *) malloc(MAX_ARG_LEN);
	}
	/**set the command name and argc*/
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
		...
	}//look in PATH directories.
	//Use access() to see if the file is in a dir
	for(i = 0; i < MAX_PATHS; i++){
		... //we need to add stuff in here
	}
	
	//FILE NAME NOT FOUND
	fprintf(stderr, "%s: command not found\n", argv[0]);
	return NULL;
}

//parse path
//p 80
int parsePath(char *dirs[]){
	/**This function reads the PATH variable for this environment, then
	builds an array, dirs[], of the directores in PATH*/
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


//execute
void executeCommand(char *name, char **argc){
	
	/**Create child and execute command*/
	
	/**Terminate child process*/
}

//main method
int main(){
	/**Initialize variables*/
	//init
	//init
	//blah blah here
	
	/**Get directory paths from PATH*/
	parsePath(pathv);
	while(TRUE){
		printPrompt();
	
	/**read command line and parse it*/
	readCommand(cLine);
	parseCommand(commanLine, &command);
	}
	
	/**Get the full pathname for the file*/
	command.name = lookupPath(command.argv, pathv);
	if(command.name == NULL){
		/**Report error*/
		continue;
	}
	
	//Execute command here
	executeCommand()//add some params

	
}


