#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES  1024
#define true 1
#define false 0


typedef struct linList {
	
	char* uname;
	int uid;
	struct linList* next;	
} linList;

typedef struct list {
	linList *head;
	linList *current;
}list;
/*
Creates an linked list with use of
memory allocation and returns a new empty list.
*/
linList* createLinList(int val, char* usrname);

/*
Inserts elements into list while sorting them to
the existing list using insertion sort.
*/
linList *insertElementToList(int val, char* usrname, linList *l, list *t);
/*
Prints the data inside the list by
traversing the list.
*/
void printList(linList *l,list *t);


/*
Gets the length of the list.
Returns an integer.
*/
int getListLen(linList *l);
/*
Frees the complete linked list
*/
void freelList(linList * l, list *t);
