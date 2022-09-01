#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

static Position CursorAlloc(void)
{
	Position P;

	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

int IsEmpty(List L)
{
	return CursorSpace[L].Next == 0;
}

int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

List MakeEmpty(List L)
{
    if(L != 0)
        CursorSpace[L].Next = 0;
    return L;
}

Position Find(ElementType X, List L)
{
	Position P;

	P = CursorSpace[L].Next;
	while (P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;
	return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while (P && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);
	if (!IsLast(P, L)) {
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = CursorAlloc();
	if (TmpCell == 0)
		printf("Out of space!!!");
	
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}

void InsertToTail(List L, ElementType X)
{
    Position Last;
    Last = L;
    while(CursorSpace[Last].Next != 0)
        Last = CursorSpace[Last].Next;
    Insert(L, X, Last);
}

void InitCursorSpace()
{
    int i;
    for(i = 0; i <= SpaceSize; i++)
    {
        if(i != SpaceSize)
            CursorSpace[i].Next = i + 1;
        else
           CursorSpace[i].Next = 0;
    }
}

void PrintCursor(List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while(CursorSpace[P].Next != 0)
    {
        printf("%c-", CursorSpace[P].Element);
        P = CursorSpace[P].Next;
    }
    printf("%c\n", CursorSpace[P].Element);
}

int main()
{
    InitCursorSpace();
    ElementType Elem, De, PreElem, Ins;
    Position Tmp;
    List L;
    L = CursorAlloc();
    if(L == 0)
        printf("No space for Allocation");
    L = MakeEmpty(L);
    printf("请输入链表元素以'#'结束：");
    while((Elem = getchar()) != '#')
    {
        InsertToTail(L, Elem);
    }
    getchar();
    PrintCursor(L);

    printf("请输入你要删除的元素：");
    scanf("%d", &De);
    getchar();
    Delete(L, De);
    PrintCursor(L);

    printf("请输入你将要插在哪个元素后：");
    scanf("%d", &PreElem);
    getchar();
    Tmp = Find(L, PreElem);

    printf("请输入你要插入的元素：");
    scanf("%d", &Ins);
    Insert(L, Ins, Tmp);
    PrintCursor(L);
    /*最后删除整个表以及表头*/
    //DeleteList(L);
    CursorFree(L);

    return 0;
}
