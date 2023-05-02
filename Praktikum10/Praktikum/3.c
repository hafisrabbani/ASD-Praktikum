#include <stdio.h>
#include<time.h>
#define MAX 20

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
    int data_awal[MAX], data_urut[MAX];
    int i;
    printf("Sebelum pengurutan : \n");
    for(i=0; i<MAX; i++){
        srand(time(NULL) * (i+1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\n");
    for(i=0; i<MAX; i++){
        data_urut[i] = data_awal[i];
    }
    
    int pil;
    printf("Masukan Pilihan : \n1.Ascending\n2.Descending\npilih : ");
    scanf("%d",&pil);
    (pil==1)?InsertionSortAsc(data_urut,MAX) : InsertionSortDesc(data_urut,MAX);

    for(i=0;i<MAX;i++){
        printf("%d ",data_urut[i]);
    }
}