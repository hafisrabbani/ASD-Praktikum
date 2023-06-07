#include <stdio.h>
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
void main()
{
  int Beban[N][N] = {M, 1, 3, M, M,
                     M, M, 1, M, 5,
                     3, M, M, 2, M,
                     M, M, M, M, 1,
                     M, M, M, M, M};
  int Jalur[N][N] = {0, 1, 1, 0, 0,
                     0, 0, 1, 0, 1,
                     1, 0, 0, 1, 0,
                     0, 0, 0, 0, 1,
                     0, 0, 0, 0, 0};
  int Rute[N][N] = {M, 0, 0, M, M,
                    M, M, 0, M, 0,
                    0, M, M, 0, M,
                    M, M, M, M, 0,
                    M, M, M, M, M};
  Tampil(Beban, "Beban");
  Tampil(Jalur, "Jalur");
  Tampil(Rute, "Rute");
}
