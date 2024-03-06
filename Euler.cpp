#include <bits/stdc++.h>
using namespace std;

void taoMaTran(int array[][100], int &n);
void inMaTran(int array[][100], int n, int m);
int demBacLe(int array[][100], int n);
int loaiDoThi(int array[][100], int n);
// void eulerCircle(int array[][100], int n )
int main()
{
    int array[100][100], n;
    taoMaTran(array, n);
    inMaTran(array, n, n);
    cout << "So bac le cua ma tran la: " << demBacLe(array, n);
    if (loaiDoThi(array, n) == 1)
        cout << "\nLa Euler";
    else if (loaiDoThi(array, n) == 0.5)
        cout << "\nLa 1/2 Euler";
    else if (loaiDoThi(array, n) == 0)
        cout << "\nKhong phai Euler";
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
    for (int i = 0; i < n; i++)
    {
        int tempCount = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] == 1)
                tempCount++;
        }
        if (tempCount % 2 == 1)
            count++;
    }
    return count;
}

int loaiDoThi(int array[][100], int n)
{
    if (demBacLe(array, n) % 2 == 0)
        return 1;
    if (demBacLe(array, n) > 2)
        return 0;
    else
        return 0.5;
}