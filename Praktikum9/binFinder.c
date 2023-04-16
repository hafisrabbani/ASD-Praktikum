#include <stdio.h>
#include <string.h>
#define MAX 100

int findNum(int num, int arr[]){
    int i=0;
    if(num==arr[i]){
        return i;
    }else{
        i++;
        return findNum(num,arr);
    }
}

void main()
{
    int num[MAX],i=0,find;
    char lanjut;
    do{
        printf("Masukkan angka: ");
        scanf("%d",&num[i]);
        printf("Apakah anda ingin memasukkan lagi? (y/n) ");
        scanf(" %c",&lanjut);
        i++;
    }while(lanjut=='y' || lanjut=='Y');

    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d",&find);
    printf("Angka %d berada di indeks ke-%d",find,findNum(find,num));
    
}