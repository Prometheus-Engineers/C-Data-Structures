#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int front, rear, size;
	unsigned capacity;
	int *array;
} Queue;

Queue* create_queue(unsigned capacity);
int enqueue(Queue* queue, int num);
int dequeue(Queue* queue);
void print_queue(Queue queue);

Queue* create_queue(unsigned capacity)
{
	Queue* queue = (Queue *)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int *)malloc(queue->capacity * sizeof(int));
	return queue;
}

int enqueue(Queue* queue, int num)
{
	if (queue->size == queue->capacity)
		return -1;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = num;
	queue->size++;
	return 0;
}

int dequeue(Queue* queue)
{
	if (queue->size == 0)
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}

void print_queue(Queue queue)
{
	printf(" [");
	for (int i = queue.front; i <= queue.rear; i++)
		printf(" %d,", queue.array[i]);
	puts(" ]");
}
