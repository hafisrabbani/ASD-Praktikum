#include <stdio.h>
int zeroToN(int n){(n<0) ? 0 : printf("%d ",n) && zeroToN(n-1);}
void main(){int n;printf("Masukkan angka: ");scanf("%d",&n);zeroToN(n);}
