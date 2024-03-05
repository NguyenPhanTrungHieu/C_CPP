#include <stdio.h> //test

void IN(int A[], int nA);
int CON(int A[], int nA, int B[], int nB);
int BANG(int A[], int nA, int B[], int nB);
void HOP(int A[], int nA, int B[], int nB, int C[], int &nC);

int main()
{
	int A[] = {1, 2}, B[] = {4, 2, 1}, nA = 2, nB = 3, C[100], nC = 0;
	printf("\n A con B: %d", CON(A, nA, B, nB));
	printf("\n A = B: %d \n", BANG(A, nA, B, nB));
	HOP(A, nA, B, nB, C, nC);
	IN(C, nC);
}

void IN(int A[], int nA)
{
	for (int i = 0; i < nA; i++)
		printf("%d ", A[i]);
}

int CON(int A[], int nA, int B[], int nB)
{
	int kt = 1, kt1;
	for (int i = 0; i < nA; i++)
	{ // A
		kt1 = 0;
		for (int j = 0; j < nB; j++)
		{ // B
			if (A[i] == B[j])
			{
				kt1 = 1;
				break;
			}
		} // B
		if (kt1 == 0)
		{
			kt = 0;
			return kt;
		}
	} // A
	return kt;
}

int BANG(int A[], int nA, int B[], int nB)
{
	int kt = 1;
	if (nA != nB)
	{
		kt = 0;
		return kt;
	}
	else
		kt = CON(A, nA, B, nB);
	return kt;
}

void HOP(int A[], int nA, int B[], int nB, int C[], int &nC)
{
	for (int i = 0; i < nA; i++)
	{ // A
		C[nC] = A[i];
		nC++;
	} // A
	for (int i = 0; i < nB; i++)
	{ // B
		int kt = 0;
		for (int j = 0; j < nC; j++)
		{ // C
			if (B[i] == C[j])
			{
				kt = 1;
				break;
			}
		} // C
		if (kt == 0)
		{
			C[nC] = B[i];
			nC++;
		}
	} // B
}
