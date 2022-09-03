#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void PreOrderTraversalTree(SearchTree T, int depth)
{
	if (T) {
		printf("%d>>%c\n", depth, T->Element);
		PreOrderTraversalTree(T->Left, depth+1);
		PreOrderTraversalTree(T->Right, depth+1);
	}
}

int main()
{
	SearchTree T;

	T = malloc(sizeof(struct TreeNode));
	T->Element = 'e';
	T = Insert('o', T);
	T = Insert('a', T);
	T = Insert('c', T);
	T = Insert('d', T);
	T = Insert('f', T);
	PreOrderTraversalTree(T, 0);

	Delete('a', T);
	PreOrderTraversalTree(T, 0);
}
