#include <stdio.h>

int reverseNumber(int num, int rev) {
   
    if (num == 0) {
        return rev;
    } else {
        rev = rev*10 + num%10;
        return reverseNumber(num/10, rev);
    }
}

int main() {
    int num, reversedNum;

    printf("Enter a number: ");
    scanf("%d", &num);

    reversedNum = reverseNumber(num, 0);

    printf("The reversed number is: %d\n", reversedNum);

    return 0;
}
