#include <stdio.h>

void InsertionSort(int A[], int N)
{
	int j, P, i;
	int Tmp;

	for (P = 1; P < N; P++)
	{
		Tmp = A[P];
		for (j = P; j > 0 && A[j-1] > Tmp; j--) {
			A[j] = A[j-1];
		}
		A[j] = Tmp;
		for (i = 0; i < N; i++) {
			printf("%d,", A[i]);
		}
		printf("\n");
	}
}

int main()
{
	int a[] = {9, 7, 11, 6, 8, 5,};
	InsertionSort(a, 6);
}
