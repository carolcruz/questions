struct Node {
	int data;
	Node *right;
	Node *left;
}

int findMax(Node *root){
	if (root == NULL)
		return -1;
	else{
		while(root!=NULL){
			root = root->right;
		}
		return root->data;
	}
}

int findMin(Node *root){
	if(root = NULL)
		return -1;
	else{
		while(root!=NULL){
			root = root->left;
		}
		return root->data;
	}
}

bool checkBST(Node *root){
	if(root == NULL) //it's a BTS
		return true;
	else if(root->data < findMin(root->left)) // is not a BTS
		return false;
	else if(root->data > findMax(root->right)) // is not a BTS
		return false;
	else return true; //passing all these, it's a BTS
}
