#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

typedef struct stackNode {
	int data;
	struct stackNode* next;
} stackNode;

stackNode* startStack() {
    return NULL;
}

void stackPush(int x,stackNode** p_p_top) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->next = *p_p_top;
	*p_p_top = newNode;
}

int stackPop(stackNode** p_p_top,int* p_poppedValue) {
	if (*p_p_top == NULL) {
        fprintf(stderr,"Can't pop element: stack is empty\n");
        return 0;
    }
	stackNode* oldNode = *p_p_top;
	*p_p_top = oldNode->next;
    *p_poppedValue = oldNode->data;
	free(oldNode);
    if(*p_p_top == NULL) return -1; //returns -1 if the poppedElement was the last one and now the stack is empty, returns 1 otherwise
    return 1;
}

void printStack(stackNode* top) {
	if (top == NULL){
        fprintf(stderr,"Can't print stack: stack is empty\n"); 
        return;
    }
    while(top != NULL) {
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}

#endif