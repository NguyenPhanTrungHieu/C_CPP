#include <stdio.h>

int **SET(int arr[][10], int m, int n);
void IN(int **M, int m, int n);
int **CONG(int **M1, int **M2, int m, int n);
int **NHAN(int **M1, int **M2, int m, int n, int k);
int BANG(int **M1, int **M2, int m, int n);
int main()
{
    int m = 3, n = 3, k = 2;
    int a[10][10] = {{2, 2}, {2, 2}, {2, 2}}, b[10][10] = {{1, 1, 1}, {1, 1, 1}}, c[10][10] = {{1, 1, 1}, {1, 1, 1}};
    int **A = SET(a, m, k);
    int **B = SET(b, k, n);
    int **C = SET(c, k, n);
    int **C1 = CONG(NHAN(A, B, m, n, k), NHAN(A, C, m, n, k), m, n);
    int **C2 = NHAN(A, CONG(B, C, k, n), m, n, k);
    printf("A: \n");    IN(A, m, k);
    printf("B: \n");    IN(B, k, n);
    printf("C: \n");    IN(C, k, n);
    printf("(AB)+(AC): \n");    IN(C1, m, n);
    printf("A(B+C): \n");    IN(C2, m, n);
    printf("\nA(B+C) = (AB)+(AC) : %d", BANG(C1, C2, m, n));
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

int **CONG(int **M1, int **M2, int m, int n)
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

int **NHAN(int **M1, int **M2, int m, int n, int k)
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
                s = s + (M1[i][t] * M2[t][j]);
            }
            KQ[i][j] = s;
        }
    }
    return KQ;
}

int BANG(int **M1, int **M2, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M1[i][j] != M2[i][j])
                return 0;
        }
    }
    return 1;
}
