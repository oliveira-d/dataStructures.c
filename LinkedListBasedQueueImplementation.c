#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode {
	int data;
	struct queueNode* next;
} queueNode;

typedef struct Queue {
	queueNode* front;
	queueNode* rear;
} Queue;

bool isQueueEmpty(Queue* queue) {
	if (queue->front == NULL) return true;
	else return false;
}

Queue* startQueue() {
	Queue* p_queue = (Queue*)malloc(sizeof(Queue));
	p_queue->front = NULL;
	p_queue->rear = NULL;
	return p_queue;
}

void enqueue(int x, Queue* queue) {
	queueNode* var = (queueNode*)malloc(sizeof(queueNode));
	var->data = x;
	var->next = NULL;
	if (queue->front == NULL) {
		queue->rear = var;
		queue->front = var;
		return;
	}
	(queue->rear)->next = var;
	queue->rear=var;
}

int dequeue(Queue* queue, int* p_poppedValue) {

	if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
		return -1;
    }

	*p_poppedValue = (queue->front)->data;
	
	queueNode* p_queueNode = queue->front;
	queue->front = (queue->front)->next; //change the current front element of the queue
	if (queue->front == NULL) queue->rear=NULL; // se o elemento tiver sido o último da lista, ajustar o queue->rear
	free(p_queueNode); // free previous queue front element
	return 0;
}

void printQueue(Queue* queue) {
	queueNode* p_queueNode = queue->front;
	while(p_queueNode != NULL) {
		printf("%d ",p_queueNode->data);
		p_queueNode=(p_queueNode)->next;
	}
	printf("\n");
}

int main() {
	
	Queue* p_fila = startQueue();
	int poppedValue;
	
	if (!dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	enqueue(1,p_fila);	
	enqueue(2,p_fila);	
	enqueue(3,p_fila);	
	enqueue(4,p_fila);
	printQueue(p_fila);	
	if (!dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	printQueue(p_fila);
	enqueue(5,p_fila);
	printQueue(p_fila);

	return 0;
}