#include <stdio.h>
#include <stdlib.h>
#define M 1000
#define N 5
void cetak(int Mat[N][N], char *judul)
{
  int i, j;
  printf("%s: \n", judul);
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      if (Mat[i][j] == M)
        printf("M ");
      else
        printf("%d ", Mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void warshall(int Q[N][N], int P[N][N], int R[N][N])
{
  int i, j, k;
  for (k = 0; k < N; k++)
  {
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        if (Q[i][k] + Q[k][j] < Q[i][j])
        {
          Q[i][j] = Q[i][k] + Q[k][j];
          if (R[k][j] == 0)
            R[i][j] = k + 1;
          else
            R[i][j] = R[k][j];
          P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
        }
      }
    }
  }
}
int main()
{
  int Q[N][N] = {M, 4, 2, M, M, M,
                 M, M, 1, 5, M, M,
                 M, M, M, 8, 10, M,
                 M, M, M, M, 2, 6,
                 M, M, M, M, M, 3,
                 M, M, M, M, M, M};
  int P[N][N] = {0, 1, 1, 0, 0, 0,
                 0, 0, 1, 1, 0, 0,
                 0, 0, 0, 1, 1, 0,
                 0, 0, 0, 0, 1, 1,
                 0, 0, 0, 0, 0, 1,
                 0, 0, 0, 0, 0, 0};
  int R[N][N] = {M, 0, 0, M, M, M,
                 M, M, 0, 0, M, M,
                 M, M, M, 0, 0, M,
                 M, M, M, M, 0, 0,
                 M, M, M, M, M, 0,
                 M, M, M, M, M, M};
  printf("Matriks sebelum Warshall\n");
  cetak(Q, "Beban");
  cetak(P, "Jalur");
  cetak(R, "Rute");
  warshall(Q, P, R);
  printf("Matriks setelah Warshall\n");
  cetak(Q, "Beban");
  cetak(P, "Jalur");
  cetak(R, "Rute");
  return 0;
}
