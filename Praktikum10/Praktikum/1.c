#include <stdio.h>
#include<time.h>
#define MAX 20

void InsertionSort(int data[MAX], int x){
    if(x<=1){return;}
    InsertionSort(data, x-1);

    int key = data[x-1];
    int j = x-2;

    while (j>=0 && data[j] < key){
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
    printf("Urutkan : \n");
    InsertionSort(data_urut,MAX);
    // orderDesc(data_urut);
    for(i=0;i<MAX;i++){
        printf("%d ",data_urut[i]);
    }
}