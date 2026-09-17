#include <stdio.h>

int fibonacci(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2 || n == 3) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Enter the value of n to find the nth Fibonacci number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int result = fibonacci(n);

    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}
