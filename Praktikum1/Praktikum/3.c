#include <stdio.h>

typedef struct
{
    int angka;
    int derajat;
} polinom;



// P1 = 6x^8 + 8x^7 +5x^5 + x^3 + 15
// P2 = 3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10
// P3 = x^2 + 5

polinom p1[10]  = {{0,0},{6,8},{8,7},{0,0},{5,5},{0,0},{1,3},{0,0},{0,0},{15,0}};
polinom p2[10]  = {{3,9},{0,0},{4,7},{0,0},{0,0},{3,4},{2,3},{2,2},{0,0},{10,0}};
polinom p3[10]  = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,2},{0,0},{5,0}};

void print_polinom(polinom *p);

void penjumlahan(polinom *p1, polinom *p2, polinom *hasil) {
    int i = 0;
    while(i < 10) {
        int temp1 = p1[i].derajat+p1[i].angka;
        int temp2 = p2[i].derajat+p2[i].angka;

        if(temp1==0 && temp2==0) {
            hasil[i].angka = 0;
            hasil[i].derajat = 0;
        }else if(temp1==0) {
            hasil[i].angka = p2[i].angka;
            hasil[i].derajat = p2[i].derajat;
        }else if(temp2==0) {
            hasil[i].angka = p1[i].angka;
            hasil[i].derajat = p1[i].derajat;
        }else{
            hasil[i].angka = p1[i].angka + p2[i].angka;
            hasil[i].derajat = p1[i].derajat;
        }
        i++;
    }
}

void pengurangan(polinom *p1, polinom *p2, polinom *hasil) {
    int i = 0;
    while(i < 10) {
        int temp1 = p1[i].derajat+p1[i].angka;
        int temp2 = p2[i].derajat+p2[i].angka;

        if(temp1==0 && temp2==0) {
            hasil[i].angka = 0;
            hasil[i].derajat = 0;
        }else if(temp1==0) {
            hasil[i].angka = -p2[i].angka;
            hasil[i].derajat = p2[i].derajat;
        }else if(temp2==0) {
            hasil[i].angka = p1[i].angka;
            hasil[i].derajat = p1[i].derajat;
        }else{
            hasil[i].angka = p1[i].angka - p2[i].angka;
            hasil[i].derajat = p1[i].derajat;
        }
        i++;
    }
}

void perkalian(polinom *p1, polinom *p2) {
    int i, j, derajat;
    polinom hasilTemp[11]; // Ukuran maksimum hasil perkalian adalah 11
    for (i = 0; i < 11; i++) {
        hasilTemp[i].angka = 0; // Inisialisasi polinom hasil dengan angka 0
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (p1[i].angka != 0 && p2[j].angka != 0) {
                derajat = p1[i].derajat + p2[j].derajat;
                hasilTemp[derajat].angka += p1[i].angka * p2[j].angka;
            }
        }
    }
    // Print hasil
    for (i = 11-1; i >= 0; i--) {
        if (hasilTemp[i].angka != 0) {
            if (i == 0) {
                printf("%d", hasilTemp[i].angka);
            } else if (i == 1) {
                printf("%dx + ", hasilTemp[i].angka);
            } else {
                printf("%dx^%d + ", hasilTemp[i].angka, i);
            }
        }
    }
    printf("\n");
}





void turunan(polinom *p1, polinom *hasil)
{
    int i;
    for (i = 0; i <= 10; i++) {
        hasil[i].angka = 0; // inisialisasi polinom hasil dengan angka 0
    }
    for (i = 0; i <= 9; i++) {
        if (p1[i].angka != 0) {
            hasil[i].angka = p1[i].angka * p1[i].derajat;
            hasil[i].derajat = p1[i].derajat - 1;
        }
    }
}





void print_polinom(polinom *hasil) {
    int i = 0;
    while(i < 10) {
        if(hasil[i].angka!=0) {
            if(hasil[i].derajat==0) {
                printf("%d", hasil[i].angka);
            }else if(hasil[i].derajat==1) {
                printf("%dx", hasil[i].angka);
            }else{
                printf("%dx^%d", hasil[i].angka, hasil[i].derajat);
            }
            if(i!=9) {
                printf(" + ");
            }
        }
        i++;
    }
    printf("\n");
}

int main() {
    polinom hasil[10];
    penjumlahan(p1, p2, hasil);
    print_polinom(hasil);
    pengurangan(p1, p2, hasil);
    print_polinom(hasil);
    perkalian(p1, p3);
    turunan(p2, hasil);
    print_polinom(hasil);

    return 0;
}