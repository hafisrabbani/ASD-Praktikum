#include <stdio.h>
#define MAX 5
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

int main()
{
    struct Queue queue;
    init(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    dequeue(&queue);
    enqueue(&queue, 8);
    dequeue(&queue);
    enqueue(&queue, 9);
    enqueue(&queue, 10);
    enqueue(&queue, 11);
    enqueue(&queue, 12);

    while (!isEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
}