#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleList{
	int info;
	struct DoubleList *previous;
	struct DoubleList *next;
}doublelist;

doublelist *beg=NULL, *end=NULL; //pointers that points the beginning and the end of the double linked list


//add is a function that inserts newNode elements on the double linked list
void add(int n){ //receive a integer that will be added to the list
	if(beg==NULL){
		doublelist *newNode = (doublelist*)malloc(sizeof(doublelist));
		newNode->info = n;
		newNode->next = newNode;
		newNode->previous = newNode;
		beg = newNode;
		end = newNode;
	}else{
		doublelist *newNode = (doublelist*)malloc(sizeof(doublelist));
		newNode->info = n;
		end->next = newNode;
		newNode->previous = end;
		end = newNode;
		newNode->next = beg;
		beg->previous = newNode;
	}
}
void print(doublelist *ini){ //print the entire double linked list starting with the element that was passed as parameter
	doublelist *aux=NULL;
	aux = ini->next;
	printf("%d ", ini->info);
		while(aux!=ini){
			printf("%d ", aux->info);
			aux = aux->next; //right here we update the value, coming to the next element
		}
		printf("\n");
}
void move(char m, int n, doublelist *aux){ //receive as parameters a char that will be the direction (left or right) of the movement, and a integer that indicates how many movementes the program has to execute
	//doublelist *aux;
	//aux = beg; //start with the first element of the list
	int i=0;
	if(m=='D'){ //if RIGTH
		aux = beg;
		for(i=0; i<n; i++){
			aux = aux->previous;
			beg = aux; //here we update the beginning, because the roulette was moved
			end = aux->previous; //this is a circular list, so the end will always be the beginning previous

		}
		print(beg);
	}else if(m=='E'){ //if LEFT
		aux = beg;
		for(i=0; i<n; i++){
			aux = aux->next;
			beg = aux; //same here
			end = aux->previous; //same here
		}
		print(beg);
	}
	
	//return beg;
}

int main(){
	int n=0, qnt=0, i=0, elem=0;
	char m ='\0';
	doublelist *aux=NULL;
	scanf("%d", &qnt);
	while(i<qnt){ //add the elements in the list
		scanf("%d", &elem);
		add(elem);
		i++;
	}
	//aux = beg;
	do{
		scanf("%c %d", &m, &n);
		if(m!='S'){
			move(m, n, aux);
        		//print(aux); 
		}	
	}while(m!='S');

	return 0;
}

