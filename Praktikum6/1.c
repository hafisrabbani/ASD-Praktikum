

#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    char nama[25];
    int nrp;
    Node *before;
    Node *next;
};

Node *head = NULL;


void sisipAwal(){
    Node *baru = (Node *) malloc(sizeof(Node));
    printf("masukkan nama : ");
    scanf("%s", baru->nama);
    printf("masukkan nrp : ");
    scanf("%d", &baru->nrp);
    baru->before = NULL;
    
    if (!head) {
        baru->next = NULL;
        head = baru;
    } else {
        head->before = baru;
        baru->next = head;
        head = baru;
    }
}

void tampil(){
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    while (temp != NULL) {
        printf("nama : %s\nnrp : %d\n", temp->nama, temp->nrp);
        temp = temp->before;
    }
}

void cari(){
    int nrp;
    printf("masukkan nrp : ");
    scanf("%d", &nrp);
    
    Node *temp = head;
    while (temp != NULL) {
        if (temp->nrp == nrp) {
            printf("-----data ditemukan----\nnama : %s\nnrp : %d\n", temp->nama, temp->nrp);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("data tidak ditemukan\n");
    }
}

void hapus(){
    int nrp;
    printf("masukkan nrp : ");
    scanf("%d", &nrp);
    
    Node *recent = head;
    while (recent != NULL) {
        if (recent->nrp == nrp) {
            if (recent == head) {
                head = recent->next;
                free(recent);
                break;
            }
            Node *before = recent->before;
            before->next = recent->next;
            free(recent);
            break;
        }
        recent = recent->next;
        
    }
    
    if (recent == NULL) {
        printf("data tidak ditemukan\n");
    }
}

int main() {
    
    char lanjut='y';
    int pilihan;
        
        while (lanjut == 'y') {
            printf("(1). sisipkan di sebelum\n(2). tampilkan\n(3). cari\n(4). hapus\npilihan : ");
            scanf("%d", &pilihan);
            switch (pilihan) {
                case 1:
                    sisipAwal();
                    break;
                case 2:
                    tampil();
                    break;
                case 3:
                    cari();
                    break;
                case 4:
                    hapus();
                    break;
                default:
                    printf("salah input\n");
                    break;
            }
            
            fflush(stdin);
            printf("lanjut? (y/n) : ");
            lanjut = getchar();
        }

    return 0;
}
