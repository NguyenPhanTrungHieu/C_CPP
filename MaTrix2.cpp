#include <stdio.h>
#include <stdlib.h>

void IN(int **M, int m, int n);
int **SET(int m, int n, int x);
int **MT(int **M, int m, int n);

int main()
{
    int **A, **At, m = 3, n = 2;
    A = SET(m, n, 2);
    IN(A, m, n);
    At = MT(A, m, n);
    printf("\n");
    IN(At, n, m);
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
int **SET(int m, int n, int x)
{
    int **C = new int *[m];
    for (int i = 0; i < m; i++)
    {
        C[i] = new int[n];
        for (int j = 0; j < n; j++)
            C[i][j] = rand() % x;
    }
    return C;
}
int **MT(int **M, int m, int n)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            C[i][j] = M[j][i];
        }
    }
    return C;
}