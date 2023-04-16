#include<stdio.h>
#include<math.h>
int prime(int number, int index)
{
    if(index == 1)
        return 1;
    else if(number % index == 0)
        return 0;
    else
        return prime(number, --index);

}
void main()
{
    int num;
    printf("Masukkan bilangan sampai dengan : ");
    scanf("%d", &num);
    printf("Deret bilangan prima : ");
    for(int i=1;i<=num;i++)
        if(prime(i,(int)sqrt(i)))
        printf("%d ", i);

}