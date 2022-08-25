#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void InitList(List L)
{
	int i;
	//int d;

	for(i=0; i<=5; i++)
	{
		//printf("输入链表的第%d个数据值\n", i+1);
		//scanf("%d", &d);
		Position p = (Position)malloc(sizeof(struct Node));
		p->Element = i+1;
		p->Next = NULL;
		L->Next = p;
		L = p;
	}
}

void PrintList(List L)
{
	printf("输出链表值\n");
	while(L->Next != NULL)
	{
		L = L->Next;
		printf("%d\t", L->Element);
	}
    printf("\n");
}

int main()
{
	List l = MakeEmpty();
    InitList(l);
    PrintList(l);

    int e = IsEmpty(l);
	printf("链表是否为空：%d\n", e);

    printf("5后面插入9\n");
    Position p2 = Find(5, l);
    Insert(9, l, p2);
    PrintList(l);
    Position p6 = Find(6, l);
    printf("6是否是last: %d\n", IsLast(p6, l));
    printf("删除6\n");
    Delete(6, l);
    PrintList(l);
    printf("删除整个链表\n");
    DeleteList(l);
    PrintList(l);

	
	return 0;
}
