#include <stdio.h>
int SoLonNhi(int a[], int n);
void Nhap(int a[], int &n);
int main()
{
    int a[10], n;
    Nhap(a, n);
    printf("Phan tu lon thu 2 trong mang: %d", SoLonNhi(a, n));
    return 0;
}
void Nhap(int a[], int &n)
{
    printf("Nhap vao n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int SoLonNhi(int a[], int n)
{
    // Cach 1

    // int max = a[0], max2 = a[0];
    // for (int i = 1; i < n; i++)
    // {
    //     if (a[i] > max)
    //     {
    //         max = a[i];
    //     }
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     if (a[i] > max2 && a[i] < max)
    //     {
    //         max2 = a[i];
    //     }
    // }
    // return max2;

    // Cach 2

    int max = a[0], max2 = NULL;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max2 = max;
            max = a[i];
        }
        else if (a[i] > max2)
        {
            max2 = a[i];
        }
    }
}