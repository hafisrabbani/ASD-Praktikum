#include <stdio.h>

void calculateMatrix(int matriks1[][100], int matriks2[][100], int size, int operation);

int main() {
    int size, operation;
    printf("Masukan ordo matriks: ");
    scanf("%d", &size);
    printf("Masukan operasi yang diinginkan: \n");
    printf("1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n");
    printf("Masukan Pilihan : ");
    scanf("%d", &operation);

    int matriks1[100][100], matriks2[100][100];
    printf("Masukan matriks 1: \n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &matriks1[i][j]);
        }
    }

    printf("Masukan matriks 2: \n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &matriks2[i][j]);
        }
    }

    calculateMatrix(matriks1, matriks2, size, operation);

    return 0;
}

void calculateMatrix(int matriks1[][100], int matriks2[][100], int size, int operation) {
    int result[100][100];

    if(operation == 1) { // Penjumlahan
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                result[i][j] = matriks1[i][j] + matriks2[i][j];
            }
        }
    } else if(operation == 2) { // Pengurangan
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                result[i][j] = matriks1[i][j] - matriks2[i][j];
            }
        }
    } else if(operation == 3) { // Perkalian
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                result[i][j] = 0;
                for(int k = 0; k < size; k++) {
                    result[i][j] += matriks1[i][k] * matriks2[k][j];
                }
            }
        }
    } else {
        printf("Operasi tidak ditemukan");
        return;
    }

    printf("Hasil operasi: \n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
