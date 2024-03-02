#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void taoMaTran(int array[][100], int &n);
void inMaTran(int array[][100], int n, int m);
void DFS(int array[][100], int n, int u);
int chuaXet[13] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
int main()
{
    int array[100][100], n;
    taoMaTran(array, n);
    inMaTran(array, n, n);
    DFS(array, n, 0);
}

void taoMaTran(int array[][100], int &n)
{
    ifstream fi;
    fi.open("G1.txt");
    if (!fi.eof())
    {
        fi >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fi >> array[i][j];
            }
        }
    }
    else
    {
        cout << "FILE KHONG TON TAI!!";
    }
    fi.close();
}

void inMaTran(int array[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int array[][100], int n, int u)
{
    cout<<u+1<<" ";
    chuaXet[u] = 0;
    for (int v = 0; v < n; v++)
    {
        if ((array[u][v] == 1) && (chuaXet[v] == 1))
        {
            DFS(array, n, v);
        }
    }
}

