#include "lList.h"

/*
This function will read a file into a linked list
and return it to the function call.
*/

linList *readFilefunc(int argc, char *argv[],linList *head, list *t);

int main(int argc, char* argv[]){ 
	
	printf("Initializing main\n");
	linList *root;
	root = NULL;
	list *tracker;
	tracker = malloc(sizeof(list));
	root = readFilefunc(argc,argv,root,tracker);
	
	printList(root,tracker);
	freelList(root,tracker);
	free(tracker);
	return 0;
}

linList * readFilefunc(int argc, char *argv[],linList *head, list *t){
	FILE *fp;
	if(argc < 2){
		printf("No file used for program\n");
		printf("Using stdin, as file stream instead\n");
		fp = stdin;

	}
	else{
		fp = fopen(argv[1], "r");
	}

	char *outp = calloc(1,MAXLINES*sizeof(char));
	char *tmp = calloc(1,MAXLINES*sizeof(char));
	int index = 0;
	int counter = 0;
	int uid;
	int len;
	int entered = 4;

	if( fp == NULL ){

		printf("file pointer is null, something went wrong.\n");
		free(outp);
		free(tmp);
		exit(-1);
	}
	
	
	while((outp[index]  = getc(fp)) != EOF){
	
		if(outp[index] == '\n'){
			if(tmp == NULL || uid == -1 || counter != 6){

				printf("Incorrect line, throwing it away..\n");
				index = -1;
				counter = 0;
				free(outp);
				free(tmp);
				outp = calloc(1,MAXLINES*sizeof(char));
				tmp = calloc(1,MAXLINES*sizeof(char));							
			}
		}
		if(outp[index] == ':'){
			entered = false;
			counter++;
				
		}
		
		/*
			this if statement is used
			to controll the bounds of the copying of 
			uname and uid.
			will not enter the switch case unless a new : 
			has been found. for each new line from the file stream
			we will only do  each case once.
		*/
		if(entered == false){

			switch(counter){
			
				case 1:
					
					len = strlen(outp);
					outp[len-1] = '\0';
					strcpy(tmp, outp);
					free(outp);
					outp = calloc(1,MAXLINES*sizeof(char));
					entered = true;
					index = -1;
				break;
				case 2:
				
					free(outp);
					outp = calloc(1,MAXLINES*sizeof(char));
					entered = true;
					index = -1;
				break;
				case 3:
				
					if(strlen(outp) == 0){
						free(outp);
						outp = calloc(1,MAXLINES*sizeof(char));
						uid = -1;
					}
					else{
					
						uid = atoi(outp);
						free(outp);
						outp = calloc(1,MAXLINES*sizeof(char));
						entered = true;		
					}
				
				break;
				//if in case 6 line has almosted ended
				//checking if current position is at end of line.
				case 6:
				
					if(outp[index] == '\n'){

						if(tmp != NULL || uid != 0){

							head = insertElementToList(uid,tmp,head,t);
							free(outp);
							free(tmp);
							outp = calloc(1,MAXLINES*sizeof(char));
							tmp = calloc(1,MAXLINES*sizeof(char));
							index = -1; 
							counter = 0;
						}
					}
			}
		}
		index++;
	}		
	fclose(fp);
	free(tmp);
	free(outp);
	return head;
}




















