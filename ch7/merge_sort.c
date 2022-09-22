#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	printf("in Merge: Lpos=%d, Rpos=%d, RightEnd=%d, LeftEnd=%d, NumElements=%d\n", Lpos, Rpos, RightEnd, LeftEnd, NumElements);

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		printf("while1: Lpos=%d, LeftEnd=%d, Rpos=%d, RightEnd=%d, A[Lpos]=%d, A[Rpos]=%d\n", Lpos, LeftEnd, Rpos, RightEnd, A[Lpos], A[Rpos]);
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}

	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];

	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;

	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		printf("center=%d,left=%d,right=%d\n", Center, Left, Right);
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void MergeSort(ElementType A[], int N)
{
	ElementType *TmpArray;

	TmpArray = malloc(N * sizeof(ElementType));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N-1);
		free(TmpArray);
	} else
		printf("No space for tmp array!!!");

	int i;
	for (i = 0; i < N; i++)
		printf("%d,", A[i]);
}

int main()
{
	ElementType a[] = {1, 13, 24, 26, 2, 15, 27, 38};
	MergeSort(a, 8);
}
