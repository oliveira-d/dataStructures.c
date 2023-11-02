#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

typedef struct queueNode {
	int data;
	struct queueNode* next;
} queueNode;

typedef struct Queue {
	queueNode* front;
	queueNode* rear;
} Queue;

/* function starts a queue and returns a pointer to the queue, which should be attributed to a variable.
If you want to use this on your main code, should be written like this:

Queue* p_queue = startQueue();

*/
Queue* startQueue() {
	Queue* p_queue = (Queue*)malloc(sizeof(Queue));
	p_queue->front = NULL;
	p_queue->rear = NULL;
	return p_queue;
}

bool isQueueEmpty(Queue* queue) {
	if (queue->front == NULL) return true;
	else return false;
}

/* the enqueue() function returns 0 if it fails (cannot allocate memory), 
-1 if the enqueued element is the first one and returns 1 otherwise. */
int enqueue(int x, Queue* queue) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (newNode==NULL) {
		fprintf(stderr,"Failed to enqueue: could not allocate memory\n");
		return 0;
	}
	newNode->data = x;
	newNode->next = NULL;
	if (queue->front == NULL) {
		queue->rear = newNode;
		queue->front = newNode;
		return -1;
	}
	(queue->rear)->next = newNode;
	queue->rear=newNode;
	return 1;
}

/* the dequeue() function takes the pointer to the queue and a pointer to an int variable to store the poppedValue.
The function return 0 when fails (queue is empty), returns -1 when the popped element is the last one and returns 1 otherwise. */
int dequeue(Queue* queue, int* p_poppedValue) {

	if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
		return 0;
    }

	*p_poppedValue = (queue->front)->data;
	
	queueNode* p_queueNode = queue->front;
	queue->front = (queue->front)->next; //change the current front element of the queue
	free(p_queueNode); //free previous front node
	
	if (queue->front == NULL) {
		queue->rear=NULL; // se o elemento tiver sido o último da lista, ajustar o queue->rear		
		return -1;
	} else {
		return 1;
	}
	// function returns 0 when failed (empty queue), -1 when last element was popped and 1 otherwise
}

/* endQueue() function will call dequeue() function until the last element is popped out, 
then will free the pointer to the queue. */
void endQueue(Queue* p_queue) {
	int poppedValue;
	while(dequeue(p_queue,&poppedValue) != -1);
	free(p_queue);
}

// prints values on the queue to the same line with spaces between items
void printQueue(Queue* queue) {
	queueNode* p_queueNode = queue->front;
	while(p_queueNode != NULL) {
		printf("%d ",p_queueNode->data);
		p_queueNode=(p_queueNode)->next;
	}
	printf("\n");
}

#endif // LINKED_LIST_QUEUE_H
