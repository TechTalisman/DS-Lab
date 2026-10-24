
#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int value) {
    if (isFull(s)) {
        return 0;
    }

    s->items[++s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }

    return s->items[s->top--];
}

void printBinary(unsigned int n) {
    Stack s;
    init(&s);

    if (n == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    while (n > 0) {
        push(&s, n % 2);
        n /= 2;
    }

    printf("Binary representation: ");

    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }

    printf("\n");
}

int main(void) {
    int n;

    printf("Enter a non-negative integer: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    printBinary((unsigned int)n);

    return 0;
}
