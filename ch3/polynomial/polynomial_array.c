/*顺序存储实现的线性表，完成两个多项式相加和相乘的计算*/
#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 20
#define Max(a,b) ((a) > (b) ? (a) : (b))

typedef struct Node
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} * Polynomial;

void ZeroPolynomial(Polynomial Poly);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);

void ZeroPolynomial(Polynomial Poly)
{
	int i;

	for (i = 0; i <= MaxDegree + 1; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	int i;

	ZeroPolynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

	for (i = PolySum->HighPower; i >= 0; i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	int i, j;
	
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if (PolyProd->HighPower > MaxDegree)
		printf("Exceeded array size");
	else
		for (i = 0; i <= Poly1->HighPower; i++)
		{
			for (j = 0; j <= Poly2->HighPower; j++)
				PolyProd->CoeffArray[i+j] += Poly1->CoeffArray[i] + Poly2->CoeffArray[j];;
		}
}

void PrintPolynomial(Polynomial Poly)
{
	int i;

	for (i = 0; i <= Poly->HighPower + 1; i++)
	{
		printf("+%dX^%d\t", Poly->CoeffArray[i], i);
	}
	printf("\n");
}

int main()
{
	Polynomial P1, P2, P3, P4;
	P1 = (Polynomial)malloc(sizeof(struct Node));
	P2 = (Polynomial)malloc(sizeof(struct Node));
	P3 = (Polynomial)malloc(sizeof(struct Node));
	P4 = (Polynomial)malloc(sizeof(struct Node));
	ZeroPolynomial(P1);
	P1->HighPower = 5;
	P1->CoeffArray[0] = 9;
	P1->CoeffArray[1] = 4;
	P1->CoeffArray[2] = 1;
	P1->CoeffArray[3] = 2;
	P1->CoeffArray[4] = 0;
	P1->CoeffArray[5] = 1;
	printf("多项式1:\n");
	PrintPolynomial(P1);
	
	ZeroPolynomial(P2);
	P2->HighPower = 8;
	P2->CoeffArray[0] = 1;
	P2->CoeffArray[1] = 0;
	P2->CoeffArray[2] = 7;
	P2->CoeffArray[3] = 0;
	P2->CoeffArray[4] = 0;
	P2->CoeffArray[5] = 0;
	P2->CoeffArray[6] = 0;
	P2->CoeffArray[7] = 0;
	P2->CoeffArray[8] = 1;
	printf("多项式2:\n");
	PrintPolynomial(P2);

	AddPolynomial(P1, P2, P3);
	printf("多项式和:\n");
	PrintPolynomial(P3);
 	MultPolynomial(P1, P2, P4);
	printf("多项式积:\n");
	PrintPolynomial(P4);

	return 0;
}

