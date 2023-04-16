#include <stdio.h>
#include <string.h>
struct dtnilai
{
char nrp[10];
char nama[20];
double nilai;
};

void main()
{
struct dtnilai my_struct;
struct dtnilai *st_ptr;
st_ptr = &my_struct;
strcpy(my_struct.nrp,"01");
printf("\n%s ",my_struct.nrp);
strcpy(my_struct.nama,"Arini");
printf("\n%s ",my_struct.nama);
my_struct.nilai = 63.6;
tampil(st_ptr);
}
void tampil(struct tag *p)
{
printf("\n%s ", p->nrp);
printf("%s ", p->nama);
printf("%d\n", p->age);
}