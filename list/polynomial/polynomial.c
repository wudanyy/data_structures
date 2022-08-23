/*顺序存储实现的线性表，完成两个多项式相加和相乘的计算*/
#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 8
#define Max(a,b) ((a) > (b) ? (a) : (b))

typedef struct
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

void InitPolynomial(Polynomial Poly)
{
	int i;

	for (i = 0; i < MaxDegree; i++)
	{
		printf("in init..for, %d\n", i);
		scanf("%d", &(Poly->CoeffArray[i]));
		if (Poly->CoeffArray[i] != 0)
			Poly->HighPower = i;
	}
}

void PrintPolynomial(Polynomial Poly)
{
	int i;

	for (i = 0; i < MaxDegree; i++)
	{
		printf("%dX^%d\t", Poly->CoeffArray[i], i);
	}
	printf("HighPower %d", Poly->HighPower);
	printf("\n");
}

int main()
{
	Polynomial P1;
	printf("多项式1\n");
	InitPolynomial(P1);
	PrintPolynomial(P1);
	Polynomial P2;
	printf("多项式2\n");
	InitPolynomial(P2);
	PrintPolynomial(P2);

	Polynomial PSum;
	ZeroPolynomial(PSum);
	
	AddPolynomial(P1, P2, PSum);

	return 0;
}
