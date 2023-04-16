#include <stdio.h>
#include <stdlib.h>

struct simpul
{
    char nama[25];
    int nrp;
    struct simpul *next;
};

struct simpul *ujung = NULL;

void add();
void read();
void assignBefore();
void assignAfter();
void del();


void add(){
    struct simpul *baru;
    baru = (struct simpul *)malloc(sizeof(struct simpul));
    printf("Masukkan nama : ");
    scanf("%s", &baru->nama);
    printf("Masukkan NRP : ");
    scanf("%d", &baru->nrp);
    baru->next = NULL;
    if(ujung == NULL){
        ujung = baru;
    } else {
        baru->next = ujung;
        ujung = baru;
    }
}

void read(){
    struct simpul *baca;
    baca = ujung;
    if(baca == NULL){
        printf("Tidak ada data\n");
    } else {
        while(baca != NULL){
            printf("Nama : %s\n", baca->nama);
            printf("NRP : %d", baca->nrp);
            printf("\n\n");
            baca = baca->next;
        }
    }
}

void assignBefore(){
    struct simpul *baru, *baca;
    int cari;
    baca = ujung;
    baru = (struct simpul *)malloc(sizeof(struct simpul));
    printf("Masukkan nama : ");
    scanf("%s", &baru->nama);
    printf("Masukkan NRP : ");
    scanf("%d", &baru->nrp);
    baru->next = NULL;
    printf("Masukkan NRP yang akan ditambahkan sebelumnya : ");
    scanf("%d", &cari);
    if(baca == NULL){
        printf("Tidak ada data\n");
    } else {
        while(baca != NULL){
            if(baca->nrp == cari){
                baru->next = baca;
                ujung = baru;
                break;
            } else if(baca->next->nrp == cari){
                baru->next = baca->next;
                baca->next = baru;
                break;
            }
            baca = baca->next;
        }
    }
}

void assignAfter(){
    struct simpul *baru, *baca;
    int cari;
    baca = ujung;
    baru = (struct simpul *)malloc(sizeof(struct simpul));
    printf("Masukkan nama : ");
    scanf("%s", &baru->nama);
    printf("Masukkan NRP : ");
    scanf("%d", &baru->nrp);
    baru->next = NULL;
    printf("Masukkan NRP yang akan ditambahkan sesudahnya : ");
    scanf("%d", &cari);
    if(baca == NULL){
        printf("Tidak ada data\n");
    } else {
        while(baca != NULL){
            if(baca->nrp == cari){
                baru->next = baca->next;
                baca->next = baru;
                break;
            }
            baca = baca->next;
        }
    }
}

void del()
{
    struct simpul *hapus, *baca;
    int cari;
    baca = ujung;

    printf("Masukkan NRP yang akan dihapus : ");
    scanf("%d", &cari);
    if(baca == NULL){
        printf("Tidak ada data\n");
    }else{
        if(baca->nrp == cari){
            hapus = baca;
            ujung = baca->next;
            free(hapus);
            printf("Data berhasil dihapus\n");
        } else {
            while(baca->next != NULL){
                if(baca->next->nrp == cari){ 
                    hapus = baca->next;
                    baca->next = hapus->next;
                    free(hapus);
                    printf("Data berhasil dihapus\n");
                    return;
                }
                baca = baca->next;
            }
            printf("Data tidak ditemukan\n");
        }
    }
}

void main()
{
    int pilih;
    do
    {
        printf("1. Tambah\n");
        printf("2. Baca\n");
        printf("3. Tambah Sebelum\n");
        printf("4. Tambah Sesudah\n");
        printf("5. Hapus\n");
        printf("6. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);
        switch(pilih)
        {
            case 1: add(); break;
            case 2: read(); break;
            case 3: assignBefore(); break;
            case 4: assignAfter(); break;
            case 5: del(); break;
            case 6: exit(0); break;
            
        }
    } while(pilih != 6 || pilih < 1 || pilih > 6);
}
