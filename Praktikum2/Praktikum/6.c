#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXIMUM 100

int top = -1;

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
    if (!isFull(s)) {
        s->data[s->count] = c;
        s->count++;
    } else {
        printf("Stack penuh");
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        s->count--;
        return s->data[s->count];
    } else {
        printf("Stack kosong");
        return '\0';
    }
}

int tingkatOperator(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}

int calculate(Stack *s, char *postfix) {
    int operand1, operand2, i = 0;
    char c;

    while (postfix[i] != '\0') {
        c = postfix[i];
        if (isdigit(c)) {
            push(s, c - '0');
        } else {
            operand2 = pop(s);
            operand1 = pop(s);
            switch (c) {
                case '+':
                    push(s, operand1 + operand2);
                    break;
                case '-':
                    push(s, operand1 - operand2);
                    break;
                case '*':
                    push(s, operand1 * operand2);
                    break;
                case '/':
                    push(s, operand1 / operand2);
                    break;
            }
        }
        i++;
    }

    return pop(s);
}

int main() {
    char c[MAXIMUM];
    char *data, x, postfix[MAXIMUM];
    int i = 0;
    printf("Masukkan notasi infix: ");
    scanf("%s", c);
    data = c;
    Stack s;
    init(&s);
    while (*data != '\0') {
        if (isdigit(*data)) {
            postfix[i] = *data;
            i++;
        } else if (*data == '(') {
            push(&s, *data);
        } else if (*data == ')') {
            while ((x = pop(&s)) != '(') {
                postfix[i] = x;
                i++;
            }
        } else {
            while (!isEmpty(&s) && tingkatOperator(s.data[s.count - 1]) >= tingkatOperator(*data)) {
                postfix[i] = pop(&s);
                i++;
            }
            push(&s, *data);
        }
        data++;
    }
    while (!isEmpty(&s)) {
        postfix[i] = pop(&s);
        i++;
    }
    postfix[i] = '\0';
    printf("Notasi postfix: %s\n", postfix);
    printf("Hasil: %d", calculate(&s, postfix));
    return 0;
}