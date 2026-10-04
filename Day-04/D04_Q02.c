#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int search(struct Node *head) {
    int value;
    int position = 1;

    printf("Enter element to be searched: ");
    scanf("%d", &value);

    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }

        position++;
        temp = temp->next;
    }

    return 0;
}

void sort(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *i = head;
    struct Node *j;
    int temp;

    while (i != NULL) {
        j = i->next;

        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }

            j = j->next;
        }

        i = i->next;
    }

    printf("List sorted in ascending order:\n");
    traverse(head);
}

void reverse(struct Node **head) {
    struct Node *previous = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;

    printf("List reversed:\n");
    traverse(*head);
}

void freeList(struct Node *head) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int numberOfNodes;
    int choice;
    int data;

    struct Node *head = NULL;
    struct Node *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &numberOfNodes);

    if (numberOfNodes <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return 1;
    }

    printf("Enter the elements: ");

    for (int i = 0; i < numberOfNodes; i++) {
        scanf("%d", &data);

        struct Node *newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            freeList(head);
            return 1;
        }

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Search an element\n");
        printf("2. Sort the list in ascending order\n");
        printf("3. Reverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int position = search(head);

                if (position != 0) {
                    printf("Element found at node %d.\n", position);
                } else {
                    printf("Element is not present in the list.\n");
                }

                break;
            }

            case 2:
                sort(head);
                break;

            case 3:
                reverse(&head);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    freeList(head);

    return 0;
}
