#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20
void BubbleSort(int arr[])
{
    int i, j, temp;
        for(i=0; i<MAX-1; i++){
        for(j=0; j<MAX-i-1; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]= temp;

            }
        }
    }
}

void main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    long k1, k2;
    printf("Sebelum pengurutan : \n");
    for(i=0; i<MAX; i++){
        srand(time(NULL) * (i+1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan : \n");
    for(i=0; i<MAX; i++)
        data_urut[i] = data_awal[i];
    time(&k1);
    BubbleSort(data_urut);
    time(&k2);
    for(i=0; i<MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2-k1);
}