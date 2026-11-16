#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int hasDuplicateParentheses(char expression[]) {
    int duplicateFound = 0;
    top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isspace((unsigned char)ch)) {
            continue;
        }

        if (ch == ')') {
            int elementsInside = 0;

            while (top >= 0 && stack[top] != '(') {
                top--;
                elementsInside++;
            }

            if (top < 0) {
                printf("Invalid expression: unmatched closing parenthesis.\n");
                return -1;
            }

            top--;

            if (elementsInside <= 1) {
                duplicateFound = 1;
            }
        } else {
            if (top == MAX - 1) {
                printf("Expression is too long.\n");
                return -1;
            }

            stack[++top] = ch;
        }
    }

    for (int i = 0; i <= top; i++) {
        if (stack[i] == '(') {
            printf("Invalid expression: unmatched opening parenthesis.\n");
            return -1;
        }
    }

    return duplicateFound;
}

int main(void) {
    char expression[MAX];

    printf("Enter an expression: ");

    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    int result = hasDuplicateParentheses(expression);

    if (result == 1) {
        printf("The expression has duplicate parentheses.\n");
    } else if (result == 0) {
        printf("The expression does not have duplicate parentheses.\n");
    }

    return 0;
}
