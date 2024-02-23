#include <stdio.h>
static int MAX = 100;

void arrayCopy(int b[], int a[], int n);
void Nhap(int a[], int &n);
void In(int a[], int n);
int LonNhi(int a[], int n); //1
int TimNhiPhan(int a[], int n, int x); //2
void SapXepChen(int a[], int n); //3
void SapXepNhanh(int a[], int l, int r); //4


int main() {
    int n, x = 4;
    int a[MAX];
    Nhap(a, n);
    In(a, n);
    printf("\nPhan tu lon nhi la: %d\n", LonNhi(a, n));
    printf("\nVi tru cua %d trong mang : %d\n", x, TimNhiPhan(a, n, x));
    printf("\n");
    In(a, n);
}


void arrayCopy(int b[], int a[], int n) {
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
    int max = a[0], max2 = '\0';

    for (int i = 1; i < n; i++) { // Tim max
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (int i = 1; i < n; i++) {
        if ( (a[i] > max2) && (a[i] < max) ) {
            max2 = a[i];
        }
    }

    return max2;
}

void SapXepChen(int a[], int n) {
    int vitri, giatri;
    for (int i = 1; i < n; i++){
        vitri = i;
        giatri = a[i];
        while (vitri > 0 && a[vitri - 1] > giatri){
            a[vitri] = a[vitri - 1];
            vitri --;
        }
        a[vitri] = giatri;
    }
}

int TimNhiPhan(int a[],int n, int x) {
    int at[MAX];
    arrayCopy(at, a, n);
    SapXepChen(at,n); //Dung mang at de mang goc khong bi hong
    int l = 0, r = n-1;
    while (l < r){
        int mid = (l+r)/2;
        if (at[mid] < x){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    if (at[l] == x){
        return l;
    }
    return -1;
}

void SapXepNhanh(int a[], int l, int r)
{
    int p = a[(l+r)/2];
    int i = l, j = r;
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if (i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r){
        quickSort(a, i, r);
    }
    if (l < j){
        quickSort(a, l, j);
    }
}