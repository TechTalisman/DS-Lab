#include <stdio.h>

int reverseNumber(int n, int reverse) {
    if (n == 0) {
        return reverse;
    }

    reverse = reverse * 10 + n % 10;
    return reverseNumber(n / 10, reverse);
}

void checkPalindrome(int number, int reverse) {
    if (number == reverse) {
        printf("%d is a palindrome number.\n", number);
    } else {
        printf("%d is not a palindrome number.\n", number);
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    int reverse = reverseNumber(number, 0);
    checkPalindrome(number, reverse);

    return 0;
}
