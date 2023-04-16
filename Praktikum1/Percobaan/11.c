#include <stdio.h>
#include <string.h>
struct dtnilai
{
    char nrp[10];
    char nama[20];
    double nilai;
};
struct dtnilai data[10];
int j=0;
void tambah_data()
{
    char jawab[2];
    while(1)
    {
        fflush(stdin);
        printf("NRP :");scanf("%s",&data[j].nrp);
        printf("Nama :");scanf("%s",&data[j].nama);
        printf("Nilai Test :");scanf("%lf",&data[j].nilai);
        printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
        if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0))
        {
            j++;continue;
        }
        else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
        break;

    }
}
void tampil()
{
    int i;
    printf("Data Mahasiswa yang telah diinputkan :\n");
    printf("NRP\tNama\tNilai\n");
    for (i=0;i<=j;i++)
    {
        printf("%s\t%s\t%6.2f\n",data[i].nrp,data[i].nama,

        data[i].nilai);
    }
}
void main()
{
    tambah_data();
    tampil();
}