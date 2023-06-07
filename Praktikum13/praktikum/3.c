#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 1000

void Tampil(int data[N][N], char *judul)
{
  printf("%s = \n", judul);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      if (data[i][j] >= M)
        printf("M ");
      else
        printf("%d ", data[i][j]);
    printf("\n");
  }
}

void Warshall(int Q[N][N], int P[N][N], int R[N][N])
{
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
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

int main()
{
  int Beban[N][N] = {M, 1, 2, M, M,
                     M, M, 5, M, M,
                     M, M, M, 3, M,
                     M, M, M, M, 4,
                     M, M, M, M, M};
  int Jalur[N][N] = {0, 1, 1, 0, 0,
                     0, 0, 1, 0, 0,
                     0, 0, 0, 1, 0,
                     0, 0, 0, 0, 1,
                     0, 0, 0, 0, 0};
  int Rute[N][N] = {M, 0, 0, M, M,
                    M, M, 0, M, M,
                    M, M, M, 0, M,
                    M, M, M, M, 0,
                    M, M, M, M, M};
  Tampil(Beban, "Beban Sebelum Algoritma Warshall");
  Tampil(Jalur, "Jalur Sebelum Algoritma Warshall");
  Tampil(Rute, "Rute Sebelum Algoritma Warshall");

  Warshall(Beban, Jalur, Rute);
  printf("\nMatriks setelah Algoritma Warshall : \n");
  Tampil(Beban, "Beban Setelah Algoritma Warshall");
  Tampil(Jalur, "Jalur Setelah Algoritma Warshall");
  Tampil(Rute, "Rute Setelah Algoritma Warshall");

  return 0;
}
