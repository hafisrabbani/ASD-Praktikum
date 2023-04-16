#include <stdio.h>
main()
{
    int y, x = 87; /* x & y bertipe int */
    int *px;
    /* var pointer yang menunjuk ke data yang bertipe int */
    x = 87;
    px = &x; /* px diisi dengan alamat dari variabel x */
    y = *px; /* y diisi dengan nilai yg ditunjuk oleh px */
    printf("Alamat x = %p\n", &x);
    printf("Isi px = %p\n", px);
    printf("Isi x = %d\n", x);
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    printf("Nilai y = %d\n", y);
}