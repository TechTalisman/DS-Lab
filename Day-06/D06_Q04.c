#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int operandStack[MAX];
char operatorStack[MAX];
int topOperand = -1;
int topOperator = -1;

void pushOperand(int value) {
    if (topOperand < MAX - 1) {
        operandStack[++topOperand] = value;
    }
}

int popOperand() {
    return operandStack[topOperand--];
}

void pushOperator(char op) {
    if (topOperator < MAX - 1) {
        operatorStack[++topOperator] = op;
    }
}

char popOperator() {
    return operatorStack[topOperator--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

void evaluateTop() {
    int b = popOperand();
    int a = popOperand();
    char op = popOperator();

    pushOperand(applyOperation(a, b, op));
}

int evaluateInfix(char* exp) {
    topOperand = -1;
    topOperator = -1;

    int length = strlen(exp);

    for (int i = 0; i < length; i++) {
        if (isspace((unsigned char)exp[i])) {
            continue;
        }

        if (isdigit((unsigned char)exp[i])) {
            int value = 0;

            while (i < length && isdigit((unsigned char)exp[i])) {
                value = value * 10 + (exp[i] - '0');
                i++;
            }

            i--;
            pushOperand(value);
        } else if (exp[i] == '(') {
            pushOperator(exp[i]);
        } else if (exp[i] == ')') {
            while (topOperator != -1 &&
                   operatorStack[topOperator] != '(') {
                evaluateTop();
            }

            if (topOperator != -1) {
                popOperator();
            }
        } else if (exp[i] == '+' || exp[i] == '-' ||
                   exp[i] == '*' || exp[i] == '/') {
            while (topOperator != -1 &&
                   operatorStack[topOperator] != '(' &&
                   precedence(operatorStack[topOperator]) >= precedence(exp[i])) {
                evaluateTop();
            }

            pushOperator(exp[i]);
        }
    }

    while (topOperator != -1) {
        if (operatorStack[topOperator] == '(') {
            popOperator();
        } else {
            evaluateTop();
        }
    }

    return popOperand();
}

int main() {
    char exp[MAX];

    printf("Enter infix expression: ");

    if (fgets(exp, sizeof(exp), stdin) == NULL) {
        return 1;
    }

    printf("Result of the infix expression: %d\n", evaluateInfix(exp));

    return 0;
}
