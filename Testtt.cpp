#include <stdio.h>

void DeQuy(int n, int array[][n], int temp) {
    if (n != 0) {
        if (temp == 0) {
            DeQuy(n - 1, array, n); // Recur with the previous row
        } else {
            printf("%d ", array[n][temp - 1]); // Print the element
            DeQuy(n, array, temp - 1); // Recur with the previous column
        }
    }
}

int main() {
    int n = 2;
    int Main[n][n] = {{1, 2}, {3, 4}};

    DeQuy(n, Main, n); // Start recursion

    return 0;
}
