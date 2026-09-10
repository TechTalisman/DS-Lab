#include <stdio.h>

int sumOfDigits(int number)
{
    if (number < 10)
        return number;
    else
        return number % 10 + sumOfDigits(number / 10);
}

int main()
{
    int number, sum;

    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    if (number < 1000 || number > 9999)
    {
        printf("Please enter a valid four-digit number.\n");
        return 1;
    }

    sum = sumOfDigits(number);

    printf("\nSum of digits of %d is %d\n", number, sum);

    return 0;
}
