#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
	int data;
	struct sNode* next;
} sNode;

void Push(int x,sNode** pTop) {
	sNode* var = (sNode*)malloc(sizeof(sNode));
	var->data = x;
	var->next = *pTop;
	*pTop = var;
}

void Pop(sNode** pTop) {
	if (*pTop == NULL) return;
	sNode* temp = *pTop;
	*pTop = temp->next;
	free(temp);
}

void Print(sNode* top) {
	while(top != NULL) {
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}

int main() {
	sNode* top = NULL;
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
