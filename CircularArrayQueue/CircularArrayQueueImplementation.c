#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CircularArrayQueue.h"

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

