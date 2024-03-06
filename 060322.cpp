#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void taoMaTran(int array[][100], int &n);
void inMaTran(int array[][100], int n, int m);
// void DFS(int array[][100], int n, int u);
// int chuaXet[13] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
int demBacLe(int array[][100], int n);
int loaiDoThi(int array[][100], int n);
int main()
{
    int array[100][100], n;
    taoMaTran(array, n);
    inMaTran(array, n, n);
    cout<<"So bac le cua ma tran la: "<<demBacLe(array,n);
    // DFS(array, n, 0);
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

int demBacLe(int array[][100], int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int tempCount = 0;
        for(int j=0;j<n;j++)
        {
            if(array[i][j] == 1) tempCount++;
        }
        if(tempCount%2==1) count++;
    }
    return count;
}

int loaiDoThi(int array[][100], int n)
{
    int Stack[100], CE[100];
}