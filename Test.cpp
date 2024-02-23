#include <stdio.h>
static int MAX = 100;

int sizeOfArray(int a[]);
void arrayCopy(int a[], int n, int b[]);
void Nhap(int a[], int &n);
void In(int a[], int n);
int LonNhi(int a[], int n);
void SapXep(int a[], int n);
int TimNhiPhan(int a[], int l, int r, int x);

int main() {
	int n, x = 4;
	int a[MAX];
	Nhap(a, n);
	printf("\nSo phan tu trong mang: %d\n",sizeOfArray(a));
	In(a, n);
	printf("\nPhan tu lon nhi la: %d", LonNhi(a, n));
	printf("\nVi tru cua %d trong mang : %d", x, TimNhiPhan(a, 0, n - 1, x));
	printf("\n");
	In(a, n);
}

int sizeOfArray(int a[]) {
	int i=0;
	while(a[i]!=NULL)
	{
		if(a[i]==NULL) break;
		i++;
	}
	return i;
}

void arrayCopy(int a[], int n, int b[]) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

void Nhap(int a[], int &n) {
	printf("Nhap vao so luong phan tu: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void In(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}

int LonNhi(int a[], int n) {
	int max = a[0], max2 = a[0];
	for (int i = 1; i < n; i++) { // Tim max
		if (a[i] > max) {
			max = a[i];
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] > max2 && a[i] < max) {
			max2 = a[i];
		}
	}
	return max2;
}

void SapXep(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

int TimNhiPhan(int a[], int l, int r, int x) {
	int at[MAX];
	arrayCopy(a, sizeOfArray(a), at);
	while (l <= r) {
		int mid = (l + r) / 2;
		if (at[mid] == x)
			return mid;
		if (x < at[mid])
			r = mid - 1;
		else if (x > at[mid])
			l = mid + 1;
	}
	return -1;
}