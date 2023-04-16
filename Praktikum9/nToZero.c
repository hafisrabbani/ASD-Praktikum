#include <stdio.h>
int nToZero(int n){ (n<0) ? 0 : nToZero(n-1) && printf("%d ",n); }
void main(){int n;printf("Masukkan angka: ");scanf("%d",&n);nToZero(n);}