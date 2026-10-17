#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

void insert(int element) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    queue[++rear] = element;
    printf("%d inserted into the queue.\n", element);
}

void delete() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("%d deleted from the queue.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
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
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                if (scanf("%d", &element) != 1) {
                    printf("Invalid input.\n");
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

    return 0;
}
