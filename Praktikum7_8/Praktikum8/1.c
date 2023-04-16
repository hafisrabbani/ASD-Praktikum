#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int koofisien;
    int pangkat;
    struct node *before;
    struct node *after;
} node;

node *head = NULL;
node *tail = NULL;

void assign(int koofisien, int pangkat)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->koofisien = koofisien;
    newNode->pangkat = pangkat;
    newNode->before = NULL;
    newNode->after = NULL;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            if(temp->pangkat == pangkat)
            {
                temp->koofisien += koofisien;
                break;
            }
            else if(temp->pangkat < pangkat)
            {
                newNode->after = temp;
                newNode->before = temp->before;
                if (temp->before != NULL) {
                    temp->before->after = newNode;
                }
                temp->before = newNode;
                if (temp == head) {
                    head = newNode;
                }
                break;
            }
            else if(temp->after == NULL)
            {
                temp->after = newNode;
                newNode->before = temp;
                tail = newNode;
                break;
            }
            temp = temp->after;
        }
    }
}

void read()
{
    node *temp = head;
    printf("Koofisien\tPangkat\n");
    while(temp != NULL)
    {
        printf("%d\t%d\n", temp->koofisien, temp->pangkat);
        temp = temp->after;
    }
}

void main()
{
    int koofisien, pangkat, pilihan;
    do
    {
        printf("1. Assign\n");
        printf("2. Read\n");
        printf("3. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        switch(pilihan)
        {
            case 1:
                printf("Koofisien: ");
                scanf("%d", &koofisien);
                printf("Pangkat: ");
                scanf("%d", &pangkat);
                assign(koofisien, pangkat);
                break;
            case 2:
                read();
                break;
            case 3:
                break;
            default:
                printf("Pilihan tidak ada\n");
        }
    } while (pilihan != 3 || pilihan < 1 || pilihan > 3);
}