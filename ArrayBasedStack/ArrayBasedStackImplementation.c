#include <stdio.h>
#define n 10

typedef struct Stack {
	int array[n];
	int top;
} Stack;

Stack startStack(){
	Stack S;
	S.top = -1;
	return S;
}


void Push(int x,Stack* stack) {
	if (stack->top == n-1) {
		printf("Error: stack overflow. Value %d can't be added in position %d.\n",x,stack->top+1);
		return;
	}
	stack->array[++(stack->top)] = x;
}

void Pop(Stack* stack) {
	if(stack->top > -1) (stack->top)--;
}

void Print(Stack* stack) {
	for (int i=0; i<=stack->top; i++) {
		printf("%d ",stack->array[i]);
	}
	printf("\n");
}

int main() {
	Stack stack = startStack();
	Push(2,&stack);
	Push(3,&stack);
	Push(4,&stack);
	Push(5,&stack);
	Push(6,&stack);
	
	Print(&stack);
	
	Pop(&stack);
	
	Print(&stack);
	
	Push(7,&stack);
	
	Print(&stack);
	
	Push(8,&stack);
	Push(9,&stack);
	Push(10,&stack);
	Push(11,&stack);
	Push(12,&stack);
	Push(13,&stack);
	Print(&stack);
}
