#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("error!");
		// FatalError("Out of space!!!");
	
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;

	return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void DeleteList(List L)
{
	Position P;
	Position Tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

