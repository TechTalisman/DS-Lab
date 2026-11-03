
#include <stdio.h>

void binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        } 
        else if (arr[mid] < key) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    printf("Element not found.\n");
}

int main(void) {
    int n, key;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[n];

    printf("Enter sorted elements of the array:\n");

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

    binarySearch(arr, n, key);

    return 0;
}
