#include <stdio.h>
char strA[80] = "ABCDE";
char strB[80];
void main()
{
    char *pA;
    char *pB;
    puts(strA);
    pA = strA;
    puts(pA);
    pB = strB;
    putchar('\n');
    while(*pA != '\0')
    {
        *pB++ = *pA++;
    }
    *pB = '\0';
    puts(strB);
}