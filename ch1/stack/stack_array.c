#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize)
		printf("Stack size is too small");

	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of space!!!");

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL)
		printf("Out of space!!!");

	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		printf("Full Stack");
	else
		printf("push %d\n", X);
		S->Array[++(S->TopOfStack)] = X;
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("Empty stack");
	return 0;
}

void Pop(Stack S)
{
	printf("pop\n");
	if (IsEmpty(S))
		printf("Empty stack");
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	printf("Empty stack");
	return 0;
}

void PrintStack(Stack S)
{
	int i;

	for (i=S->TopOfStack; i!=EmptyTOS; i--) {
		printf("->%d", S->Array[i]);
	}
}

int main()
{
	Stack S;
	S = CreateStack(12);
	Push(1, S);
	Push(3, S);
	Push(2, S);
	Push(6, S);
	Push(5, S);
	Pop(S);
	PrintStack(S);
}
