#include <stdio.h>
#include <math.h>
int isPrima(int bil,int i){
    if(bil==1){
        return 0;
    }
    if(i==1){
        return 1;
    }else{
        if(bil%i==0){
            return 0;
        }else{
            return isPrima(bil,i-1);
        }
    }
}

void main(){
    int bil;
    printf("Masukkan angka: ");
    scanf("%d",&bil);
    printf((isPrima(bil,(int)sqrt(bil))==0) ? "Bukan bilangan prima":"Bilangan prima");
}