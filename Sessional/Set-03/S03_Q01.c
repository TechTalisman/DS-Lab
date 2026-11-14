#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
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

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void arrangeEvenBeforeOdd(struct Node **head) {
    struct Node *evenHead = NULL;
    struct Node *evenTail = NULL;
    struct Node *oddHead = NULL;
    struct Node *oddTail = NULL;

    struct Node *current = *head;

    while (current != NULL) {
        struct Node *nextNode = current->next;
        current->next = NULL;

        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = nextNode;
    }

    if (evenHead == NULL) {
        *head = oddHead;
    } else {
        evenTail->next = oddHead;
        *head = evenHead;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter linked list elements:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            freeList(head);
            return 1;
        }

        insertEnd(&head, value);
    }

    printf("Original linked list:\n");
    display(head);

    arrangeEvenBeforeOdd(&head);

    printf("After arranging even numbers before odd numbers:\n");
    display(head);

    freeList(head);

    return 0;
}
