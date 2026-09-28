#include <stdio.h>

void sorting(int *arr, int len) {
    int temp;

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion(int *arr, int len) {
    int element, index = 0;

    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);

    while (index < len && arr[index] < element) {
        index++;
    }

    int result[len + 1];

    for (int i = 0; i < len + 1; i++) {
        if (i < index) {
            result[i] = arr[i];
        } else if (i == index) {
            result[i] = element;
        } else {
            result[i] = arr[i - 1];
        }
    }

    printf("\nNew Array: ");
    for (int i = 0; i < len + 1; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
}

int main() {
    int size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d elements of the array: ", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    sorting(arr, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    insertion(arr, size);

    return 0;
}
