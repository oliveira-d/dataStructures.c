#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

Queue* startQueue() {
	Queue* p_queue = (Queue*)malloc(sizeof(Queue));
	p_queue->front=-1;
	p_queue->rear=-1;
	return p_queue;
}

bool isQueueEmpty(Queue* queue) {
	if (queue->front == -1) return true;
	return false;
}

bool isQueueFull(Queue* queue) {
	if ((queue->rear+1)%n == queue->front) return true;
	else return false;
}

int enqueue(int x,Queue* queue) {
	if (isQueueEmpty(queue)) {
		queue->array[++queue->front]=x;
		queue->rear++;
		return 0;
	} else if (isQueueFull(queue)) {
		fprintf(stderr,"Queue is full\n");
		return -1;
	}
	queue->rear=(queue->rear+1)%n;
	queue->array[queue->rear]=x;
	return 0;
}

int dequeue(Queue* queue,int* p_poppedValue) {
	if (isQueueEmpty(queue)) {
		fprintf(stderr,"Could not pop value: queue is empty\n");
		return -1;
	} else *p_poppedValue = queue->array[queue->front];
	
	if (queue->front == queue->rear){ // se houver apenas um elemento na fila
		queue->front=-1;
		queue->rear=-1;
	} else {
		queue->front=(queue->front+1)%n;
	}
	return 0;
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
	
	Queue* p_fila = startQueue();
	int poppedValue;

	enqueue(1,p_fila);
	enqueue(2,p_fila);
	enqueue(3,p_fila);
	enqueue(4,p_fila);
	enqueue(5,p_fila);
	printQueue(p_fila);
	if (!dequeue(p_fila,&poppedValue)) printf("%d \n",poppedValue);
	printQueue(p_fila);
	enqueue(6,p_fila);
	enqueue(7,p_fila);
	enqueue(8,p_fila);
	enqueue(9,p_fila);
	enqueue(10,p_fila);
	enqueue(11,p_fila);
	printQueue(p_fila);
	enqueue(12,p_fila);
	printQueue(p_fila);
	if (!dequeue(p_fila,&poppedValue)) printf("%d \n",poppedValue);
	printQueue(p_fila);
	enqueue(12,p_fila);
	printQueue(p_fila);

	return 0;	
}

