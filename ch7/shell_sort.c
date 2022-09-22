#include <stdio.h>
#define ElementType int

void ShellSort(ElementType A[], int N)
{
	int i, j, Increment, k;
	ElementType Tmp;

	for (Increment = N/2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				printf("increment=%d, i=%d, j=%d, Tmp,A[i]=%d, A[j-increment]=%d\n", Increment, i, j, Tmp, A[j-Increment]);
				if (Tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
			}
			A[j] = Tmp;
		}
		for (k = 0; k < N; k++)
			printf("%d, ", A[k]);
		printf("\n");
	}
}

int main()
{
	ElementType a[] = {81,94,11,96,12,35,17,95,28,58,41,75,15};
	int k;
	for (k = 0; k < 13; k++)
		printf("%d, ", a[k]);
	printf("\n");
	ShellSort(a, 13);
}
