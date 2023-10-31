#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree implementation

typedef struct bNode {
	int data;
	struct bNode* left;
	struct bNode* right;
} bNode;

bool isTreeEmpty(bNode* root) {
	if (root == NULL) return true;
	return false;
}

int treeHeight(bNode* root) {
	if (root == NULL) return -1;
	
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	
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

bNode* treeMin(bNode* root) {
	if (isTreeEmpty(root)) {
		printf("Error: tree is empty!");
		return NULL;
	} else if (root->left == NULL) {
		return root;
	} else return treeMin(root->left);
}

bNode* treeMax(bNode* root) {
	if (isTreeEmpty(root)) {
		printf("Error: tree is empty!");
		return NULL;
	} else if (root->right == NULL) {
		return root;
	} else return treeMin(root->right);
}

bool treeHas(int x,bNode* root) {
	if (root == NULL) return false;
	else if (x == root->data) return true;
	else if (x < root->data) return treeHas(x,root->left);
	else return treeHas(x,root->right);
}

// insertion with Recursion
bNode* insertTreeR(int x, bNode** pRoot) {
		if (*pRoot == NULL) {
			(*pRoot) = (bNode*)malloc(sizeof(bNode));
			(*pRoot)->data = x;
			(*pRoot)->left = NULL;
			(*pRoot)->right = NULL;
		} else if (x <= (*pRoot)->data) {
			(*pRoot)->left = insertTreeR(x,&(*pRoot)->left);
		} else {
			(*pRoot)->right = insertTreeR(x,&(*pRoot)->right);
		}
		return *pRoot;
}

// insertion with While Loop
void insertTreeL(int x, bNode** pRoot) {
	
	bNode* var = (bNode*)malloc(sizeof(bNode));
	var->left = NULL;
	var->right = NULL;
	var->data = x;
	
	if (*pRoot == NULL) {
		*pRoot = var;
		return;
	}
	
	bNode* temp = *pRoot;
	
	while(temp->left != var && temp->right != var) {
		
		if (x <= temp->data && temp->left == NULL) {
			temp->left = var;
		} else if (x > temp->data && temp->right == NULL) {
			temp->right = var;
		} else if (x <= temp->data) temp = temp->left;
		else temp = temp->right;
	}
}

bNode* deleteTree(int x, bNode** pRoot) {
	if (*pRoot == NULL) return NULL;
	else if (x < (*pRoot)->data) (*pRoot)->left = deleteTree(x,&(*pRoot)->left);
	else if (x > (*pRoot)->data) (*pRoot)->right = deleteTree(x,&(*pRoot)->right);
	else {
		if ((*pRoot)->left == NULL && (*pRoot)->right == NULL) {
			free(*pRoot);
			*pRoot = NULL;
		} else if ((*pRoot)->left == NULL) {
			bNode* temp = (*pRoot);
			*pRoot = (*pRoot)->right;
			free(temp);
		} else if ((*pRoot)->right == NULL) {
			bNode* temp = (*pRoot);
			*pRoot = (*pRoot)->left;
			free(temp);
		} else {
			bNode* temp = treeMin((*pRoot)->right);
			(*pRoot)->data = temp->data;
			(*pRoot)->right = deleteTree(temp->data,&(*pRoot)->right);
		}
	}
	return *pRoot;
}

// Depth-first traversal: 
void PreOrder(bNode* root){
	if(root != NULL) {
		printf("%p %p %d %p\n",root,root->left,root->data,root->right);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(bNode* root){
	if(root != NULL) {
		InOrder(root->left);
		printf("%p - %p %d %p\n",root,root->left,root->data,root->right);
		InOrder(root->right);
	}
}

void PostOrder(bNode* root){
	if(root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%p - %p %d %p\n",root,root->left,root->data,root->right);
	}
}

// Breadth-first traversal
void LevelOrder(bNode* root) {
	if (root == NULL) return;
	Queue queue = startQueue();
	enqueue(root,&queue);
	while (!isQueueEmpty(&queue)) {
		bNode* current = queue.array[queue.front];
		printf("%p - %p %d %p \n",current,current->left,current->data,current->right);
		if (current->left != NULL) enqueue(current->left,&queue);
		if (current->right != NULL) enqueue(current->right,&queue);
		dequeue(&queue);
	}
}

int main() {
	return 0;
}
