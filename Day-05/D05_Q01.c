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

struct Node* createDoublyLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("The number of nodes must be greater than zero.\n");
        return NULL;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }

    return head;
}

void displayDoublyLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayDoublyLinkedList(head);

    return 0;
}
