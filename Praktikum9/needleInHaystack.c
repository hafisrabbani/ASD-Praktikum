#include <stdio.h>

int findIndex(int needle, int haystack[], int size){
    if(needle==haystack[size]){
        return size;
    }else{
        findIndex(needle,haystack,size-1);
    }
}

void main()
{
    int arr[5],i;
    for(i=0;i<5;i++){printf("Masukkan angka: ");scanf("%d",&arr[i]);}
    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d",&i);
    printf((findIndex(i,arr,4)>0) ? "Ditemukan pada index %d:":"Tidak ditemukan",findIndex(i,arr,4));
}