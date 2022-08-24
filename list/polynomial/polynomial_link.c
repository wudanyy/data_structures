/*链式存储实现的线性表，完成两个多项式相加和相乘的计算*/
#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;

struct Node
{
	int Coef;
	int Expon;
	PtrToNode Next;
};

void AttachPolynomial(int c, int e, Polynomial *p)
{
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct Node));
	P->Coef = c;
	P->Expon = e;
	P->Next = NULL;

	(*p)->Next = P;
	*p = P;
}

int Compare(int d1, int d2)
{
	if (d1 == d2) 
		return 0;
	else if (d1 > d2) 
		return 1;
	else 
		return -1;
}

Polynomial AddPolynomial(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct Node));
	front = rear;
	while (P1 && P2) {
		switch (Compare(P1->Expon, P2->Expon)) {
			case 1:
				AttachPolynomial(P1->Coef, P1->Expon, &rear);
				P1 = P1->Next;
				break;
			case -1:
				AttachPolynomial(P2->Coef, P2->Expon, &rear);
				P2 = P2->Next;
				break;
			case 0:
				sum = P1->Coef + P2->Coef;
				if (sum) AttachPolynomial(sum, P1->Expon, &rear);
				P1 = P1->Next;
				P2 = P2->Next;
				break;
		}
	}
	for (; P1; P1 = P1->Next) AttachPolynomial(P1->Coef, P1->Expon, &rear);
	for (; P2; P2 = P2->Next) AttachPolynomial(P2->Coef, P2->Expon, &rear);
	rear->Next = NULL;
	temp = front;
	front = front->Next;
	free(temp);

	return front;
}

Polynomial ReadPolynomial()
{
	Polynomial P, rear, temp;
	int c, e, n;

	printf("多项式的项数:\n");
	scanf("%d", &n);
	P = (Polynomial)malloc(sizeof(struct Node));
	P->Next = NULL;
	rear = P;

	printf("输入多项式的系数和指数:\n");
	while (n--) {
		scanf("%d %d", &c, &e);
		AttachPolynomial(c, e, &rear);
	}
	temp = P; 
	P = P->Next;
	free(temp);
	return P;

}

void PrintPolynomial(Polynomial P)
{
	printf("多项式:\n");
	if (!P) {
		printf("0 0\n");
		return;
	}

	while (P) {
		printf("+%dX^%d\t", P->Coef, P->Expon);
		P = P->Next;
	}
	printf("\n");
}

int main()
{
	Polynomial P1, P2, PSum;
	P1 = ReadPolynomial();
	PrintPolynomial(P1);

	P2 = ReadPolynomial();
	PrintPolynomial(P2);

	PSum = AddPolynomial(P1, P2);
	PrintPolynomial(PSum);

}


