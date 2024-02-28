#include <stdio.h>
#include <stdlib.h>

void taoMaTran(int a[][100], int &n);
void inMaTran(int a[][100], int n, int m);
int DEG(int a[][100], int n, int v);

int main(){
	int n;
	int a[100][100];
	taoMaTran(a,n);
	inMaTran(a,n,n);
	printf("\n\n%d ",DEG(a,n,3));
}
void taoMaTran(int a[][100], int &n)
{
	FILE *f = fopen("G1.txt", "r");
	if(f == NULL){
		printf("Khong co file!!");
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++){
				fscanf(f,"%d",&a[i][j]);
			}
		}
	}
	fclose(f);
}
void inMaTran(int a[][100], int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int DEG(int a[][100], int n, int v)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(a[v][i]) sum++;
	}
	return sum;
}