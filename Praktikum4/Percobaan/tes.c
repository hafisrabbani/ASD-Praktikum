#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul {
  char nama[25];
  int nrp;
  struct simpul *next;
}link;

link *head = NULL;

//Alokasi memori
void tambah() {
      link *baru = (link *) malloc(sizeof(link));
    fflush(stdin);
      printf("\nNama\t: ");
      scanf("%[^\n]s", baru->nama);
      printf("NRP\t: ");
      scanf("%d", &baru->nrp);
    baru->next = NULL;

      if (head == NULL){
          printf("tes 123\n");
            head = baru;
      }
      else{
          link *tmp = head;
          while (tmp->next != NULL) {
              tmp = tmp->next;
          }
          tmp->next = baru;
      }
}

//Membaca atau menampilkan
void tampil(){
    link *tampil = head;

    while(tampil != NULL){
        printf("Nama: %s\n",tampil->nama);
        printf("NRP: %d\n",tampil->nrp);
        tampil = tampil->next;
    }
}

void cari(){
    link *cari;
    int cariNRP = 0, pil;
    char cariNama[25];
    printf("Mau cari berdasarkan apa :");
    printf("\n1. Nama\n2.NRP\n");
    printf("\nPilihan Anda : ");
    scanf("%d", &pil);

    if(pil == 1){
        printf("Nama yang dicari : ");
        scanf("%[^\n]s", cariNama);
    }else{
        printf("NRP yang dicari : ");
        scanf("%d", &cariNRP);
    }
    cari = head;

    while(cari!=NULL){
        if(strcmp(cariNRP, head->nrp) == 0 || strcmp(cariNama, head->nama) == 0){
            printf("Data ditemukan!");
            printf("Nama\t: %s", head->nama);
            printf("NRP\t: %d", head->nrp);
        }
        else{
            printf("Data tidak ditemukan :<");
        }
        cari = cari->next;
    }
}

int main(){
    int pilihan;
    int lanjut = 1;

    while(lanjut == 1){
        printf("\n--------------------------------\n");
        printf("1. Tambah data\n");
        printf("2. Baca dan Tampilkan\n");
        printf("3. Cari simpul\n");
        printf("4. Sisipkan Akhir\n");
        printf("5. EXIT\n");

        printf("\nPilihan anda : ");
        scanf("%d", &pilihan);

        switch(pilihan){
        case 1 :    //tambah
            printf("\n TAMBAH DATA \n");
            tambah();
            break;
        case 2 :    //baca dan tampil
            printf("\n TAMPILKAN DATA \n");
            tampil();
            break;
        case 3 :    //cari
            printf("\n CARI DATA \n");
            cari();
            break;
        case 4 :
            printf("\n SISIPKAN AKHIR \n");
            break;
        case 5 :
            printf("\n--PROGRAM SELESAI--\n");
            lanjut = 0;
            break;
        default :
            printf("Pilihan anda salah!, Input lagi : ");
            scanf("%d", &pilihan);
        }
    }
    
    
    return 0;
}