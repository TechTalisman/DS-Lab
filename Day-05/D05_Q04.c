#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void createCircularDoublyLinkedList(struct Node** head, int n) {
    struct Node* last = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (*head == NULL) {
            *head = newNode;
            last = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->prev = last;
            newNode->next = *head;
            last->next = newNode;
            (*head)->prev = newNode;
            last = newNode;
        }
    }
}

void displayCircularDoublyLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Doubly Linked List: ");

    do {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != head) {
            printf(" <-> ");
        }
    } while (temp != head);

    printf(" -> back to %d\n", head->data);
}

void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = (*head)->next;

    while (current != *head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(*head);
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of nodes: ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    createCircularDoublyLinkedList(&head, n);

    printf("\nThe created circular doubly linked list is:\n");
    displayCircularDoublyLinkedList(head);

    freeList(&head);

    return 0;
}
