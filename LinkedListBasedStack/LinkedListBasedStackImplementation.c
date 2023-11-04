#include <stdio.h>
#include <stdlib.h>
#include "LinkedListStack.h"
/*
typedef struct stackNode {
	int data;
	struct stackNode* next;
} stackNode;

void push(int x,stackNode** pTop) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->next = *pTop;
	*pTop = newNode;
}

void pop(stackNode** pTop) {
	if (*pTop == NULL) return;
	stackNode* temp = *pTop;
	*pTop = temp->next;
	free(temp);
}

void Print(stackNode* top) {
	while(top != NULL) {
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}
*/
int main() {
	stackNode* p_top = startStack();
	int poppedValue;
	stackPush(1,&p_top);
	stackPush(2,&p_top);
	stackPush(3,&p_top);
	stackPush(4,&p_top);
	stackPush(5,&p_top);
	stackPush(6,&p_top);
	stackPush(7,&p_top);
	stackPush(8,&p_top);
	stackPush(9,&p_top);
	stackPush(10,&p_top);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPush(11,&p_top);
	printStack(p_top);
	stackPush(12,&p_top);
	printStack(p_top);
	stackPush(13,&p_top);
	printStack(p_top);
	stackPush(14,&p_top);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	stackPop(&p_top,&poppedValue);
	printStack(p_top);
	return 0;	
}
