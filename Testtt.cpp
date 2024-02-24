#include <stdio.h>

void DeQuy(int n, int array[][n], int temp) {
    if (n != 0) {
        if (temp == 0) {
            DeQuy(n - 1, array, n); // Recur with the previous row
        } else {
            printf("%d ", array[n - 1][temp - 1]); // Print the element
            DeQuy(n, array, temp - 1); // Recur with the previous column
        }
    }
}

int main() {
    int n = 2;
    int Main[n][n]; 


    Main[0][0] = 1;
    Main[0][1] = 2;
    Main[1][0] = 3;
    Main[1][1] = 4;

    DeQuy(n, Main, n); 

    return 0;
}
