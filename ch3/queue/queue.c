#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;

	if (MaxElements < MinQueueSize)
		printf("Queue size is too small");

	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		printf("Out of space!!!");

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if (Q->Array == NULL)
		printf("Out of space!!!");
	Q->Capacity = MaxElements;
	MakeEmpty(Q);

	return Q;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL) {
		free(Q->Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		printf("Full queue");
	else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		printf("Empty queue");
	else {
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType Front(Queue Q)
{
	if (IsEmpty(Q))
		printf("Empty queue");
	else 
		return Q->Array[Q->Front];
}

int main()
{
    Queue queue = CreateQueue(1000);

    Enqueue(10, queue);
    Enqueue(20, queue);
    Enqueue(30, queue);
    Enqueue(40, queue);

	printf("dequeued from queue\n\n");
	Dequeue(queue);

    printf("Front item is %d\n", Front(queue));
    //printf("Rear item is %d\n", rear(queue));

    return 0;
}
