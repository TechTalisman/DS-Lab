
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

int push(int value) {
    if (top == MAX - 1) {
        return 0;
    }

    stack[++top] = value;
    return 1;
}

int pop(int *value) {
    if (top == -1) {
        return 0;
    }

    *value = stack[top--];
    return 1;
}

int evaluatePostfix(char expression[]) {
    top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isdigit((unsigned char)c)) {
            if (!push(c - '0')) {
                printf("Stack overflow.\n");
                return 0;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand1, operand2;

            if (!pop(&operand2) || !pop(&operand1)) {
                printf("Invalid postfix expression.\n");
                return 0;
            }

            int result;

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        return 0;
                    }
                    result = operand1 / operand2;
                    break;
            }

            if (!push(result)) {
                printf("Stack overflow.\n");
                return 0;
            }
        } else {
            printf("Invalid character: %c\n", c);
            return 0;
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    printf("Result of the postfix expression: %d\n", stack[top]);
    return 1;
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression (single-digit operands): ");

    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    evaluatePostfix(expression);

    return 0;
}
