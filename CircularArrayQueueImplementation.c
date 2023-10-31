#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* diferença: em vez de i++, para uma array circular, i=(i+1)%arraySize;
 * em vez de i--, para uma array circular, i=(i+arraySize-1)%arraySize --. Esse, no entanto não, foi usado aqui. */

typedef struct Queue {
	int* array;
	int arraySize;
	int front, rear;
} Queue;

Queue* startQueue(int items) {
	Queue* p_queue = (Queue*)malloc(sizeof(Queue));
	p_queue->front=-1;
	p_queue->rear=-1;
	p_queue->array=(int*)malloc(items*sizeof(int));
	p_queue->arraySize = items;
	return p_queue;
}

bool isQueueEmpty(Queue* queue) {
	if (queue->front == -1) return true;
	return false;
}

bool isQueueFull(Queue* queue) {
	if ((queue->rear+1)%(queue->arraySize) == queue->front) return true;
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
	queue->rear=(queue->rear+1)%(queue->arraySize);
	queue->array[queue->rear]=x;
	return 0;
}

int dequeue(Queue* queue,int* p_poppedValue) {
	if (isQueueEmpty(queue)) {
		fprintf(stderr,"Could not pop value: queue is empty\n");
		return 0;
	} else *p_poppedValue = queue->array[queue->front];
	
	if (queue->front == queue->rear){ // se houver apenas um elemento na fila
		queue->front=-1;
		queue->rear=-1;
		return -1;
	} else {
		queue->front=(queue->front+1)%(queue->arraySize);
		return 1;
	}
	// function returns 0 when fails (queue is empty), -1 when the popped element was the last one in the queue, 1 when not
}

void endQueue(Queue* p_queue) {
	int poppedValue;
	while(dequeue(p_queue,&poppedValue) != -1); // this will dequeue while there are still elements
	free(p_queue->array);
	free(p_queue);
}

void printQueue(Queue* queue) {
	if (isQueueEmpty(queue)) return;
	int i;
	for (i=queue->front; i!=queue->rear; i=(i+1)%(queue->arraySize)) {
		printf("%d ",queue->array[i]);
	}
	printf("%d",queue->array[i]);
	printf("\n");
}

int main() {
	
	Queue* p_fila = startQueue(10);
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

	endQueue(p_fila);

	return 0;	
}

