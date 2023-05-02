#include <stdio.h>
#include<time.h>
#define MAX 20

struct mhs
{
    int nrp;
    char nama[20];
};


void InsertionSortDesc(int data[MAX], int x){
    if(x<=1){return;}
    InsertionSortDesc(data, x-1);

    int key = data[x-1];
    int j = x-2;

    while (j>=0 && data[j] < key){
        data[j+1] = data[j];
        j--;
    }
    data[j+1] = key;
    
}
void InsertionSortAsc(int data[MAX], int x){
    if(x<=1){return;}
    InsertionSortAsc(data, x-1);

    int key = data[x-1];
    int j = x-2;

    while (j>=0 && data[j] > key){
        data[j+1] = data[j];
        j--;
    }
    data[j+1] = key;
    
}

void main()
{
    struct mhs mahasiswa[MAX];

    
    int pilih;
    do
    {
        printf("1. Tambah\n");
        printf("2. Urutkan Asc\n");
        printf("3. Urutkan Desc\n");
        printf("4. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);
        
    } while(pilih != 4 || pilih < 1 || pilih > 4);
    
}