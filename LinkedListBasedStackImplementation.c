#include <stdio.h>
#include <stdlib.h>

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

int main() {
	stackNode* top = NULL;
	push(1,&top);
	push(2,&top);
	push(3,&top);
	push(4,&top);
	
	Print(top);
	
	pop(&top);
	
	Print(top);
	
	push(5,&top);
	
	Print(top);
	
}
