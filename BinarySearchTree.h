// Binary Search Tree implementation
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct bstNode {
	int data;
	struct bstNode* left;
	struct bstNode* right;
} bstNode;

// START OF QUEUE IMPLEMENTATION

typedef struct queueNode {
	bstNode* p_bstNode;
	struct queueNode* next;
} queueNode;

typedef struct Queue {
	queueNode* front;
	queueNode* rear;
} Queue;

/* function starts a queue and returns a pointer to the queue, which should be attributed to a variable.
If you want to use this on your main code, should be written like this:

Queue* p_queue = startQueue();

*/
Queue* startQueue() {
	Queue* p_queue = (Queue*)malloc(sizeof(Queue));
	p_queue->front = NULL;
	p_queue->rear = NULL;
	return p_queue;
}

bool isQueueEmpty(Queue* p_queue) {
	if (p_queue->front == NULL) return true;
	else return false;
}

/* the enqueue() function returns 0 if it fails (cannot allocate memory), 
-1 if the enqueued element is the first one and returns 1 otherwise. */
int enqueue(bstNode* pt_bstNode, Queue* p_queue) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (newNode==NULL) {
		fprintf(stderr,"Failed to enqueue: could not allocate memory\n");
		return 0;
	}
	newNode->p_bstNode = pt_bstNode;
	newNode->next = NULL;
	if (p_queue->front == NULL) {
		p_queue->rear = newNode;
		p_queue->front = newNode;
		return -1;
	}
	(p_queue->rear)->next = newNode;
	p_queue->rear=newNode;
	return 1;
}

/* the dequeue() function takes the pointer to the queue and a pointer to an int variable to store the poppedValue.
The function return 0 when fails (queue is empty), returns -1 when the popped element is the last one and returns 1 otherwise. */
int dequeue(Queue* p_queue, bstNode** p_poppedValue) {

	if (p_queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
		return 0;
    }

	*p_poppedValue = (p_queue->front)->p_bstNode;
	
	queueNode* p_queueNode = p_queue->front;
	p_queue->front = (p_queue->front)->next; //change the current front element of the queue
	free(p_queueNode); //free previous front node
	
	if (p_queue->front == NULL) {
        p_queue->rear=NULL; // se o elemento tiver sido o último da lista, ajustar o queue->rear		
		return -1;
	} else {
		return 1;
	}
	// function returns 0 when failed (empty queue), -1 when last element was popped and 1 otherwise
}

/* endQueue() function will call dequeue() function until the last element is popped out, 
then will free the pointer to the queue. */
void endQueue(Queue* p_queue) {
	bstNode* poppedValue;
	while(dequeue(p_queue,&poppedValue) == 1);
	free(p_queue);
}

// prints pointers to the bstNodes in the queue to the same line with spaces between items
void printQueue(Queue* p_queue) {
	queueNode* p_queueNode = p_queue->front;
	while(p_queueNode != NULL) {
		printf("%p ",p_queueNode->p_bstNode);
		p_queueNode=p_queueNode->next;
	}
	printf("\n");
}

// prints values in the bstNodes in the queue to the same line with spaces between items
void printBSTDataQueue(Queue* p_queue) {
	queueNode* p_queueNode = p_queue->front;
	while(p_queueNode != NULL) {
		printf("%d ",(p_queueNode->p_bstNode)->data);
		p_queueNode=p_queueNode->next;
	}
	printf("\n");
}

// END OF QUEUE IMPLEMENTATION

// START OF STACK IMPLEMENTATION

typedef struct stackNode {
	bstNode* p_bstNode;
	struct stackNode* next;
} stackNode;

stackNode* startStack() {
    return NULL;
}

void stackPush(bstNode* p_bstNode,stackNode** p_p_top) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->p_bstNode = p_bstNode;
	newNode->next = *p_p_top;
	*p_p_top = newNode;
}

int stackPop(stackNode** p_p_top,bstNode** p_p_poppedValue) {
	if (*p_p_top == NULL) {
        fprintf(stderr,"Can't pop element: stack is empty\n");
        return 0;
    }
	stackNode* oldNode = *p_p_top;
	*p_p_top = oldNode->next;
    *p_p_poppedValue = oldNode->p_bstNode;
	free(oldNode);
    if(*p_p_top == NULL) return -1; //returns -1 if the poppedElement was the last one and now the stack is empty, returns 1 otherwise
    return 1;
}

void printStack(stackNode* p_top) {
	if (p_top == NULL){
        fprintf(stderr,"Can't print stack: stack is empty\n"); 
        return;
    }
    while(p_top != NULL) {
		printf("%p ",p_top->p_bstNode);
		p_top=p_top->next;
	}
	printf("\n");
}

// END OF STACK IMPLEMENTATION

// START OF BINARY SEARCH TREE IMPLEMENTATION

bstNode* startBST() {
    return NULL;
}

bool isTreeEmpty(bstNode* p_root) {
	if (p_root == NULL) return true;
	return false;
}

int treeHeight(bstNode* p_root) {
	if (p_root == NULL) return -1;
	
	int leftHeight = treeHeight(p_root->left);
	int rightHeight = treeHeight(p_root->right);
	
	if (leftHeight > rightHeight) return leftHeight + 1;
	else return rightHeight + 1;
}

// Search

bstNode* treeMin(bstNode* p_root) {
	if (isTreeEmpty(p_root)) {
		fprintf(stderr,"Error: tree is empty\n");
		return NULL;
	} else if (p_root->left == NULL) {
		return p_root;
	} else return treeMin(p_root->left);
}

