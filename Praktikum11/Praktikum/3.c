#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define MAX 20
void ShellSort(int arr[]) {
    int i, jarak, temp;
    bool did_swap = true;
    jarak = MAX;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap) {
            did_swap = false;
            i = 0;
            while (i < (MAX - jarak)) {
                if (arr[i] < arr[i + jarak]) {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;

                }
                i++;
            }
        }
    }
}
void main() {
    int data_awal[MAX], data_urut[MAX];
    int i;
    long k1, k2;
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
    ShellSort(data_urut);
    time( & k2);
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1);
}