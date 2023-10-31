#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	int data;
	struct stackNode* next;
} stackNode;

void Push(int x,stackNode** pTop) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->next = *pTop;
	*pTop = newNode;
}

void Pop(stackNode** pTop) {
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
	Push(1,&top);
	Push(2,&top);
	Push(3,&top);
	Push(4,&top);
	
	Print(top);
	
	Pop(&top);
	
	Print(top);
	
	Push(5,&top);
	
	Print(top);
	
}