bstNode* treeMax(bstNode* p_root) {
	if (isTreeEmpty(p_root)) {
		fprintf(stderr,"Error: tree is empty\n");
		return NULL;
	} else if (p_root->right == NULL) {
		return p_root;
	} else return treeMin(p_root->right);
}

bool treeHas(int x,bstNode* p_root) {
	if (p_root == NULL) return false;
	else if (x == p_root->data) return true;
	else if (x < p_root->data) return treeHas(x,p_root->left);
	else return treeHas(x,p_root->right);
}

// insertion with Recursion
bstNode* insertTreeR(int x, bstNode** p_p_root) {
		if (*p_p_root == NULL) {
			(*p_p_root) = (bstNode*)malloc(sizeof(bstNode));
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
void insertTree(int x, bstNode** p_p_root) {
	
	bstNode* newNode = (bstNode*)malloc(sizeof(bstNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = x;
	
	if (*p_p_root == NULL) {
		*p_p_root = newNode;
		return;
	}
	
	bstNode* p_bstNode = *p_p_root;
	
	while(p_bstNode->left != newNode && p_bstNode->right != newNode) {
		
		if (x <= p_bstNode->data && p_bstNode->left == NULL) {
			p_bstNode->left = newNode;
		} else if (x > p_bstNode->data && p_bstNode->right == NULL) {
			p_bstNode->right = newNode;
		} else if (x <= p_bstNode->data) p_bstNode = p_bstNode->left;
		else p_bstNode = p_bstNode->right;
	}
}

bstNode* deleteTree(int x, bstNode** p_p_root) {
	if (*p_p_root == NULL) {
		printf("Value %d not found in tree");
		return NULL;
	} else if (x < (*p_p_root)->data) (*p_p_root)->left = deleteTree(x,&(*p_p_root)->left);
	else if (x > (*p_p_root)->data) (*p_p_root)->right = deleteTree(x,&(*p_p_root)->right);
	else {
		if ((*p_p_root)->left == NULL && (*p_p_root)->right == NULL) {
			free(*p_p_root);
			*p_p_root = NULL;
		} else if ((*p_p_root)->left == NULL) {
			bstNode* temp = (*p_p_root);
			*p_p_root = (*p_p_root)->right;
			free(temp);
		} else if ((*p_p_root)->right == NULL) {
			bstNode* temp = (*p_p_root);
			*p_p_root = (*p_p_root)->left;
			free(temp);
		} else {
			bstNode* temp = treeMin((*p_p_root)->right);
			(*p_p_root)->data = temp->data;
			(*p_p_root)->right = deleteTree(temp->data,&(*p_p_root)->right);
		}
	}
	return *p_p_root;
}

// Depth-first traversal: 
void PreOrderRecursive(bstNode* p_root){
	if(p_root != NULL) {
		printf("%p %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
		PreOrderRecursive(p_root->left);
		PreOrderRecursive(p_root->right);
	}
}

// Preorder traversal using an iterative approach
void PreOrder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }

    struct stackNode* stack = NULL;
    struct bstNode* current = root;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            printf("%p %p %d %p\n",current,current->left,current->data,current->right);

            if (current->right != NULL) {
                stackPush(current->right,&stack);
            }

            current = current->left;
        }

        if (stack != NULL) {
			bstNode* poppedValue = NULL;
            stackPop(&stack,&poppedValue);
			current = poppedValue;
        }
    }
}


void InOrderRecursive(bstNode* p_root){
	if(p_root != NULL) {
		InOrderRecursive(p_root->left);
		printf("%p - %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
		InOrderRecursive(p_root->right);
	}
}

void InOrder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }

    stackNode* stack = NULL;
    bstNode* current = root;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            stackPush(current,&stack);
            current = current->left;
        }

        stackPop(&stack,&current);
        printf("%p - %p %d %p\n", current, current->left, current->data, current->right);
        current = current->right;
    }
}

void PostOrderRecursive(bstNode* p_root){
	if(p_root != NULL) {
		PostOrderRecursive(p_root->left);
		PostOrderRecursive(p_root->right);
		printf("%p - %p %d %p\n",p_root,p_root->left,p_root->data,p_root->right);
	}
}

void PostOrder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }

    struct stackNode* stack1 = NULL;
    struct stackNode* stack2 = NULL;

    stackPush(root,&stack1);

    bstNode* current=NULL;
	while (stack1 != NULL) {
        stackPop(&stack1,&current);
        stackPush(current,&stack2);

        if (current->left != NULL) {
            stackPush(current->left,&stack1);
        }

        if (current->right != NULL) {
            stackPush(current->right,&stack1);
        }
    }

	while (stack2 != NULL) {
		stackPop(&stack2,&current);
        printf("%p - %p %d %p\n", current, current->left, current->data, current->right);
    }
}

void LevelOrder(bstNode* p_root) {
	if (p_root == NULL) return;
	Queue* p_queue = startQueue();
	bstNode* poppedValue;
	enqueue(p_root,p_queue);
    printf("Address - LeftAddr Value RightAddr\n");
	while (!isQueueEmpty(p_queue)) {
		bstNode* current = (p_queue->front)->p_bstNode;
		bstNode* poppedValue = NULL;
        printf("%p - %p %d %p \n",current,current->left,current->data,current->right);
		if (current->left != NULL) enqueue(current->left,p_queue);
		if (current->right != NULL) enqueue(current->right,p_queue);
		dequeue(p_queue,&poppedValue);
	}
	free(p_queue);
}

#endif // BINARY_SEARCH_TREE_H