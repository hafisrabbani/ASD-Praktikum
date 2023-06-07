#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 1000


typedef struct{
    int Data[N]; 
    int top;
} Graph;

void initGraph(Graph *G){
    G->top = -1;
}

void push(Graph *G, int data){
    G->top++;
    G->Data[G->top] = data;
}

int pop(Graph *G){
    int temp = G->Data[G->top];
    G->top--;
    return temp;
}


int isEmpty(Graph *G){
    if(G->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Graph *G){
    if(G->top == N-1){
        return 1;
    }else{
        return 0;
    }
}


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


void findRoute(int R[N][N], int Beban[N][N], int start, int end){
    printf("Beban dari %d ke %d adalah : %d\n", start, end, Beban[start-1][end-1]);
    Graph G;
    initGraph(&G);
    push(&G, end);
    int temp = R[start-1][end-1];
    while(temp != 0){
        push(&G, temp);
        temp = R[start-1][temp-1];
    }
    push(&G, start);
    printf("Rute : ");
    while(!isEmpty(&G)){
        printf("%d ", pop(&G));
    }
    printf("\n");
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
  Warshall(Beban, Jalur, Rute);
  printf("Matriks setelah Algoritma Warshall : \n");
  Tampil(Beban, "Beban");
  Tampil(Jalur, "Jalur");
  Tampil(Rute, "Rute");

    findRoute(Rute, Beban, 1, 5);
}
