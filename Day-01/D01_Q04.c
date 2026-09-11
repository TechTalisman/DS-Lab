#include <stdio.h>

int isPrime(int number)
{
    int i;

    if (number < 2)
        return 0;

    for (i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int number;

    printf("Enter number: ");
    scanf("%d", &number);

    if (isPrime(number))
        printf("%d is a prime number\n", number);
    else
        printf("%d is not a prime number\n", number);

    return 0;
}
