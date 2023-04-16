#include <stdio.h>

#define MAXIMUM 100

typedef struct {
    char data[MAXIMUM];
    int count;
} Stack;

void init(Stack *s) {
    s->count = 0;
}

int isEmpty(Stack *s) {
    return (s->count == 0);
}

int isFull(Stack *s) {
    return (s->count == MAXIMUM);
}

void push(Stack *s, char c) {
    if(!isFull(s)) {
        s->data[s->count] = c;
        s->count++;
    }else{
        printf("Stack penuh");
    }
}

char pop(Stack *s) {
    if(!isEmpty(s)) {
        s->count--;
        return s->data[s->count];
    }else{
        printf("Stack kosong");
    }
}





int main() {
    Stack s;
    printf("Masukan kalimat: ");
    init(&s);
    char c;
    while ((c = getchar()) != '\n') {
        push(&s, c);
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    return 0;
}