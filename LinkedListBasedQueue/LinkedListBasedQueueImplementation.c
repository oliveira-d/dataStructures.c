#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedListQueue.h"

int main() {
	
	Queue* p_fila = startQueue();
	int poppedValue;
	
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	enqueue(1,p_fila);	
	enqueue(2,p_fila);	
	enqueue(3,p_fila);	
	enqueue(4,p_fila);
	printQueue(p_fila);	
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	printQueue(p_fila);
	enqueue(5,p_fila);
	printQueue(p_fila);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	if (dequeue(p_fila,&poppedValue)) printf("Popped value is %d \n",poppedValue);
	//endQueue(p_fila);
	return 0;
}