#include <stdio.h>
#include <stdlib.h>
#include "stack_link.h"

Stack CreateStack()
{
	Stack S;

	S = malloc(sizeof(struct Node));
	if (S == NULL)
		printf("Out of space!!!");
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;

	if (IsEmpty(S))
		printf("Empty Stack");
	else {
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
		printf("Must use CreateStack first");
	else
		while (!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space!!!");
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	printf("Empty Stack");
	return 0;
}

void PrintStack(Stack S)
{
	while (S) {
		printf("->%d", S->Element);
		S = S->Next;
	}
	printf("\n");
}

int main()
{
	Stack S;
	S = CreateStack();
	Push(1, S);
	Push(3, S);
	Push(2, S);
	Push(5, S);
	PrintStack(S);
	printf("pop一个\n");
	Pop(S);
	printf("当前top: %d\n", Top(S));
	PrintStack(S);
}
