
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

struct Deque *createDeque(void) {
    struct Deque *dq = malloc(sizeof(struct Deque));

    if (dq == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    dq->front = NULL;
    dq->rear = NULL;

    return dq;
}

int isEmpty(struct Deque *dq) {
    return dq->front == NULL;
}

void insertFront(struct Deque *dq, int value) {
    struct Node *newNode = createNode(value);

    if (newNode == NULL) {
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }

    printf("%d added to the front.\n", value);
}

void insertRear(struct Deque *dq, int value) {
    struct Node *newNode = createNode(value);

    if (newNode == NULL) {
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }

    printf("%d added to the rear.\n", value);
}

void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *temp = dq->front;
    printf("%d removed from the front.\n", temp->data);

    dq->front = dq->front->next;

    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL;
    }

    free(temp);
}

void deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *temp = dq->rear;
    printf("%d removed from the rear.\n", temp->data);

    dq->rear = dq->rear->prev;

    if (dq->rear != NULL) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL;
    }

    free(temp);
}

void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *temp = dq->front;

    printf("Deque elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void freeDeque(struct Deque *dq) {
    struct Node *temp = dq->front;

    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    free(dq);
}

int main(void) {
    struct Deque *dq = createDeque();

    if (dq == NULL) {
        return 1;
    }

    int choice, value;

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
            printf("Invalid input.\n");
            freeDeque(dq);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeDeque(dq);
                    return 1;
                }

                insertFront(dq, value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeDeque(dq);
                    return 1;
                }

                insertRear(dq, value);
                break;

            case 3:
                deleteFront(dq);
                break;

            case 4:
                deleteRear(dq);
                break;

            case 5:
                display(dq);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    freeDeque(dq);

    return 0;
}
