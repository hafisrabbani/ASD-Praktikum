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

void toBinary(int n) {
    Stack s;
    init(&s);
    while (n > 0) {
        push(&s, n % 2);
        n /= 2;
    }
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
}

void toOctal(int n) {
    Stack s;
    init(&s);
    while (n > 0) {
        push(&s, n % 8);
        n /= 8;
    }
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
}

void toHexa(int n) {
    Stack s;
    init(&s);
    while (n > 0) {
        int temp = n % 16;
        if (temp < 10) {
            push(&s, temp + '0');
        } else {
            push(&s, temp - 10 + 'A');
        }
        n /= 16;
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
}

void main()
{
    int number, choice;

    printf("Masukan bilangan desimal: ");
    scanf("%d", &number);
    printf("Mau dikonvert kemana ? \n");
    printf("1. Biner \n2. Oktal \n3. Hexadesimal \n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        toBinary(number);
        break;
    case 2:
        toOctal(number);
        break;
    case 3:
        toHexa(number);
        break;
    default:
        printf("Pilihan tidak ada");
        break;
    }
    
}