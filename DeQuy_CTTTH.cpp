#include <stdio.h>
#include <math.h>

float A1(int n);
float A2(int n);
float A4(int n);

int main()
{
	int n = 4;
	printf("Bai 1:");
	printf("\nDe Quy: %.4f",A1(n));
	printf("\nCTTQ : %.4f ", pow(1.5,n) ); //CTTQ = (3/2)^n

	printf("\n\nBai 2:");
	printf("\nDe Quy: %.4f",A2(n));
	printf("\nCTTQ : %.4f ", (5.0 - 4.0*pow(0.5,n)) ); //CTTQ = 5 - 4*(1/2)^n

	printf("\n\nBai 3:");
	printf("\nDe Quy: Khong code duoc");
	printf("\nCTTQ : %.4f ", (2.0 + (0.666667)*n)*pow(1.5,n) ); //CTTQ = (2+(2/3)*n)*(3/2)^n

	printf("\n\nBai 4:");
	printf("\nDe Quy: %.4f",A4(n));
	printf("\nCTTQ : %.4f ", (-0.083334)*pow(-2,n) + (0.75)*pow(2,n) - (1.666667)) ; //CTTQ = (-1/12)*(-2)^n + (3/4)*2^n - 5/3
}

float A1(int n)
{
	if(n==0) return 1.0;
	else return A1(n-1)*1.5;
}

float A2(int n)
{
	if(n==0) return 1.0;
	else if(n==1) return 3.0;
	else return (3.0*A2(n-1)-A2(n-2))/2.0;
}

float A4(int n)
{
	if(n==0) return -1.0;
	else if(n==1) return 0;
	else if(n==2) return 1.0;
	else return A4(n-1)+4.0*A4(n-2)-4.0*A4(n-3);
}