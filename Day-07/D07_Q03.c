#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX == front;
}

void insert(int element) {
    if (isFull()) {
        printf("Circular queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = element;

    printf("%d inserted into the circular queue.\n", element);
}

void delete() {
    if (isEmpty()) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue elements: ");

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
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

    return 0;
}
