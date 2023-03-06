#include <stdio.h>

void main()
{
    int count = 10,*temp,sum=7;

    temp = &count;
    *temp = 32;
    temp = &sum;
    *temp = count;
    sum = *temp*4;

    printf("coun = %d, temp = %d, sum = %d\n",count,*temp,sum);

}

// pseudocode
