#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nrp[10];
    char nama[50];
    int kelas;
};

void bubbleSort(struct Mahasiswa arr[], int n) {
    int i, j;
    struct Mahasiswa temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j].nrp, arr[j+1].nrp) > 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortFlag(struct Mahasiswa arr[], int n) {
    int i, j, flag = 1;
    struct Mahasiswa temp;
    for (i = 0; i < n-1 && flag; i++) {
        flag = 0;
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j].nrp, arr[j+1].nrp) > 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
    }
}

void shellSort(struct Mahasiswa arr[], int n) {
    int gap, i, j;
    struct Mahasiswa temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && strcmp(arr[j-gap].nrp, temp.nrp) > 0; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    struct Mahasiswa arr[5];
    int i, n;
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Masukkan data ke-%d\n", i+1);
        printf("NRP: ");
        scanf("%s", arr[i].nrp);
        printf("Nama: ");
        scanf("%s", arr[i].nama);
        printf("Kelas: ");
        scanf("%d", &arr[i].kelas);
    }


    // Pengurutan dengan bubble sort
    bubbleSort(arr, n);
    printf("Setelah pengurutan:\n\n");
    printf("Bubble Sort:\n");

    for (i = 0; i < n; i++) {
        printf("%s %s %d\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
    }
    // Pengurutan dengan bubble sort dengan flag
    printf("\nBubble Sort dengan flag:\n");
    bubbleSortFlag(arr, n);
    for (i = 0; i < n; i++) {
        printf("%s %s %d\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
    }
    // Pengurutan dengan shell sort
    printf("\nShell Sort:\n");
    shellSort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%s %s %d\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
    }
    return 0;
}
