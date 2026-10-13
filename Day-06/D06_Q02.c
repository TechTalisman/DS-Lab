#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;

    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack() {
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is empty\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeStack();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeStack();
                    return 1;
                }
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;

            case 3:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    freeStack();
    return 0;
}
