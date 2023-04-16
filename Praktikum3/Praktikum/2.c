#include <stdio.h>
#define MAX 100
struct Queue {
    int data[MAX];
    int front;
    int rear;
    int count;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(struct Queue *q) {
    return q->count == 0;
}

int isFull(struct Queue *q) {
    return q->count == MAX;
}

void enqueue(struct Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = x;
        q->count++;
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int x = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return x;
    }
}

void shifter(struct Queue *q, int sizeShift) {
    for(int i=0; i<sizeShift; i++) {
        int x = dequeue(q);
        enqueue(q, x);
    }
}

void convertDec(struct Queue *q, int x, int base) {
    int i = 0;
    int sisa = x%base;
    int hasil = x/base;
    enqueue(q, sisa);
    while (hasil != 0) {
        if(base==16){
            if(sisa>=10 && sisa<=15){
                enqueue(q, 'A'+sisa-10);
            } else {
                enqueue(q, sisa+'0');
            }
        }else{
            enqueue(q, sisa);
        }
        sisa = hasil%base;
        hasil = hasil/base;
        i++;
    }
}

void decConverter(struct Queue *q, int from){
    if(from==1){
        int i = 0;
        int hasil = 0;
        while (!isEmpty(q)) {
            int x = dequeue(q);
            hasil += x * (1 << i);
            i++;
        }
        printf("Hasil konversi: %d", hasil);
    } else if(from==2){
        int i = 0;
        int hasil = 0;
        while (!isEmpty(q)) {
            int x = dequeue(q);
            hasil += x * (8 << i);
            i++;
        }
        printf("Hasil konversi: %d", hasil);
    } else if(from==3){
        int i = 0;
        int hasil = 0;
        while (!isEmpty(q)) {
            int x = dequeue(q);
            hasil += x * (16 << i);
            i++;
        }
        printf("Hasil konversi: %d", hasil);
    }

}

int main()
{
    struct Queue queue;
    init(&queue);
    int x;
    printf("Masukan bilangan desimal: ");
    scanf("%d", &x);
    printf("1.Biner\n2.Oktal\n3.Hexadesimal");
    int pilihan;
    printf("\nPilih: ");
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1:
            convertDec(&queue, x, 2);
            break;
        case 2:
            convertDec(&queue, x, 8);
            break;
        case 3:
            convertDec(&queue, x, 16);
            break;
        default:
            printf("Pilihan tidak ada");
            break;
    }
    struct Queue queue2;
    init(&queue2);
    printf("Hasil konversi: ");
    while (!isEmpty(&queue)) {
        int x = dequeue(&queue);
        if(x>=10 && x<=15){
            printf("%c ", 'A'+x-10);
        } else {
            printf("%d ", x);
        }
        enqueue(&queue2, x);
    }

    printf("\nMasukan banyaknya shift: ");
    int sizeShift;
    scanf("%d", &sizeShift);
    for(int i=0; i<sizeShift; i++) {
        int x = dequeue(&queue2);
        enqueue(&queue2, x);
    }
    struct Queue queue3;
    init(&queue3);
    printf("Hasil shift: ");
    while (!isEmpty(&queue2)) {
        int x = dequeue(&queue2);
        enqueue(&queue3, x);
        printf("%d", x);
    }
    printf("\n");
    decConverter(&queue3, pilihan);
    
}