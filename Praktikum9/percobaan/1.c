#include<stdio.h>
int faktorial(int x)
{
    if(x==1)
        return x;
    else
        return x * faktorial(x-1);
}
void main()
{
    int N;
    printf("Masukkan N = ");
    scanf("%d", &N);
    printf("Hasil %d! = %d\n", N, faktorial(N));
}