#ifndef CIRCULAR_ARRAY_QUEUE_H
#define CIRCULAR_ARRAY_QUEUE_H

/* diferença: em vez de i++, para uma array circular, i=(i+1)%arraySize;
 * em vez de i--, para uma array circular, i=(i+arraySize-1)%arraySize --. Esse, no entanto não, foi usado aqui. */

typedef struct Queue {
	int* array;
	int arraySize;
	int front, rear;
} Queue;

/* function starts a queue and returns a pointer to the queue, which should be attributed to a variable.
If you want to use this on your main code, should be written like this:

Queue* p_queue = startQueue();

*/
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

/* the enqueue() function returns 0 if it fails (cannot allocate memory), 
-1 if the enqueued element is the first one and returns 1 otherwise. */
int enqueue(int x,Queue* queue) {
	if (isQueueFull(queue)) {
		fprintf(stderr,"Queue is full\n");
		return 0;
	} else if (isQueueEmpty(queue)) {
		queue->array[++queue->front]=x;
		queue->rear++;
		return -1;
	}
    queue->rear=(queue->rear+1)%(queue->arraySize);
	queue->array[queue->rear]=x;
	return 1;
}

/* the dequeue() function takes the pointer to the queue and a pointer to an int variable to store the poppedValue.
The function return 0 when fails (queue is empty), returns -1 when the popped element is the last one and returns 1 otherwise. */
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

/* endQueue() function will call dequeue() function until the last element is popped out, 
then will free the pointer to the queue. */
void endQueue(Queue* p_queue) {
	int poppedValue;
	while(dequeue(p_queue,&poppedValue) != -1); // this will dequeue while there are still elements
	free(p_queue->array);
	free(p_queue);
}

// prints values on the queue to the same line with spaces between items
void printQueue(Queue* queue) {
	if (isQueueEmpty(queue)) return;
	int i;
	for (i=queue->front; i!=queue->rear; i=(i+1)%(queue->arraySize)) {
		printf("%d ",queue->array[i]);
	}
	printf("%d",queue->array[i]);
	printf("\n");
}

#endif // CIRCULAR_ARRAY_QUEUE_H