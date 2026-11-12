
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

int isEmpty(void) {
    return count == 0;
}

int isFull(void) {
    return count == MAX;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;

    printf("%d inserted into queue.\n", value);
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    front = (front + 1) % MAX;
    count--;

    if (count == 0) {
        front = 0;
        rear = -1;
    }
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }

    printf("\n");
}

void printMiddle(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int middleIndex = count / 2;
    int middle = queue[(front + middleIndex) % MAX];

    printf("Middle element: %d\n", middle);
}

void printSecondLargest(void) {
    if (count < 2) {
        printf("At least two elements are required.\n");
        return;
    }

    int largest = queue[front];
    int secondLargest = 0;
    int foundSecond = 0;

    for (int i = 1; i < count; i++) {
        int value = queue[(front + i) % MAX];

        if (value > largest) {
            secondLargest = largest;
            largest = value;
            foundSecond = 1;
        } else if (value < largest &&
                   (!foundSecond || value > secondLargest)) {
            secondLargest = value;
            foundSecond = 1;
        }
    }

    if (foundSecond) {
        printf("Second largest element: %d\n", secondLargest);
    } else {
        printf("No second largest distinct element exists.\n");
    }
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Print Middle Element\n");
        printf("5. Print Second Largest Element\n");
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
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printMiddle();
                break;

            case 5:
                printSecondLargest();
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
