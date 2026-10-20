#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void insert(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = element;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into the circular queue.\n", element);
}

void delete() {
    if (isEmpty()) {
        printf("Circular queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    int data = temp->data;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
    printf("%d deleted from the circular queue.\n", data);
}

void display() {
    if (isEmpty()) {
        printf("Circular queue is empty.\n");
        return;
    }

    struct Node* temp = front;

    printf("Circular queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

void freeQueue() {
    if (isEmpty()) {
        return;
    }

    struct Node* current = front;
    rear->next = NULL;

    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    front = rear = NULL;
}

int main() {
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Check if empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeQueue();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");

                if (scanf("%d", &element) != 1) {
                    printf("Invalid input.\n");
                    freeQueue();
                    return 1;
                }

                insert(element);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf(isEmpty()
                    ? "Circular queue is empty.\n"
                    : "Circular queue is not empty.\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    freeQueue();
    return 0;
}
