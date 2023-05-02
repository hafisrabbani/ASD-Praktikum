#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MAX 20
void BubbleSortFlag(int arr[]) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < MAX - 1 && did_swap) {
        for (j = 0; j < MAX - i - 1; j++) {
            did_swap = false;
            if (arr[j] < arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}
void main() {
    int data_awal[MAX], data_urut[MAX];
    int i;
    time_t k1, k2;
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time( & k1);
    BubbleSortFlag(data_urut);
    time( & k2);
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1);
}