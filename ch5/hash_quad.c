#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash_quad.h"

#define MinTableSize 9

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

	if (TableSize < MinTableSize) 
	{
		printf("Table size too small");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("Out of space!!!");

	H->TableSize  = NextPrime(TableSize);

	H->TheCells = malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL)
		printf("Out of space!!!");

	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;

	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}

HashTable Rehash(HashTable H)
{
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);

	for (i = 0; i < OldSize; i++) 
	{
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);
	}

	free(OldCells);

	return H;
}

void PrintHash(HashTable H)
{
	Cell *C;
	C = malloc(sizeof(Cell));
	int i;

	printf("表长:%d\n", H->TableSize);
	for (i = 0; i < H->TableSize; i++)
	{
		C = &(H->TheCells[i]);
		printf("->%d", C->Element);
	}
	printf("\n");

}

int main() 
{
	HashTable H;
	H = InitializeTable(20);
	Insert(23, H);
	Insert(29, H);
	Insert(37, H);
	Insert(68, H);
	PrintHash(H);
	Position Pos;
	Pos = Find(29, H);
	printf("29的位置:%d\n", Pos);
	HashTable H1;
	printf("再散列,");
	H1 = Rehash(H);
	PrintHash(H1);
}
