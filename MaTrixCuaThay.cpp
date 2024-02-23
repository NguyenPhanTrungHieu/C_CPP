#include <stdio.h>
#include <stdlib.h>

int **TAO(int m, int n, int x); // ** la tra ve ma tran
void IN(int **A, int m, int n);
int **CONG(int **A, int **B, int m, int n);
int **NHAN(int **A, int **B, int m, int n, int k);
int TEST(int **A, int **B, int m, int n);

int main() {
	int **A, **B, **C, **C1, **C2, m=3, k=2, n=3;
	A=TAO(m,k,5); B=TAO(k,n,7); C=TAO(k,n,9);
	printf("A:\n"); IN(A,m,k);
	printf("b:\n"); IN(B,k,n);
	printf("c:\n"); IN(C,k,n);
	C1=CONG(NHAN(A,B,m,n,k),NHAN(A,C,m,n,k),m,n); 
	printf("(AB)+(AC):\n"); IN(C1,m,n);
	C2=NHAN(A,CONG(B,C,k,n),m,n,k); 
	printf("A(B+C):\n"); IN(C2,m,n);
	printf("A(B+C) = (AB)+(AC): %d",TEST(C1,C2,m,n));
}

int **TAO(int m, int n, int x) {
	int **C=new int*[m];
	for (int i=0; i<m; i++) {
		C[i]= new int[n];
		for (int j=0; j<n; j++) C[i][j]=rand() % x;
	}
	return C;
}
void IN(int **A, int m, int n) {
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) printf("%6d",A[i][j]);
		printf("\n");
	}
}
int **CONG(int **A, int **B, int m, int n) {
	int **C=new int*[m];
	for (int i=0; i<m; i++) {
		C[i]= new int[n];
		for (int j=0; j<n; j++) C[i][j]= A[i][j]+B[i][j];
	}
	return C;
}
int **NHAN(int **A, int **B, int m, int n, int k) {
	int **C=new int*[m];
	for (int i=0; i<m; i++) {
		C[i]= new int[n];
		for (int j=0; j<n; j++) {
			C[i][j]=0;
			for (int t=0; t<k; t++) C[i][j]+= A[i][t]*B[t][j];
		}
	}
	return C;
}
int TEST(int **A, int **B, int m, int n) {
	int kt=1;
	for (int i=0; i<m && kt==1; i++) {
		for (int j=0; j<n && kt==1; j++) 
			if (A[i][j]!=B[i][j]) kt=0;
	}
	return kt;		
}


