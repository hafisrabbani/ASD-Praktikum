#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Data{
    char name[20];
    int jam;
    int menit;
    int detik;
    int total;
} data[100];

int countSecond(int jam, int menit, int detik)
{
    int total = 0;
    total += jam * 3600;
    total += menit * 60;
    total += detik;
    return total;
}


int bubbleSort(struct Data data[], int n)
{
    int i, j;
    struct Data temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (data[j].total > data[j + 1].total)
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int binarySearch(struct Data data[], int n, char name[])
{
    int i, j, mid;
    i = 0;
    j = n - 1;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (strcmp(data[mid].name, name) == 0)
        {
            return mid;
        }
        else if (strcmp(data[mid].name, name) < 0)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, i;
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Masukkan nama: ");
        scanf("%s", &data[i].name);
        printf("Masukkan jam: ");
        scanf("%d", &data[i].jam);
        printf("Masukkan menit: ");
        scanf("%d", &data[i].menit);
        printf("Masukkan detik: ");
        scanf("%d", &data[i].detik);
        data[i].total = countSecond(data[i].jam, data[i].menit, data[i].detik);
    }
    int menu;
    printf("Menu");
    printf("1. Cari berdasarkan nama");
    printf("2. Sorting");
    scanf("%d", &menu);

    if(menu == 1)
    {
        char name[20];
        printf("Masukkan nama yang dicari: ");
        scanf("%s", &name);
        int result = binarySearch(data, n, name);
        if (result == -1)
        {
            printf("Data tidak ditemukan\n");
        }
        else
        {
            printf("Data ditemukan pada indeks ke-%d\n", result);
            printf("%s %d %d %d %d\n", data[result].name, data[result].jam, data[result].menit, data[result].detik, data[result].total);
        }
    }
    else if(menu == 2)
    {
        bubbleSort(data, n);
        printf("Hasil sorting: \n");
        for (i = 0; i < n; i++)
        {
            printf("%s %d %d %d %d\n", data[i].name, data[i].jam, data[i].menit, data[i].detik, data[i].total);
        }
    }
    else
    {
        printf("Menu tidak tersedia\n");
    }
    return 0;   
}