#include <stdio.h>
#include <stdbool.h>
#define n 10

/* diferença: em vez de i++, para uma array circular, i=(i+1)%n;
 * em vez de i--, para uma array circular, i=(i+n-1)%n --. Esse, no entanto não, foi usado aqui. */

int throwError() {
	printf("NO CAN DO.\n"); return -1;
}

typedef struct Queue {
	int array[n];
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
	else return true;
}

void enqueue(int x,Queue* queue) {
	if (isQueueEmpty(queue)) {
		queue->array[++queue->front]=x;
		queue->rear++;
	} else if (isQueueFull(queue)) {
		throwError();
		return;
	} else {
		queue->rear=(queue->rear+1)%n;
		queue->array[queue->rear]=x;
	}
}

int dequeue(Queue* queue) {
	int pop;
	if (isQueueEmpty(queue)) {
		pop = throwError();
	} else if (queue->front == queue->rear){ // se houver apenas um elemento na fila
		pop = queue->array[queue->front];
		queue->front=-1;
		queue->rear=-1;
	} else {
		pop = queue->array[queue->front];
		queue->front=(queue->front+1)%n;
	}
	return pop;
}

void printQueue(Queue* queue) {
	if (isQueueEmpty(queue)) return;
	int i;
	for (i=queue->front; i!=queue->rear; i=(i+1)%n) {
		printf("%d ",queue->array[i]);
	}
	printf("%d",queue->array[i]);
	printf("\n");
}

int main() {
	
	Queue fila = startQueue();
	
	char c; int x;
	do {
		printf("Entre com 'e' para adicionar um número na fila, 'd' para retirar um número da fila ou outra tecla para encerrar o programa: ");
		scanf(" %c",&c);
		if (c == 'e') {
			printf("Entre com o valor a ser inserido na fila: ");
			scanf("%d",&x);
			enqueue(x,&fila);
			printQueue(&fila);
		} else if (c == 'd') {
			printf("%d\n",dequeue(&fila));
			printQueue(&fila);
		} else {
			c = '\0';
		}
	} while ( c != '\0');
	
	return 0;	
}

