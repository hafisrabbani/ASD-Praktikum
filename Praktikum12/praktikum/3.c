#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <string.h>
#define ASC 0
#define DESC 1
#define jumlahMahasiswa 20
#define MAX 5
typedef struct Mahasiswa
{
   char nrp[15];
   char nama[100];
   int kelas;
} Mahasiswa;
struct Mahasiswa DataAcak[jumlahMahasiswa] = {
    {"412359", "Budi", 1},
    {"412352", "Siti", 1},
    {"412350", "Susi", 1},
    {"412355", "Wawan", 1},
    {"412353", "Sari", 1}};
int PartitionAsc(Mahasiswa *read, int p, int r)
{
   Mahasiswa pivot = read[p];
   while (p <= r)
   {
      while (strcmp(read[r].nrp, pivot.nrp) > 0)
         r--;
      while (strcmp(read[p].nrp, pivot.nrp) < 0)
         p++;
      if (p < r)
      {
         Mahasiswa temp = read[p];
         read[p] = read[r];
         read[r] = temp;
         r--;
         p++;
      }
      else
         return r;
   }
   return r;
}
int PartitionDesc(Mahasiswa *read, int p, int r)
{
   Mahasiswa pivot = read[p];
   while (p <= r)
   {
      while (strcmp(read[r].nrp, pivot.nrp) < 0)
         r--;
      while (strcmp(read[p].nrp, pivot.nrp) > 0)
         p++;
      if (p < r)
      {
         Mahasiswa temp = read[p];
         read[p] = read[r];
         read[r] = temp;
         r--;
         p++;
      }
      else
         return r;
   }
   return r;
}
void QuickSort(Mahasiswa *read, int p, int r, int con)
{
   int q;
   if (p < r)
   {
      if (con == ASC)
         q = PartitionAsc(read, p, r);
      else
         q = PartitionDesc(read, p, r);
      QuickSort(read, p, q, con);
      QuickSort(read, q + 1, r, con);
   }
}
void MergeAsc(Mahasiswa *arr, int left, int median, int right)
{
   Mahasiswa temp[MAX];
   int kiri1, kanan1, kiri2, kanan2, i, j;
   kiri1 = left;
   kanan1 = median;
   kiri2 = median + 1;
   kanan2 = right;
   i = left;
   while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
   {
      if (strcmp(arr[kiri1].nrp, arr[kiri2].nrp) < 0)
      {
         temp[i] = arr[kiri1];
         kiri1++;
      }
      else
      {
         temp[i] = arr[kiri2];
         kiri2++;
      }
      i++;
   }
   while (kiri1 <= kanan1)
   {
      temp[i] = arr[kiri1];
      kiri1++;
      i++;
   }
   while (kiri2 <= kanan2)
   {
      temp[i] = arr[kiri2];
      kiri2++;
      i++;
   }
   j = left;
   while (j <= right)
   {
      arr[j] = temp[j];
      j++;
   }
}
void MergeDesc(Mahasiswa *arr, int left, int median, int right)
{
   Mahasiswa temp[MAX];
   int kiri1, kanan1, kiri2, kanan2, i, j;
   kiri1 = left;
   kanan1 = median;
   kiri2 = median + 1;
   kanan2 = right;
   i = left;
   while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
   {
      if (strcmp(arr[kiri1].nrp, arr[kiri2].nrp) > 0)
      {
         temp[i] = arr[kiri1];
         kiri1++;
      }
      else
      {
         temp[i] = arr[kiri2];
         kiri2++;
      }
      i++;
   }
   while (kiri1 <= kanan1)
   {
      temp[i] = arr[kiri1];
      kiri1++;
      i++;
   }
   while (kiri2 <= kanan2)
   {
      temp[i] = arr[kiri2];
      kiri2++;
      i++;
   }
   j = left;
   while (j <= right)
   {
      arr[j] = temp[j];
      j++;
   }
}
void MergeSort(Mahasiswa *arr, int l, int r, int con)
{
   int med;
   if (l < r)
   {
      med = (l + r) / 2;
      MergeSort(arr, l, med, con);
      MergeSort(arr, med + 1, r, con);
      if (con == ASC)
         MergeAsc(arr, l, med, r);
      else
         MergeDesc(arr, l, med, r);
   }
}
void main()
{
   Mahasiswa mhs[MAX];
   for (int a = 0; a < MAX; a++)
      mhs[a] = DataAcak[a];
   printf("\nData Sebelum urut :\n");
   for (int a = 0; a < MAX; a++)
   {
      printf("%s %s \n", mhs[a].nrp, mhs[a].nama);
   }
   for (int a = 0; a < MAX; a++)
      mhs[a] = DataAcak[a];
   QuickSort(mhs, 0, MAX - 1, ASC);
   printf("\n\nSetelah pengurutan QuickSort Ascending : \n");
   for (int a = 0; a < MAX; a++)
   {
      printf("%s %s \n", mhs[a].nrp, mhs[a].nama);
   }
   for (int a = 0; a < MAX; a++)
      mhs[a] = DataAcak[a];
   QuickSort(mhs, 0, MAX - 1, DESC);
   printf("\n\nSetelah pengurutan QuickSort Descending : \n");
   for (int a = 0; a < MAX; a++)
   {
      printf("%s %s \n", mhs[a].nrp, mhs[a].nama);
   }
   for (int a = 0; a < MAX; a++)
      mhs[a] = DataAcak[a];
   MergeSort(mhs, 0, MAX - 1, ASC);
   printf("\n\nSetelah pengurutan MergeSort Ascending: \n");
   for (int a = 0; a < MAX; a++)
   {
      printf("%s %s \n", mhs[a].nrp, mhs[a].nama);
   }
   for (int a = 0; a < MAX; a++)
      mhs[a] = DataAcak[a];
   MergeSort(mhs, 0, MAX - 1, DESC);
   printf("\n\nSetelah pengurutan MergeSort Descending: \n");
   for (int a = 0; a < MAX; a++)
   {
      printf("%s %s \n", mhs[a].nrp, mhs[a].nama);
   }
}
