#include <stdio.h>

int fibonacci(int x)
{
    return (x<=1) ? x : fibonacci(x-2)+fibonacci(x-1);
}


void main()
{
    int x,i;
    printf("Masukan jumlah deret : ");
    scanf("%d",&x);
    for(i=0;i<x;i++){
        printf("%d ",fibonacci(i));
    }
}