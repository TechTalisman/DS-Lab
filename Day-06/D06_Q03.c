#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(char* exp) {
    char postfix[MAX];
    int j = 0;
    char x;

    top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top == -1) {
                printf("Invalid expression.\n");
                return;
            }

            pop();
        } else if (c == '+' || c == '-' || c == '*' ||
                   c == '/' || c == '^') {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && c != '^'))) {
                postfix[j++] = pop();
            }

            push(c);
        } else {
            printf("Invalid character in expression.\n");
            return;
        }
    }

    while (top != -1) {
        x = pop();

        if (x == '(') {
            printf("Invalid expression.\n");
            return;
        }

        postfix[j++] = x;
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char exp[MAX];

    printf("Enter infix expression: ");

    if (fgets(exp, sizeof(exp), stdin) == NULL) {
        return 1;
    }

    infixToPostfix(exp);

    return 0;
}
