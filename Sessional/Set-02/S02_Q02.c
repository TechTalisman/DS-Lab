#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = value;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

void removeDuplicates(struct Node *head) {
    struct Node *current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *duplicate = current->next;

            current->next = duplicate->next;

            if (duplicate->next != NULL) {
                duplicate->next->prev = current;
            }

            free(duplicate);
        } else {
            current = current->next;
        }
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly linked list: ");

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

    printf("Enter sorted elements:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            freeList(head);
            return 1;
        }

        insertEnd(&head, value);
    }

    printf("Original list:\n");
    display(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    display(head);

    freeList(head);

    return 0;
}
