#include <stdio.h>
#include <math.h>

void GIAO(int A[], int B[], int na, int nb);
int TUYEN(int a, int b);
int HOI(int a, int b);
int TUYENLOAI(int a, int b);
int KEOTHEO(int a, int b);
int TUONGDUONG(int a, int b);
float A1(int n);

int main()
{
	int n = 3;
	int na = 3, nb = 3;
	int A[3] = {1,2,3}, B[3] = {2,3,4};
	printf("\nBai 1: Giao cua 2 mang: ");
	GIAO(A,B,na,nb);
	printf("\nBai 2:");
	printf("\n a |\t b |\tavb|\ta^b|\ta@b|\ta->b|\ta<->b");
	printf("\n-------------------------------------------------------");
	printf("\n %d |\t %d |\t %d |\t %d |\t %d |\t %d |\t %d", 0, 1, TUYEN(0,1), HOI(0,1), TUYENLOAI(0,1), KEOTHEO(0,1), TUONGDUONG(0,1));
	printf("\nBai 3:");
	printf("\nDe Quy: %.3f ", A1(n));
	printf("\nCong Thuc Nghiem (CTTQ: an = 3^n) : %.3f", pow(3,n)); 
}

//Bai1
void GIAO(int A[], int B[], int na, int nb)
{
	for(int i=0;i<na;i++)
	{
		for(int j=0;j<nb;j++)
		{
			if(A[i]==B[j]) printf("%d  ",A[i]);
		}
	}
}

//Bai2
int TUYEN(int a, int b)
{
	return a|b;
}

int HOI(int a, int b)
{
	return a&b;
}

int TUYENLOAI(int a, int b)
{
	return a!=b;
}

int KEOTHEO(int a, int b)
{
	if(b==1) return 1;
	if(b==0)
	{
		if(a==0) return 1;
		else return 0;
	}
}

int TUONGDUONG(int a, int b)
{
	return a==b;
}

//Bai3
float A1(int n)
{
	if(n==0) return 1.0;
	else if(n==1) return 3.0;
	else return 2.0*A1(n-1) + 3.0*A1(n-2); 
}