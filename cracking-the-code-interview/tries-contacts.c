#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct node
{
	struct node *children[ALPHABET_SIZE];
	bool isEndOfWord;
	int count;

}trieNode;

trieNode *getNode(){ //creat a new trie node
//each node is represented by an array of pointers size 26 (the alphabeth)

	trieNode *newNode = (trieNode *)malloc(sizeof(trieNode));

	if(newNode){
		int i;
		newNode->isEndOfWord = false;
		newNode->count = 0;
		for(i=0; i<ALPHABET_SIZE; i++){
			newNode->children[i] = NULL; //when a new node is created, all the pointers of this array are NULL
		}
	}
	return newNode;
}

void insert(trieNode *root, const char *key){

	int level;
	int length = strlen(key);
	int index;

	trieNode *node = NULL;
	node = root;

	for(level=0; level<length; level++){
		index = CHAR_TO_INDEX(key[level]);
         if(!node->children[index])
            node->children[index] = getNode();
		node = node->children[index]; 
		node->count = node->count+1;
	}
    if (level == length-1)
    {
       node->isEndOfWord = true;
    }
}

int find(trieNode *root, const char *key){
	
	int level;
	int length = strlen(key);
	int index;

	trieNode *node = NULL;
	node = root;

	for(level=0; level<length; level++){
		index = CHAR_TO_INDEX(key[level]);
		if(!node->children[index])
			return 0;
		node = node->children[index];
	}

	if(node == NULL) return 0;

	return node->count;
}

int main()
{
	trieNode *root = NULL;
	root = getNode();

	char op1[] = {"add"};
	char op2[] = {"find"};
	int n, i, operation, word, c=0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		c=0;
		char* operation = (char *)malloc(512000 * sizeof(char));
        char* word = (char *)malloc(512000 * sizeof(char));
        scanf("%s %s", operation, word);
        if(strcmp(operation, op1) == 0)
        	insert(root, word);
        if(strcmp(operation, op2) == 0){
            c = find(root, word);
        	printf("%d\n", c);
        }
        free(operation);
		free(word);
	}

	return 0;
}