#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int throwError() {
	printf("NO CAN DO.\n"); return -1;
}

typedef struct qNode {
	int data;
	struct qNode* next;
} qNode;

typedef struct Queue {
	qNode* front;
	qNode* rear;
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
	qNode* var = (qNode*)malloc(sizeof(qNode));
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

int dequeue(Queue* queue, int** p_p_poppedValue) {

	if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
		// free the address of a possible previously popped number before assignin NULL to the pointer 
		if (*p_p_poppedValue != NULL) free(*p_p_poppedValue);
		*p_p_poppedValue = NULL;
        return -1;
    }

	qNode* p_qNode = queue->front;
	
	int* p_poppedValue = (int*)malloc(sizeof(int));
	*p_poppedValue = (queue->front)->data;
	//the pointer might not be null, so before assigning a new address to the next popped value we must check and free the previous if needed
	if (*p_p_poppedValue != NULL) free(*p_p_poppedValue);
	free(*p_p_poppedValue);
	*p_p_poppedValue = p_poppedValue;

	queue->front = (queue->front)->next;
	if (queue->front == NULL) queue->rear=NULL; // se o elemento tiver sido o último da lista, ajustar o queue->rear
	free(p_qNode);
	return 0;
}

void printQueue(Queue* queue) {
	qNode* p_qNode = queue->front;
	while(p_qNode != NULL) {
		printf("%d ",p_qNode->data);
		p_qNode=(p_qNode)->next;
	}
	printf("\n");
}

int main() {
	
	Queue* p_fila = startQueue();
	int* p_poppedValue;
	
	if (dequeue(p_fila,&p_poppedValue) == 0) printf("Popped value is %d \n",*p_poppedValue);
	enqueue(1,p_fila);	
	enqueue(2,p_fila);	
	enqueue(3,p_fila);	
	enqueue(4,p_fila);
	printQueue(p_fila);	
	if (dequeue(p_fila,&p_poppedValue) == 0) printf("Popped value is %d \n",*p_poppedValue);
	printQueue(p_fila);
	enqueue(5,p_fila);
	printQueue(p_fila);

	return 0;
}