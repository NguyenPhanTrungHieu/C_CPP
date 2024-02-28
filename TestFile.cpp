#include <stdio.h>
int main()
{
    int x = 2;
    FILE *f = fopen("G1.txt" , "r");
    for(int i=0;i<13;i++){
        fscanf(f,"%d ", &x);
        printf("%d",x);
    }
}