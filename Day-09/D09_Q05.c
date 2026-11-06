
#include <stdio.h>

int recursiveLinearSearch(int arr[], int n, int key, int index) {
    if (index >= n) {
        return -1;
    }

    if (arr[index] == key) {
        return index;
    }

    return recursiveLinearSearch(arr, n, key, index + 1);
}

int main(void) {
    int n, key;

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

    printf("Enter element to search: ");

    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int result = recursiveLinearSearch(arr, n, key, 0);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
