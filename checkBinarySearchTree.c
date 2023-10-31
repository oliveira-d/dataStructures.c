#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Binary Tree Implementation
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

int isTreeEmpty(Node* root) {
	if (root == NULL) return 1;
	return 0;
}

Node* Insert(int x,Node** pRoot) {
		if (*pRoot == NULL) {
			(*pRoot) = (Node*)malloc(sizeof(Node));
			(*pRoot)->data = x;
			(*pRoot)->left = NULL;
			(*pRoot)->right = NULL;
		} else if (x <= (*pRoot)->data) {
			(*pRoot)->left = Insert(x,&(*pRoot)->left);
		} else {
			(*pRoot)->right = Insert(x,&(*pRoot)->right);
		}
		return *pRoot;
}

// check if binary treee is search type

bool isSubtreeLesser(Node* root, int x) { // checks if all the elements in the subtree are less then root->data, logic is a bit like depth-first traversal
	if(root == NULL) return true;
	if (root->data <= x 
		&& isSubtreeLesser(root->left,x)
		&& isSubtreeLesser(root->right,x)) return true; //linha necessária para checar o nó neto contra o avô 
	else return false;
}

bool isSubtreeGreater(Node* root, int x) {
	if(root == NULL) return true;
	if (root->data > x 
		&& isSubtreeGreater(root->left,x)
		&& isSubtreeGreater(root->right,x)) return true;
	else return false;
}

bool isBinarySearchTree(Node* root) {
	if (root == NULL) return true;
	
	if(isSubtreeLesser(root->left,root->data) 
		&& isSubtreeGreater(root->right,root->data) 
		&& isBinarySearchTree(root->left) 
		&& isBinarySearchTree(root->right)) return true;
	else return false;
}

// check if binary treee is search type (2) - não está boa

bool isBinarySearchTreeUtil(Node* root, int minValue, int maxValue) {
	if (root == NULL) return true;
	
	if(root->data <= maxValue
		&& root->data > minValue
		&& isBinarySearchTreeUtil(root->left,minValue,root->data) 
		&& isBinarySearchTreeUtil(root->right,root->data,maxValue)) return true;
	else return false;
}

bool isBinarySearchTree1(Node* root) {
	return isBinarySearchTreeUtil(root,INT_MIN,INT_MAX); // INT_MAX and INT_MIN require <limits.h>
}

int main() {
	
	Node* root=NULL;
	
	Insert(15,&root);
	Insert(10,&root);
	Insert(20,&root);
	Insert(8,&root);
	Insert(12,&root);
	Insert(17,&root);
	Insert(25,&root);
	Insert(7,&root);
	Insert(6,&root);
	//Insert(8,&root);
	
	//printf("Root - Left - Right: \n"); PreOrder(root); printf("\n");
	//printf("Left -Root - Right: \n"); InOrder(root); printf("\n");
	//printf("Left - Right - Root: \n"); PostOrder(root); printf("\n");
	
	//printf("Breadth-first:\n"); LevelOrder(root);
	if (isBinarySearchTree1(root)) printf("É\n");
	else printf("Num é\n");
	
	printf("%d -> ",((root->left)->right)->data);
	((root->left)->right)->data = 15;
	printf("%d\n",((root->left)->right)->data);
	
	if (isBinarySearchTree1(root)) printf("É\n");
	else printf("Num é\n");
	
	return 0;	
}




