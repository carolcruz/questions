#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	int info;
	struct No* prev;
	struct No* next;
}node;

node *beg=NULL, *end=NULL;

void add(int newinfo){

	if(beg==NULL){
		beg = (node*)malloc(sizeof(node));
		beg->info = newinfo;
		beg->prev = beg;
		beg->next = beg;
		end = beg;
	}
	else{
		node *newNode = (node*)malloc(sizeof(node));
		newNode->info = newinfo;
		newNode->next = beg;
		beg->prev = newNode;
		newNode->prev = end;
		end->next = newNode;
		end = newNode;
	}
}

void print(){
	node *aux=NULL;
	aux = beg;
	do{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	while(aux!=beg);
}
void move(int rotations){
	node *aux=NULL;
	aux = beg;
	int i;
	for(i=0; i<rotations; i++){
		aux = aux->next;
		beg = aux;
		end = aux->prev;
	}
	print();
}

int main(){
	int i=0, nodes, rotations, n;
	scanf("%d %d", &nodes, &rotations);
	while(i<nodes){
		scanf("%d", &n);
		add(n);
		i++;
	}
	move(rotations);
	return 0;
}