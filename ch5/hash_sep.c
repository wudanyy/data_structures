#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash_sep.h"

#define MinTableSize 10

Index Hash(ElementType Key, int TableSize)
{
	return Key % TableSize;
}

int IsPrime(int num){
    if((num & 1)==0)
        return num == 2;
    else {
        int i, limit = sqrt(num);
        for (i = 3; i <= limit; i+=2){
            if (num % i == 0)
                return 0;
        }
    }
    return 1;
}

int NextPrime(int num){
    int c;
    if(num < 2)
        c = 2;
    else if (num == 2)
        c = 3;
    else if(num & 1){
        num += 2;
        c = IsPrime(num) ? num : NextPrime(num);
    } else
        c = NextPrime(num-1);

    return c;
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if (TableSize < MinTableSize) {
		printf("Table size too smail");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("Out of space!!!");

	H->TableSize = NextPrime(TableSize);

	H->TheLists = malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		printf("Out of space!!!");

	for (i = 0; i < H->TableSize; i++) {
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("Out of space!!!");
		else 
			H->TheLists[i]->Next = NULL;
	}

	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != Key)
		P = P->Next;
	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL) {
		NewCell = malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("Out of space!!!");
		else {
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}

void PrintHash(HashTable H)
{
	int i;
	List L;
	L = malloc(sizeof(struct ListNode));

	for (i = 0; i < H->TableSize; i++) {
		printf("数组的第%d个:", i);
		L = H->TheLists[i];
		while (L) {
			printf("->%d", L->Element);
			L = L->Next;
		}
		printf("\n");
	}
}

int main()
{
	HashTable H;
	H = InitializeTable(99);
	Insert(89, H);
	Insert(18, H);
	Insert(49, H);
	Insert(102, H);
	Insert(149, H);
	Insert(138, H);
	Insert(157, H);
	Insert(276, H);
	Insert(203, H);
	PrintHash(H);
}
