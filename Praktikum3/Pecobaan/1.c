#include <stdio.h>

#define MAX 10
typedef int Itemtype;
typedef struct {
  int item[MAX];
  int front;
  int rear;
  int count;
}
Queue;
void Inisialisasi(Queue * q) {
  q -> front = q -> rear = 0;
  q -> count = 0;
}
int Penuh(Queue * q) {
  return (q -> count == MAX);
}
int Kosong(Queue * q) {
  return (q -> count == 0);
}
void Tambah(Queue * q, int x) {
  if (Penuh == 1)
    printf("\nAntrian Penuh");
  else {
    q -> item[q -> rear] = x;
    q -> rear = (q -> rear + 1) % MAX;
    q -> count++;
  }
}
Itemtype Hapus(Queue * q) {
  Itemtype temp;
  if (Kosong(q) == 1)
    printf("Queue Kosong, tidak dapat mengambil data\n");
  else {
    temp = q -> item[q -> front];
    q -> front = (q -> front + 1) % MAX;
    q -> count--;
    return (temp);
  }
}
void Tampil(Queue * q) {
  int i, jml, tpl;
  jml = q -> count;
  tpl = q -> front;
  for (i = 0; i < jml; i++)
    printf("\nData : %d", q -> item[tpl++]);

}
int main() {
  Queue q;
  int data;
  Inisialisasi( & q);
  Tambah( & q, 11);
  Tambah( & q, 12);
  Tambah( & q, 13);
  Tambah( & q, 14);
  Tambah( & q, 15);
  Tambah( & q, 16);
  Tambah( & q, 17);
  Tambah( & q, 18);
  Tambah( & q, 19);
  Tambah( & q, 20);
  Tampil( & q);
  data = Hapus( & q);
  printf("\nHapus Item = %d ", data);
  data = Hapus( & q);
  printf("\nHapus Item = %d ", data);
  data = Hapus( & q);
  printf("\n Hapus Item = %d ", data);
  Tampil( & q);
}