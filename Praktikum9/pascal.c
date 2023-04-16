#include <stdio.h>

int pascal(int baris,int kolom);
void cetakPascal(int max){
    int i,j,k;
    for(i=0;i<max;i++){
        for(j=max;j>i;j--)
            printf(" ");
        for(k=0;k<=i;k++)
            printf("%d ",pascal(i,k));
        printf("\n");
    }
}

int pascal(int baris, int kolom){
    if(kolom==0 || kolom==baris){
        return 1;
    }
    else{
        return pascal(baris-1,kolom-1)+pascal(baris-1,kolom);
    }
}

int main(){
    cetakPascal(5);
    return 0;
}