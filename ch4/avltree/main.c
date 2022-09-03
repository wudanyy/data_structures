#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void PrintTree(AvlTree T)
{
	if (T) {
		printf("--%d",T->Element);
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
}

int main()
{
	AvlTree T;
	T = malloc(sizeof(struct AvlNode));
	T->Element = 1;
	T->Left = T->Right = NULL;
	T = Insert(2, T);
	T = Insert(3, T);
	T = Insert(4, T);
	T = Insert(5, T);
	T = Insert(6, T);
	T = Insert(7, T);
	T = Insert(16, T);
	T = Insert(15, T);
	T = Insert(14, T);
	T = Insert(13, T);
	T = Insert(12, T);
	T = Insert(11, T);
	T = Insert(10, T);
	T = Insert(8, T);
	T = Insert(9, T);
	PrintTree(T);
}
