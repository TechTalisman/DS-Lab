
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct CircularQueue {
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
    return newNode;
}

struct CircularQueue *createQueue(void) {
    struct CircularQueue *q = malloc(sizeof(struct CircularQueue));

    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct CircularQueue *q) {
    return q->front == NULL;
}

void enqueue(struct CircularQueue *q, int value) {
    struct Node *newNode = createNode(value);

    if (newNode == NULL) {
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d enqueued to circular queue.\n", value);
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty.\n");
        return;
    }

    struct Node *temp = q->front;
    int value = temp->data;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    printf("%d dequeued from circular queue.\n", value);
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty.\n");
        return;
    }

    struct Node *temp = q->front;

    printf("Circular queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf("\n");
}

void freeQueue(struct CircularQueue *q) {
    while (!isEmpty(q)) {
        struct Node *temp = q->front;

        if (q->front == q->rear) {
            q->front = q->rear = NULL;
        } else {
            q->front = q->front->next;
            q->rear->next = q->front;
        }

        free(temp);
    }

    free(q);
}

int main(void) {
    struct CircularQueue *q = createQueue();

    if (q == NULL) {
        return 1;
    }

    int choice, value;

    do {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeQueue(q);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeQueue(q);
                    return 1;
                }

                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeQueue(q);
    return 0;
}
