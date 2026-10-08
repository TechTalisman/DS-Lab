#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void append(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct Node* head) {
    printf("Doubly Linked List: ");

    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" <-> ");
        }

        head = head->next;
    }

    printf(" -> NULL\n");
}

void reverse(struct Node** head_ref) {
    struct Node* temp = NULL;
    struct Node* current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("\nOriginal Doubly Linked List:\n");
    display(head);

    reverse(&head);

    printf("\nReversed Doubly Linked List:\n");
    display(head);

    return 0;
}
