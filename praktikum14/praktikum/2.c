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
    if (ph == NULL) {
        return;
    }

    pohon stack[100];
    int top = -1;
    stack[++top] = ph;

    while (top >= 0) {
        pohon node = stack[top--];
        printf("%c ", node->info);

        if (node->kanan != NULL) {
            stack[++top] = node->kanan;
        }

        if (node->kiri != NULL) {
            stack[++top] = node->kiri;
        }
    }
}

// Fungsi untuk melakukan traversal inorder pada binary tree
void inorder(pohon ph) {
    if (ph == NULL) {
        return;
    }

    pohon stack[100];
    int top = -1;
    pohon current = ph;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->kiri;
        }

        current = stack[top--];
        printf("%c ", current->info);

        current = current->kanan;
    }
}

// Fungsi untuk melakukan traversal postorder pada binary tree
void postorder(pohon ph) {
    if (ph == NULL) {
        return;
    }

    pohon stack1[100];
    pohon stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = ph;

    while (top1 >= 0) {
        pohon node = stack1[top1--];
        stack2[++top2] = node;

        if (node->kiri != NULL
            && node->kanan != NULL) {
            stack1[++top1] = node->kiri;
            stack1[++top1] = node->kanan;
        }
    }

    while (top2 >= 0) {
        pohon node = stack2[top2--];
        printf("%c ", node->info);
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
