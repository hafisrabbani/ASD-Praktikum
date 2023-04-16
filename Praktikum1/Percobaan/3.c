#include<stdio.h>
#define MAX 20
int fibo[MAX];
void main()
{
    int i;
    fibo[1] = 1;
    fibo[2] = 1;
    for (i=3;i<=MAX;i++)
        fibo[i]=fibo[i-2]+fibo[i-1];
        printf("%d Bilangan Fibonaci Pertama adalah : \n",MAX);
    for (i=1;i<MAX;i++)
        printf("%d",fibo[i]);
}