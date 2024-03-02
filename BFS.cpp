#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void taoMaTran(int array[][100], int &n);
void inMaTran(int array[][100], int n, int m);
void BFS(int array[][100], int n, int u);

int main()
{
    int array[100][100], n;
    taoMaTran(array, n);
    inMaTran(array, n, n);
    BFS(array,n,0);
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

void BFS(int array[][100], int n, int u)
{
    queue<int> q;
    int chuaXet[n] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    q.push(u);
    chuaXet[u] = 0;
    while (!q.empty())
    {
        int p = q.front();
        cout << p + 1 << " ";
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (array[p][v] == 1 && chuaXet[v] == 1)
            {
                q.push(v);
                chuaXet[v] = 0;
            }
        }
    }
}