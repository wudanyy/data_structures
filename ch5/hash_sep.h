#ifndef _HashSep_H

typedef int ElementType;
typedef unsigned int Index;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);

#endif

struct ListNode
{
	ElementType Element;
	Position    Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};
