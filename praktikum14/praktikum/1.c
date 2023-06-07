#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree* pohon;

struct tree {
  char info;
  pohon kiri;
  pohon kanan;
};

pohon baru(char hrf) {
  pohon br = (pohon) malloc(sizeof(struct tree));
  br->info = hrf;
  br->kiri = NULL;
  br->kanan = NULL;
  return br;
}

void sisip(pohon ph, pohon sp) {
  pohon P = ph;
  pohon Q = ph;

  while ((sp->info != ph->info) && (Q != NULL)) {
    P = Q;
    if (sp->info < P->info)
      Q = P->kiri;
    else
      Q = P->kanan;
  }

  if (sp->info == P->info)
    printf("Sudah ada");
  else if (sp->info < P->info)
    P->kiri = sp;
  else
    P->kanan = sp;
}

void preorder(pohon ph) {
  if (ph != NULL) {
    printf("%c ", ph->info);
    preorder(ph->kiri);
    preorder(ph->kanan);
  }
}

void inorder(pohon ph) {
  if (ph != NULL) {
    inorder(ph->kiri);
    printf("%c ", ph->info);
    inorder(ph->kanan);
  }
}

void postorder(pohon ph) {
  if (ph != NULL) {
    postorder(ph->kiri);
    postorder(ph->kanan);
    printf("%c ", ph->info);
  }
}

int main() {
  int j = 0;
  char input, jawab[2];
  pohon br, ssp;
  
  while (1) {
    printf("Ketikkan huruf: ");
    scanf(" %c", &input);
    fflush(stdin);
    
    if (j == 0) 
      br = baru(input);
    else {
      ssp = baru(input);
      sisip(br, ssp);
    }
    
    printf("Ada data lagi (y/t): ");
    scanf("%s", jawab);
    fflush(stdin);
    
    if (strcmp(jawab, "Y") == 0 || strcmp(jawab, "y") == 0) {
      j++;
      continue;
    } else if (strcmp(jawab, "T") == 0 || strcmp(jawab, "t") == 0) {
      break;
    }
  }
  
  printf("Preorder: ");
  preorder(br);
  printf("\n");
  
  printf("Inorder: ");
  inorder(br);
  printf("\n");
  
  printf("Postorder: ");
  postorder(br);
  printf("\n");

  return 0;
}
