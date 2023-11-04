#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinarySearchTree.h"

// Binary Search Tree implementation
/*
typedef struct bNode {
	int data;
	struct bNode* left;
	struct bNode* right;
} bNode;

bool isTreeEmpty(bNode* p_root) {
	if (p_root == NULL) return true;
	return false;
}

int treeHeight(bNode* p_root) {
	if (p_root == NULL) return -1;
	
	int leftHeight = treeHeight(p_root->left);
	int rightHeight = treeHeight(p_root->right);
	
	if (leftHeight > rightHeight) return leftHeight + 1;
	else return rightHeight + 1;
}

// start circular array based queue implementation (dependency for LevelOrder() function in BST implementation)

#define n 20

typedef struct Queue {
	bNode* array[n];
	int front, rear;
} Queue;

Queue startQueue() {
	Queue Q;
	Q.front=-1;
	Q.rear=-1;
	return Q;
}

bool isQueueEmpty(Queue* queue) {
	if (queue->front == -1) return true;
	return false;
}

bool isQueueFull(Queue* queue) {
	if ((queue->rear+1)%n != queue->front) return false;
	return true;
}

void enqueue(bNode* x,Queue* queue) {
	if (isQueueEmpty(queue)) {
		queue->array[++queue->front]=x;
		queue->rear++;
	} else if (isQueueFull(queue)) {
		printf("NO CAN DO!\n");
		return;
	} else { // não está cheia nem vazia
		queue->rear=(queue->rear+1)%n;
		queue->array[queue->rear]=x;
	}
}


void throwError() {
	printf("ERRO!\n");
}

bNode* dequeue(Queue* queue) {
	bNode* pop = NULL;
	if (isQueueEmpty(queue)) {
		throwError();
		pop = NULL;
	} else if (queue->front == queue->rear){ //quando houver apenas um elemento: acontece sempre que a lista é esvaziada, independente do quão cheia, então nem sempre queue->front=n-1
		pop = queue->array[queue->front];
		queue->front=-1;
		queue->rear=-1;
	} else {
		pop = queue->array[queue->front];
		queue->front=(queue->front+1)%n;
	}
	return pop;
}

// end of queue implementation

// Search

bNode* treeMin(bNode* p_root) {
	if (isTreeEmpty(p_root)) {
		printf("Error: tree is empty!");
		return NULL;
	} else if (p_root->left == NULL) {
		return p_root;
	} else return treeMin(p_root->left);
}

bNode* treeMax(bNode* p_root) {
	if (isTreeEmpty(p_root)) {
		printf("Error: tree is empty!");
		return NULL;
	} else if (p_root->right == NULL) {
		return p_root;
	} else return treeMin(p_root->right);
}

bool treeHas(int x,bNode* p_root) {
	if (p_root == NULL) return false;
	else if (x == p_root->data) return true;
	else if (x < p_root->data) return treeHas(x,p_root->left);
	else return treeHas(x,p_root->right);
}

// insertion with Recursion
bNode* insertTreeR(int x, bNode** p_p_root) {
		if (*p_p_root == NULL) {
			(*p_p_root) = (bNode*)malloc(sizeof(bNode));
			(*p_p_root)->data = x;
			(*p_p_root)->left = NULL;
			(*p_p_root)->right = NULL;
		} else if (x <= (*p_p_root)->data) {
			(*p_p_root)->left = insertTreeR(x,&(*p_p_root)->left);
		} else {
			(*p_p_root)->right = insertTreeR(x,&(*p_p_root)->right);
		}
		return *p_p_root;
}

// insertion with While Loop
void insertTreeL(int x, bNode** p_p_root) {
	
	bNode* var = (bNode*)malloc(sizeof(bNode));
	var->left = NULL;
	var->right = NULL;
	var->data = x;
	
	if (*p_p_root == NULL) {
		*p_p_root = var;
		return;
	}
	
	bNode* temp = *p_p_root;
	
	while(temp->left != var && temp->right != var) {
		
		if (x <= temp->data && temp->left == NULL) {
			temp->left = var;
		} else if (x > temp->data && temp->right == NULL) {
			temp->right = var;
		} else if (x <= temp->data) temp = temp->left;
		else temp = temp->right;
	}
}

bNode* deleteTree(int x, bNode** p_p_root) {
	if (*p_p_root == NULL) return NULL;
	else if (x < (*p_p_root)->data) (*p_p_root)->left = deleteTree(x,&(*p_p_root)->left);
	else if (x > (*p_p_root)->data) (*p_p_root)->right = deleteTree(x,&(*p_p_root)->right);
	else {
		if ((*p_p_root)->left == NULL && (*p_p_root)->right == NULL) {
			free(*p_p_root);
			*p_p_root = NULL;
		} else if ((*p_p_root)->left == NULL) {
			bNode* temp = (*p_p_root);
			*p_p_root = (*p_p_root)->right;
			free(temp);
		} else if ((*p_p_root)->right == NULL) {
			bNode* temp = (*p_p_root);
			*p_p_root = (*p_p_root)->left;
			free(temp);
		} else {
			bNode* temp = treeMin((*p_p_root)->right);
			(*p_p_root)->data = temp->data;
			(*p_p_root)->right = deleteTree(temp->data,&(*p_p_root)->right);
		}
	}
	return *p_p_root;
}

// Depth-first traversal: 
void PreOrder(bNode* p_root){
	if(p_root != NULL) {
		printf("%p %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
		PreOrder(p_root->left);
		PreOrder(p_root->right);
	}
}

void InOrder(bNode* p_root){
	if(p_root != NULL) {
		InOrder(p_root->left);
		printf("%p - %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
		InOrder(p_root->right);
	}
}

void PostOrder(bNode* p_root){
	if(p_root != NULL) {
		PostOrder(p_root->left);
		PostOrder(p_root->right);
		printf("%p - %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
	}
}

// Breadth-first traversal
void LevelOrder(bNode* p_root) {
	if (p_root == NULL) return;
	Queue queue = startQueue();
	Queue* p_queue = &queue;
	int poppedValue;
	enqueue(p_root,p_queue);
	while (!isQueueEmpty(p_queue)) {
		bNode* current = p_queue->array[p_queue->front];
		printf("%p - %p %d %p \n",current,current->left,current->data,current->right);
		if (current->left != NULL) enqueue(current->left,p_queue);
		if (current->right != NULL) enqueue(current->right,p_queue);
		dequeue(p_queue);
	}
	//endQueue(p_queue);
}
*/
int main() {
	
	bstNode* p_root = NULL;

	insertTree(10,&p_root);
	insertTree(0,&p_root);
	insertTree(20,&p_root);
	insertTree(-10,&p_root);
	insertTree(30,&p_root);
	insertTree(5,&p_root);
	insertTree(-5,&p_root);
	insertTree(15,&p_root);
	insertTree(-15,&p_root);
	insertTree(8,&p_root);
	insertTree(-7,&p_root);
	//printf("%p",p_root);
	//if (!treeHas(11,p_root)) printf("11 não encontrado\n");
	//LevelOrder(p_root);
	//InOrder(p_root);
	InOrderRecursive(p_root);
	printf("\n");
	InOrder(p_root);
	return 0;
}
