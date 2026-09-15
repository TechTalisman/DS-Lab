#include <stdio.h>

int findMax(int arr[], int index, int maximum)
{
    if (index < 0)
        return maximum;

    if (arr[index] > maximum)
        maximum = arr[index];

    return findMax(arr, index - 1, maximum);
}

int findMin(int arr[], int index, int minimum)
{
    if (index < 0)
        return minimum;

    if (arr[index] < minimum)
        minimum = arr[index];

    return findMin(arr, index - 1, minimum);
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Array must contain at least one element.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements in the array:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maximum = findMax(arr, n - 1, arr[0]);
    int minimum = findMin(arr, n - 1, arr[0]);

    printf("The maximum element in the array is: %d\n", maximum);
    printf("The minimum element in the array is: %d\n", minimum);

    return 0;
}
