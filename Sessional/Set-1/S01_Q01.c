
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty(void) {
    return top == -1;
}

int isFull(void) {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow.\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack.\n", value);
}

void pop(void) {
    if (isEmpty()) {
        printf("Stack underflow.\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top--]);
}

void display(void) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

void findMinimum(void) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    int min = stack[0];

    for (int i = 1; i <= top; i++) {
        if (stack[i] < min) {
            min = stack[i];
        }
    }

    printf("Minimum element: %d\n", min);
}

void findMaximum(void) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    int max = stack[0];

    for (int i = 1; i <= top; i++) {
        if (stack[i] > max) {
            max = stack[i];
        }
    }

    printf("Maximum element: %d\n", max);
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                findMinimum();
                break;

            case 5:
                findMaximum();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
