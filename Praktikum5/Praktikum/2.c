#include <stdio.h>
#include <stdlib.h>

struct Polinom
{
    int koefisien;
    int pangkat;
    struct Polinom *next;
};

struct Polinom *ujung = NULL;

void add();
void read();


void add()
{
    struct Polinom *baru;
    baru = (struct Polinom *)malloc(sizeof(struct Polinom));
    printf("Masukkan koefisien : ");
    scanf("%d", &baru->koefisien);
    printf("Masukkan pangkat : ");
    scanf("%d", &baru->pangkat);
    baru->next = NULL;
    if(ujung == NULL){
        ujung = baru;
    } else {
        if(ujung->pangkat < baru->pangkat){
            baru->next = ujung;
            ujung = baru;
        } else {
            struct Polinom *temp = ujung;
            while(temp->next != NULL && temp->next->pangkat > baru->pangkat){
                temp = temp->next;
            }
            baru->next = temp->next;
            temp->next = baru;
        }
    }
}

void read()
{
    struct Polinom *baca;
    baca = ujung;
    if(baca == NULL){
        printf("Tidak ada data\n");
    } else {
        while(baca != NULL){
            (baca->pangkat == 0) ? printf("%d", baca->koefisien) : printf("%dx^%d + ", baca->koefisien, baca->pangkat);
            baca = baca->next;
        }
    }
}

int main()
{
    int pilihan;
    do{
        printf("1. Tambah\n");
        printf("2. Baca\n");
        printf("3. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch(pilihan)
        {
            case 1:add();break;
            case 2:read();break;
            case 3:printf("Terima kasih\n");break;
            default:printf("Pilihan tidak ada\n");
        }
    } while(pilihan != 4);
    return 0;
}
