#include <stdio.h>
#include <stdlib.h>

void insertion(int **ptr, int *len) {
    int element, index;

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    printf("Enter the position/index (0 to %d): ", *len);
    scanf("%d", &index);

    if (index < 0 || index > *len) {
        printf("Invalid index!\n");
        return;
    }

    int *temp = realloc(*ptr, (*len + 1) * sizeof(int));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = temp;

    for (int i = *len; i > index; i--) {
        (*ptr)[i] = (*ptr)[i - 1];
    }

    (*ptr)[index] = element;
    (*len)++;

    printf("New Array: ");
    for (int i = 0; i < *len; i++) {
        printf("%d ", (*ptr)[i]);
    }
    printf("\n");
}

void deletion(int **ptr, int *len) {
    int index;

    if (*len == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter the position/index to delete (0 to %d): ", *len - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *len) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < *len - 1; i++) {
        (*ptr)[i] = (*ptr)[i + 1];
    }

    (*len)--;

    if (*len == 0) {
        free(*ptr);
        *ptr = NULL;
    } else {
        int *temp = realloc(*ptr, (*len) * sizeof(int));

        if (temp != NULL) {
            *ptr = temp;
        }
    }

    printf("New Array: ");
    for (int i = 0; i < *len; i++) {
        printf("%d ", (*ptr)[i]);
    }
    printf("\n");
}

void search(int *ptr, int len) {
    int value;
    int found = 0;

    printf("Enter an element for linear search: ");
    scanf("%d", &value);

    for (int i = 0; i < len; i++) {
        if (ptr[i] == value) {
            printf("%d is present at index %d in the array.\n", value, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%d is absent in the array.\n", value);
    }
}

void traversal(int *ptr, int len) {
    printf("Traversal of the array: ");

    for (int i = 0; i < len; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\n");
}

int main() {
    int size, choice;

    printf("Enter the size of a 1-D array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements of the 1-D array: ", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Menu-Driven Array Operations ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Linear search\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion(&arr, &size);
                break;

            case 2:
                deletion(&arr, &size);
                break;

            case 3:
                search(arr, size);
                break;

            case 4:
                traversal(arr, size);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    free(arr);

    return 0;
}
