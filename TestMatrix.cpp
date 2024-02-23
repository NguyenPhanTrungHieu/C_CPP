#include <stdio.h>

int **SET(int arr[][10], int m, int n);
void IN(int **M, int m, int n);
int **CMT(int **M1, int **M2, int m, int n);
int **NMT(int **M1, int **M2, int m, int n, int k);
int main()
{
    int a[10][10] = {{2, 2}, {2, 2}, {2, 2}}, b[10][10] = {{1, 1, 1}, {1, 1, 1}}, c[10][10] = {{1, 1, 1}, {1, 1, 1}};
    int **A = SET(a, 3, 2);
    int **B = SET(b, 2, 3);
    int **C = SET(c, 2, 3);
    IN(A, 3, 2);
    printf("\n");
    IN(B, 2, 3);
    printf("\n");
    IN(C, 2, 3);
    printf("\n");
    int **C2 = NMT(A, B, 3, 3, 2);
    IN(C2, 3, 3);
    printf("\n");
}

int **SET(int arr[][10], int m, int n)
{
    int **M = new int *[m];
    for (int i = 0; i < m; i++)
    {
        M[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            M[i][j] = arr[i][j];
        }
    }
    return M;
}

void IN(int **M, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", M[i][j]);
        }
        printf("\n");
    }
}

int **CMT(int **M1, int **M2, int m, int n)
{
    int **KQ = new int *[m];
    for (int i = 0; i < m; i++)
    {
        KQ[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            KQ[i][j] = M1[i][j] + M2[i][j];
        }
    }
    return KQ;
}

int **NMT(int **M1, int **M2, int m, int n, int k)
{
    int **KQ = new int *[m];
    for (int i = 0; i < m; i++)
    {
        KQ[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            int s = 0;
            for (int t = 0; t < k; t++)
            {
                s = s + (M1[i][t]*M2[t][j]);
            }
            KQ[i][j] = s;
        }
    }
    return KQ;
}
