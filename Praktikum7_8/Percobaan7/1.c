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

void addFirst(int nrp, char nama[])
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
        newNode->after = head;
        head->before = newNode;
        head = newNode;
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

void find(int nrp)
{
    node *temp = head;
    if(head->nrp == nrp)
    {
        printf("%d %s\n", temp->nrp, temp->nama);
    }
    else{
        while(temp != NULL)
        {
            if(temp->nrp == nrp)
            {
                printf("%d %s\n", temp->nrp, temp->nama);
                break;
            }
            temp = temp->after;
        }
    }
}

void delete(int nrp)
{
    node *temp = head;
    if(head->nrp == nrp)
    {
        head = head->after;
        head->before = NULL;
        free(temp);
    }
    else{
        while(temp != NULL)
        {
            if(temp->nrp == nrp)
            {
                temp->before->after = temp->after;
                temp->after->before = temp->before;
                free(temp);
                break;
            }
            temp = temp->after;
        }
    }
}


void main()
{
    int menu, nrp;
    char nama[20];

    do
    {
        printf("Menu\n1. Add First\n2. Read\n3. Find\n4. Delete\n5. Exit\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
                printf("Masukkan NRP: ");
                scanf("%d", &nrp);
                printf("Masukkan Nama: ");
                scanf("%s", &nama);
                addFirst(nrp, nama);
                break;
            case 2:
                read();
                break;
            case 3:
                printf("Masukkan NRP: ");
                scanf("%d", &nrp);
                find(nrp);
                break;
            case 4:
                printf("Masukkan NRP: ");
                scanf("%d", &nrp);
                delete(nrp);
                break;
            case 5:
                printf("Terima kasih");
                break;
            default:
                printf("Pilihan tidak ada");
                break;
        }

    }while(menu != 5 || menu < 1 || menu > 5);

}

