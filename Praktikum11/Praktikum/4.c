#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

struct Mahasiswa {
    int nrp;
    char nama[20];
    int kelas;
};

// 0 for ascending, 1 for descending
void BubbleSort(struct Mahasiswa arr[], int type) {
    int i, j;
    struct Mahasiswa temp;
    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - i - 1; j++) {
            if (type == 0) {
                if (arr[j].nrp > arr[j + 1].nrp) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            } else {
                if (arr[j].nrp < arr[j + 1].nrp) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

void BubbleSortFlag(struct Mahasiswa arr[], int type) {
    int i = 0, j;
    struct Mahasiswa temp;
    bool did_swap = true;
    while (i < MAX - 1 && did_swap) {
        did_swap = false;
        for (j = 0; j < MAX - i - 1; j++) {
            if (type == 0) {
                if (arr[j].nrp > arr[j + 1].nrp) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    did_swap = true;
                }
            } else {
                if (arr[j].nrp < arr[j + 1].nrp) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    did_swap = true;
                }
            }
        }
        i++;
    }
}

void ShellSort(struct Mahasiswa arr[], int type) {
    int i, j, k, n;
    struct Mahasiswa temp;
    for (i = MAX / 2; i > 0; i = i / 2) {
        for (j = i; j < MAX; j++) {
            temp = arr[j];
            for (k = j; k >= i && ((type == 0 && arr[k - i].nrp > temp.nrp) || (type == 1 && arr[k - i].nrp < temp.nrp)); k = k - i)
                arr[k] = arr[k - i];
            arr[k] = temp;
        }
    }
}

void main()
{
    struct Mahasiswa data[MAX], temp;
    int i, j, k, n;
    bool did_swap = true;
    printf("Masukkan jumlah data : ");
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        printf("Data ke-%d\n", i + 1);
        printf("NRP : ");
        scanf("%d", & data[i].nrp);
        printf("Nama : ");
        scanf("%s", & data[i].nama);
        printf("Kelas : ");
        scanf("%d", & data[i].kelas);
    }

    printf("\nPilih Algoritma : \n");
    printf("1. Bubble Sort\n");
    printf("2. Bubble Sort Flag\n");
    printf("3. Shell Sort\n");
    printf("Pilihan : ");
    scanf("%d", &k);
    printf("\nUrutkan dari : \n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan : ");
    scanf("%d", & j);

    switch (k) {
    case 1:
        BubbleSortByNrp(data, j - 1);
        break;
    case 2:
        BubbleSortFlagByNrp(data, j - 1);
        break;
    case 3:
        ShellSortByNrp(data, j - 1);
        break;
    default:
        printf("Pilihan tidak tersedia\n");
        break;
    }

    printf("\nHasil pengurutan : \n");
    for (i = 0; i < n; i++) {
        printf("%d %s %d\n", data[i].nrp, data[i].nama, data[i].kelas);
    }
}
