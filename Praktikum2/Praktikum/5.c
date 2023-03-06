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

int validateInfix(Stack *s) {
    int bukakurung = 0;
    int tutupkurung = 0;
    int operator = 0;
    int operand = 0;
    int i;

    for (i = 0; i < s->count; i++) {
        if (s->data[i] == '(') {
            bukakurung++;
        } else if (s->data[i] == ')') {
            tutupkurung++;
        } else if (s->data[i] == '+' || s->data[i] == '-' || s->data[i] == '*' || s->data[i] == '/') {
            operator++;
        } else if (s->data[i] >= '0' && s->data[i] <= '9') {
            operand++;
        }
    }

    if (bukakurung == tutupkurung && operator == operand - 1) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    Stack s;
    printf("Masukan notasi infix: ");
    init(&s);
    char c;
    while ((c = getchar()) != '\n') {
        push(&s, c);
    }

    if (validateInfix(&s)) {
        printf("Notasi infix valid");
    } else {
        printf("Notasi infix tidak valid");
    }
}