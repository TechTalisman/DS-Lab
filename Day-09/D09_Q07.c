
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

void recursiveSelectionSort(int arr[], int n, int index) {
    if (index >= n - 1) {
        return;
    }

    int minIndex = findMinIndex(arr, index, n - 1);

    if (minIndex != index) {
        swap(&arr[index], &arr[minIndex]);
    }

    recursiveSelectionSort(arr, n, index + 1);
}

int main(void) {
    int n;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[n];

    printf("Enter elements of the array:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    recursiveSelectionSort(arr, n, 0);

    printf("Sorted array in ascending order:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
