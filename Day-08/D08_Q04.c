
#include <stdio.h>

#define MAX 5

typedef struct Deque {
    int items[MAX];
    int front, rear;
} Deque;

void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) ||
           (dq->front == dq->rear + 1);
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }

    dq->items[dq->front] = value;
    printf("%d added to the front.\n", value);
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->items[dq->rear] = value;
    printf("%d added to the rear.\n", value);
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("%d removed from the front.\n", dq->items[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("%d removed from the rear.\n", dq->items[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");

    int i = dq->front;

    while (1) {
        printf("%d ", dq->items[i]);

        if (i == dq->rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    Deque dq;
    int choice, value;

    init(&dq);

    do {
        printf("\n--- Deque Operations ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertFront(&dq, value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insertRear(&dq, value);
                break;

            case 3:
                deleteFront(&dq);
                break;

            case 4:
                deleteRear(&dq);
                break;

            case 5:
                display(&dq);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
