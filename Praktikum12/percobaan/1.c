#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
int Partition(int arr[], int p, int r)
{
   int i, j;
   int pivot, temp;
   pivot = arr[p];
   i = p;
   j = r;
   while (i <= j)
   {
      while (pivot < arr[j])
         j--;
      while (pivot > arr[i])
         i++;
      if (i < j)
      {
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         j--;
         i++;
      }
      else
         return j;
   }
   return j;
}
void QuickSort(int arr[], int p, int r)
{
   int q;
   if (p < r)
   {
      q = Partition(arr, p, r);
      QuickSort(arr, p, q);
      QuickSort(arr, q + 1, r);
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
   printf("\nSetelah pengurutan : \n");
   for (i = 0; i < MAX; i++)
      data_urut[i] = data_awal[i];
   time(&k1);
   QuickSort(data_urut, 0, MAX - 1);
   time(&k2);
   for (i = 0; i < MAX; i++)
      printf("%d ", data_urut[i]);
   printf("\nWaktu = %ld\n", k2 - k1);
}
