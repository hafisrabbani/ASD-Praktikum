#include <stdio.h>
void main()
{
    int my_array[] = {1,23,17,4,-5,100};
    int *ptr;
    int i;

    ptr = &my_array[0]; /* var pointer ptr menunjuk ke elemen ke-
    0 dari myarray */

    printf("\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("my_array[%d] = %d ",i,my_array[i]);
        printf("ptr + %d = %d\n",i, *(ptr + i));
    }
}