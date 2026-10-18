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
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into the queue.\n", element);
}

void delete() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d deleted from the queue.\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue() {
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
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
                printf(isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
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
