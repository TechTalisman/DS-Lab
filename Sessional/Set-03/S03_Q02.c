
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define SIZE 300

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

int evaluatePostfix(char expression[], int *result) {
    char *token = strtok(expression, " \t\n");

    top = -1;

    while (token != NULL) {
        char *end;
        long number = strtol(token, &end, 10);

        if (*token != '\0' && *end == '\0') {
            if (number < -2147483647L - 1 ||
                number > 2147483647L) {
                printf("Integer value out of range.\n");
                return 0;
            }

            if (!push((int)number)) {
                printf("Stack overflow.\n");
                return 0;
            }
        } else if (strlen(token) == 1 &&
                   strchr("+-*/", token[0]) != NULL) {
            int operand1, operand2, value;

            if (!pop(&operand2) || !pop(&operand1)) {
                printf("Invalid postfix expression.\n");
                return 0;
            }

            switch (token[0]) {
                case '+':
                    value = operand1 + operand2;
                    break;

                case '-':
                    value = operand1 - operand2;
                    break;

                case '*':
                    value = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        return 0;
                    }
                    value = operand1 / operand2;
                    break;

                default:
                    return 0;
            }

            if (!push(value)) {
                printf("Stack overflow.\n");
                return 0;
            }
        } else {
            printf("Invalid token: %s\n", token);
            return 0;
        }

        token = strtok(NULL, " \t\n");
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    *result = stack[top];
    return 1;
}

int main(void) {
    char expression[SIZE];
    int result;

    printf("Enter postfix expression (separate tokens with spaces):\n");

    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    if (evaluatePostfix(expression, &result)) {
        printf("Result: %d\n", result);
    }

    return 0;
}
