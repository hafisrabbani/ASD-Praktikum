#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int nrp;
    char nama[20];
    struct node *before;
    struct node *after;
} node;

node *head = NULL;
node *tail = NULL;

void assignBefore(int nrpBefore, int nrp, char nama[])
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->nrp = nrp;
    strcpy(newNode->nama, nama);
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
            if(temp->nrp == nrpBefore)
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
            temp = temp->after;
        }
    }
}

void assignAfter(int nrpAfter, int nrp, char nama[])
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->nrp = nrp;
    strcpy(newNode->nama, nama);
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
            if(temp->nrp == nrpAfter)
            {
                newNode->before = temp;
                newNode->after = temp->after;
                if (temp->after != NULL) {
                    temp->after->before = newNode;
                }
                temp->after = newNode;
                if (temp == tail) {
                    tail = newNode;
                }
                break;
            }
            temp = temp->after;
        }
    }
}

void read()
{
    node *temp = head;
    printf("NRP\tNama\n");
    while(temp != NULL)
    {
        printf("%d\t%s\n", temp->nrp, temp->nama);
        temp = temp->after;
    }
}

void main()
{
    int nrp, nrpBefore, nrpAfter,pilihan;
    char nama[20];

    do{
        printf("1. Assign Before\n");
        printf("2. Assign After\n");
        printf("3. Read\n");
        printf("4. Exit\n");
        printf("Pilihan: ");

        scanf("%d", &pilihan);

        switch(pilihan)
        {
            case 1:
                printf("NRP: ");
                scanf("%d", &nrp);
                printf("Nama: ");
                scanf("%s", &nama);
                printf("NRP Before: ");
                scanf("%d", &nrpBefore);
                assignBefore(nrpBefore, nrp, nama);
                break;
            case 2:
                printf("NRP: ");
                scanf("%d", &nrp);
                printf("Nama: ");
                scanf("%s", &nama);
                printf("NRP After: ");
                scanf("%d", &nrpAfter);
                assignAfter(nrpAfter, nrp, nama);
                break;
            case 3:
                read();
                break;
            case 4:
                break;
            default:
                printf("Pilihan tidak ada\n");
        }
    }while(pilihan != 4 || pilihan < 1 || pilihan > 4);
}