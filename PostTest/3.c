#include <stdio.h>
#include <stdlib.h>
#define M 100
#define SIZE 6

struct stack
{
    int data[SIZE];
    int top;
} s;

void warshall(int Q[SIZE][SIZE], int P[SIZE][SIZE], int R[SIZE][SIZE])
{
    for (int k = 0; k < SIZE; k++)
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
            {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j])
                {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[k][j] == 0)
                        R[i][j] = k + 1;
                    else
                        R[i][j] = R[k][j];
                }
            }
}

void tampil(int data[SIZE][SIZE], char *judul)
{
    printf("%s = \n", judul);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            if (data[i][j] >= M)
                printf("M ");
            else
                printf("%d ", data[i][j]);
        printf("\n");
    }
}

void tampilRute(int Q[SIZE], int P[SIZE][SIZE], int R[SIZE][SIZE], int start, int end)
{
    int i = start;
    int j = end;
    int k = R[i][j] - 1;
    int count = 0;
    s.top = -1;
    s.data[++s.top] = j + 1;
    while (k != 0)
    {
        s.data[++s.top] = k + 1;
        k = R[i][k] - 1;
    }
    s.data[++s.top] = i + 1;
    printf("Rute terpendek dari %d ke %d adalah: ", start + 1, end + 1);
    while (s.top != -1)
    {
        printf("%d", s.data[s.top--]);
        if (s.top != -1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main()
{

    int beban[SIZE][SIZE] = {
        M,3,7,8,M,M,
        3,M,4,5,2,M,
        7,4,M,M,6,6,
        8,5,M,M,1,10,
        M,2,6,M,M,3,
        M,M,6,10,3,M
    };

    int rute[SIZE][SIZE] = {
        0,1,1,1,0,0,
        1,0,1,1,1,0,
        1,1,0,0,1,1,
        1,1,0,0,1,1,
        0,1,1,0,0,1,
        0,0,1,1,1,0
    };

    int jalur[SIZE][SIZE] = {
        0,3,7,8,0,0,
        3,0,4,5,2,0,
        7,4,0,0,6,6,
        8,5,0,0,1,1,
        0,2,6,0,0,3,
        0,0,6,10,3,0
    };

    tampil(beban, "Beban Sebelum Algoritma Warshall");
    tampil(jalur, "Jalur Sebelum Algoritma Warshall");
    tampil(rute, "Rute Sebelum Algoritma Warshall");

    warshall(beban, jalur, rute);
    printf("\n");
    tampil(beban, "Beban Setelah Algoritma Warshall");
    tampil(jalur, "Jalur Setelah Algoritma Warshall");
    tampil(rute, "Rute Setelah Algoritma Warshall");

    int start, end;
    printf("\n");
    printf("Masukkan titik awal: ");
    scanf("%d", &start);
    printf("Masukkan titik akhir: ");
    scanf("%d", &end);
    tampilRute(beban[start - 1], jalur, rute, start - 1, end - 1);
   return 0;
}