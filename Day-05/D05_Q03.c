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

int isEmpty(struct Node* head) {
    return head == NULL;
}

void traverseForward(struct Node* head) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    printf("List (forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* head) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    while (head->next != NULL) {
        head = head->next;
    }

    printf("List (backward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void deleteByKey(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

int countNodes(struct Node* head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int search(struct Node* head, int key) {
    int position = 1;

    while (head != NULL) {
        if (head->data == key) {
            return position;
        }

        head = head->next;
        position++;
    }

    return -1;
}

void freeList(struct Node** head) {
    struct Node* temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    do {
        printf("\nMenu:\n");
        printf("1. Traverse forward\n");
        printf("2. Traverse backward\n");
        printf("3. Check if list is empty\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at position\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Delete at position\n");
        printf("10. Delete by key\n");
        printf("11. Count nodes\n");
        printf("12. Search for element\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeList(&head);
            return 1;
        }

        switch (choice) {
            case 1:
                traverseForward(head);
                break;

            case 2:
                traverseBackward(head);
                break;

            case 3:
                printf(isEmpty(head) ? "List is empty.\n" : "List is not empty.\n");
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 6:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 7:
                deleteAtBeginning(&head);
                break;

            case 8:
                deleteAtEnd(&head);
                break;

            case 9:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 10:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(&head, key);
                break;

            case 11:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;

            case 12:
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = search(head, key);

                if (position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 13:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 13);

    freeList(&head);
    return 0;
}
