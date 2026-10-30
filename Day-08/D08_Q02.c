#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

bool hasDuplicateParentheses(char expression[]) {
    top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == ')') {
            int elementsInside = 0;

            while (top >= 0 && stack[top] != '(') {
                top--;
                elementsInside++;
            }

            if (top < 0) {
                printf("Invalid expression: unmatched closing parenthesis.\n");
                return false;
            }

            top--;

            if (elementsInside <= 1) {
                return true;
            }
        } else {
            if (top == MAX - 1) {
                printf("Expression is too long.\n");
                return false;
            }

            stack[++top] = ch;
        }
    }

    for (int i = 0; i <= top; i++) {
        if (stack[i] == '(') {
            printf("Invalid expression: unmatched opening parenthesis.\n");
            return false;
        }
    }

    return false;
}

int main(void) {
    char expression[MAX];

    printf("Enter an expression: ");

    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    if (hasDuplicateParentheses(expression)) {
        printf("The expression has duplicate parentheses.\n");
    } else {
        printf("The expression does not have duplicate parentheses.\n");
    }

    return 0;
}
