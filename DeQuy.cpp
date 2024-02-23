#include <stdio.h>

static int MAX = 100;
int A1(int n);									// Bai1
int A2(int n);									// Bai2
int A3(int a, int b);							// Bai3
void A4(int n, char A, char B, char C, int &d); // Bai4 - Thap Ha Noi
void In(int a[], int n, int i);					// Bai5 - In Mang
int Tong(int a[], int n);						// Bai6 - Tong mang

int main()
{
	int A[MAX] = {1, 2, 3}, na = 3, i = 0;
	int x = 5, a = 9, b = 6;
	int n = 3, d = 0;
	printf("\nBai 1: %d", A1(x));
	printf("\nBai 2: %d", A2(x));
	printf("\nBai 3: %d", A3(a, b));
	A4(n, 'A', 'B', 'C', d);
	printf("\n");
	In(A, na, 0);
	printf("\nTong cac phan tu trong mang = %d", Tong(A, na));
	return 0;
}

int A1(int n)
{
	if (n <= 0)
		return 1;
	else
		return n * A1(n - 1);
}

int A2(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return A2(n - 1) + A2(n - 2);
}

int A3(int a, int b)
{
	if (b == 0)
		return a;
	else
		return A3(b, a % b);
}

void A4(int n, char A, char B, char C, int &d)
{
	if (n == 1)
		printf("\n%d: %c -> %c", ++d, A, C);
	else
	{
		A4(n - 1, A, C, B, d); // Buoc 1
		A4(1, A, B, C, d);	   // Buoc 2
		A4(n - 1, B, A, C, d); // Buoc 3
	}
}

void In(int a[], int n, int i)
{
	if (i == n - 1)
	{
		printf("%d  ", a[i]);
	}
	else
	{
		printf("%d  ", a[i++]);
		In(a, n, i);
	}
}

int Tong(int a[], int n)
{
	if (n == 0)
		return a[n];
	else
		return a[n] + (Tong(a, n - 1));
}