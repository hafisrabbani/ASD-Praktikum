#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void SelectionSortDesc(int data[]){
    char op = '>';
    for(int i = 0; i < MAX - 1; i++){
        int max_index = i;
        for(int j = i+1;j<MAX;j++){
            if(data[j] > data[max_index]){
                max_index = j;
            }
        }
        swap(&data[max_index], &data[i]);
    }
}
void SelectionSortAsc(int data[]){
    char op = '>';
    for(int i = 0; i < MAX - 1; i++){
        int min_index = i;
        for(int j = i+1;j<MAX;j++){
            if(data[j] < data[min_index]){
                min_index = j;
            }
        }
        swap(&data[min_index], &data[i]);
    }
}

void main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    time_t k1, k2;
    printf("Sebelum pengurutan : \n");
    for(i=0; i<MAX; i++){
        srand(time(NULL) * (i+1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan : \n");
    for(i=0; i<MAX; i++)
        data_urut[i] = data_awal[i];

    int pil;
    printf("Masukan Pilihan : \n1.Ascending\n2.Descending\npilih : ");
    scanf("%d",&pil);
    time(&k1);
    (pil==1)?SelectionSortAsc(data_urut) : SelectionSortDesc(data_urut);
    time(&k2);
    for(i=0; i<MAX; i++)
        printf("%d ", data_urut[i]);
    
    printf("\nWaktu = %ld\n", k2-k1);
}