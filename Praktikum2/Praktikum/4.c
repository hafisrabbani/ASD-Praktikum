#include <stdio.h>
#include <string.h>
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

int isPalindrome(Stack *s, char asli[]) {
    int i = 0;
    while (!isEmpty(s)) {
        if (asli[i] != pop(s)) {
            return 0;
        }
        i++;
    }
    return 1;
}


int main() {
    Stack s;
    printf("Masukan kalimat: ");
    init(&s);
    char c;
    char asli[MAXIMUM];
    int i = 0;
    while ((c = getchar()) != '\n') {
        push(&s, c);
        asli[i] = c;
        i++;
    }

    if (isPalindrome(&s, asli)) {
        printf("Palindrome");
    }else{
        printf("Bukan Palindrome");
    }

    
    
}