#include <stdio.h>

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }

    return findGCD(b, a % b);
}

int main() {
    int num1, num2, gcd;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    gcd = findGCD(num1, num2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
