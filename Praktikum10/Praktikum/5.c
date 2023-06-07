#include <stdio.h>
#include<time.h>
#define MAX 20

struct mhs
{
    int nrp;
    char nama[20];
};

int data[MAX];
int count = 0;

void InsertionSortDesc(int data[MAX], int x){
    if(x<=1){return;}
    InsertionSortDesc(data, x-1);

    int key = data[x-1];
    int j = x-2;

    while (j>=0 && data[j] < key){
        data[j+1] = data[j];
        j--;
    }
    data[j+1] = key;
    
}
void InsertionSortAsc(int data[MAX], int x){
    if(x<=1){return;}
    InsertionSortAsc(data, x-1);

    int key = data[x-1];
    int j = x-2;

    while (j>=0 && data[j] > key){
        data[j+1] = data[j];
        j--;
    }
    data[j+1] = key;
    
}

void TambahData(struct mhs mahasiswa[MAX]){
    if(count == MAX){
        printf("Data mahasiswa sudah penuh!\n");
        return;
    }
    
    printf("Masukkan NRP: ");
    scanf("%d", &mahasiswa[count].nrp);
    printf("Masukkan Nama: ");
    scanf("%s", mahasiswa[count].nama);
    count++;
}

void TampilkanData(struct mhs mahasiswa[MAX]){
    if(count == 0){
        printf("Data mahasiswa kosong!\n");
        return;
    }

    printf("NRP\tNama\n");
    for(int i=0;i<count;i++){
        printf("%d\t%s\n", mahasiswa[i].nrp, mahasiswa[i].nama);
    }
}

void main()
{
    struct mhs mahasiswa[MAX];
    
    int pilih;
    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Urutkan Asc\n");
        printf("3. Urutkan Desc\n");
        printf("4. Tampilkan Data\n");
        printf("5. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);
        
        switch(pilih){
            case 1:
                TambahData(mahasiswa);
                break;
            case 2:
                InsertionSortAsc(data, count);
                printf("Data sudah diurutkan secara ascending!\n");
                break;
            case 3:
                InsertionSortDesc(data, count);
                printf("Data sudah diurutkan secara descending!\n");
                break;
            case 4:
                TampilkanData(mahasiswa);
                break;
            case 5:
                printf("Program Selesai!");
                break;
            default:
                printf("Pilihan tidak tersedia!");
                break;
        }

    } while(pilih != 5);
}