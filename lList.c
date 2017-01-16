#include "lList.h"

/*
Creates an linked list by allocating
memory for the list and returning a new empty list.
*/
linList* createLinList(int val, char* usrname){
	int len;
	linList *lList;
  
	lList = (linList*)malloc(sizeof(linList));
	if(lList == NULL){
	
		printf("Something went wrong with memmory allocation.\n");	
		return 0;
	}
	
	lList->uid = val;
	len = strlen(usrname) + 1;
	lList->uname = calloc(1,len*sizeof(char));	

	if(lList->uname == NULL){
		printf("Something went wrong with memmory allocation.\n");	
		
	}
	strcpy(lList->uname, usrname);
	
	lList->next = NULL;
	return lList;

}

/*
Uses the existing list to add a value into the last spot.
After the value is added the old value pointer is deleted
and new mem allocation is used to create the
new next part of the linked list.
*/
linList *insertElementToList(int val, char* usrname , linList *l,list *t){
	int c = 0;
	if(l == NULL ){
		
		l = createLinList(val,usrname);
		return l;
	}
	else{
		t->head = l;
		t->current = l;
		while(l->next != NULL){
			
			if(t->current->uid > val){
				t->current = l;
				break;
			}
			else{
				t->current = t->current->next;
				c++;
			}
				l = l->next;
		}

		linList *new_List;
		new_List = createLinList(val,usrname);
		
		if(t->current->uid < new_List->uid){
			t->current->next = new_List;
		
			return t->head;
		}else if(t->head->uid > new_List->uid ){

			new_List->next = t->head;
			return new_List;

		}else if(c >= 0) {
			switch(c){
				case 0:
					new_List->next = t->current;
					t->head = new_List;
					return t->head;
				break;
				
				case 1:
					new_List->next = t->current;
					t->head->next = new_List;
					return t->head;
				default:
					new_List->next = t->current;
					l= t->head;
					for(int i = 1; i < c; i++){
			
						l= l->next;
					}
					l->next = new_List;			
			}	
		}
	}
	return t->head;
}

void printList(linList *l, list *t){
	
	t->head = l;
	t->current = l;
	for(int i = 0; i < getListLen(l); i++){

		printf("%d:%s\n",t->current->uid,t->current->uname);
		t->current = t->current->next;
	}
}

int getListLen(linList *l){

	int iterations = 1;
	while(l->next != NULL){
	
		iterations++;
		l = l->next;
	}
	return iterations;
}
void freelList(linList * l, list *t){
	
	l = t->head;
	while(l->next != NULL){
		t->head = t->head->next;	
		t->current = l;	
		free(t->current->uname);
		free(t->current);
		l = t->head;
	}
	t->current = l;
	free(t->current->uname);
	free(t->current);
}
