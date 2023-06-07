#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define ASC 0
#define DESC 1
int PartitionAsc(int arr[], int p, int r)
{
   int pivot, temp;
   pivot = arr[p];
   while (p <= r)
   {
      while (pivot < arr[r])
         r--;
      while (pivot > arr[p])
         p++;
      if (p < r)
      {
         temp = arr[p];
         arr[p] = arr[r];
         arr[r] = temp;
         r--;
         p++;
      }
      else
         return r;
   }
   return r;
}
int PartitionDesc(int arr[], int p, int r)
{
   int pivot, temp;
   pivot = arr[p];
   while (p <= r)
   {
      while (pivot > arr[r])
         r--;
      while (pivot < arr[p])
         p++;
      if (p < r)
      {
         temp = arr[p];
         arr[p] = arr[r];
         arr[r] = temp;
         r--;
         p++;
      }
      else
         return r;
   }
   return r;
}
void QuickSort(int arr[], int p, int r, int con)
{
   int q;
   if (p < r)
   {
      if (con == ASC)
         q = PartitionAsc(arr, p, r);
      else
         q = PartitionDesc(arr, p, r);
      QuickSort(arr, p, q, con);
      QuickSort(arr, q + 1, r, con);
   }
}
void main()
{
   int data_awal[MAX], data_urut[MAX];
   int i;
   time_t k1, k2;
   printf("Sebelum pengurutan : \n");
   for (i = 0; i < MAX; i++)
   {
      srand(time(NULL) * (i + 1));
      data_awal[i] = rand() % 100 + 1;
      printf("%d ", data_awal[i]);
   }
   printf("\n\nSetelah pengurutan Ascending: \n");
   for (i = 0; i < MAX; i++)
      data_urut[i] = data_awal[i];
   time(&k1);
   QuickSort(data_urut, 0, MAX - 1, ASC);
   time(&k2);
   for (i = 0; i < MAX; i++)
      printf("%d ", data_urut[i]);
   printf("\nWaktu = %ld\n", k2 - k1);
   printf("\nSetelah pengurutan Descending: \n");
   for (i = 0; i < MAX; i++)
      data_urut[i] = data_awal[i];
   time(&k1);
   QuickSort(data_urut, 0, MAX - 1, DESC);
   time(&k2);
   for (i = 0; i < MAX; i++)
      printf("%d ", data_urut[i]);
   printf("\nWaktu = %ld\n\n", k2 - k1);
}
