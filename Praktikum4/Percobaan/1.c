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
    void assignLast();
    void find();


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

    void assignLast(){
        struct simpul *baca;
        baca = ujung;
        if(baca == NULL){
            printf("Tidak ada data\n");
        } else {
            while (baca->next != NULL)
            {
                baca = baca->next;
            }
            printf("Masukkan nama : ");
            scanf("%s", &baca->nama);
            printf("Masukkan NRP : ");
            scanf("%d", &baca->nrp);        
        }
    }

    void find(){
        struct simpul *baca;
        baca = ujung;
        int nrp;
        printf("Masukkan NRP : ");
        scanf("%d", &nrp);
        if(baca == NULL){
            printf("Tidak ada data\n");
        } else {
            while(baca != NULL){
                if(baca->nrp == nrp){
                    printf("Nama : %s\n", baca->nama);
                    printf("NRP : %d", baca->nrp);
                    printf("\n\n");
                    break;
                }
                baca = baca->next;
            }
        }
    }




    void main()
    {
        int pilih;
        do
        {
            printf("1. Tambah simpul\n");
            printf("2. Baca simpul\n");
            printf("3. Tambah simpul terakhir\n");
            printf("4. Cari simpul\n");
            printf("5. Keluar\n");
            printf("Pilihan : ");
            scanf("%d", &pilih);
            switch(pilih)
            {
                case 1: add(); break;
                case 2: read(); break;
                case 3: assignLast(); break;
                case 4: find(); break;
                default: printf("Pilihan tidak ada\n"); break;
            }
        } while(pilih != 5 || pilih < 1 || pilih > 5);
    }
