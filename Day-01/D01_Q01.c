#include <stdio.h>

void callByValue(int num1, int num2)
{
    printf("\nUsing Call By Value\n");
    printf("num1: %d\nnum2: %d\n", num1, num2);

    if (num1 > num2)
    {
        printf("%d is greater than %d\n", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("%d is greater than %d\n", num2, num1);
    }
    else
    {
        printf("Both are equal\n");
    }
}

void callByAddress(int *num1, int *num2)
{
    printf("\nUsing Call By Address\n");
    printf("The numbers are %d and %d\n", *num1, *num2);

    if (*num1 > *num2)
    {
        printf("%d is greater than %d\n", *num1, *num2);
    }
    else if (*num1 < *num2)
    {
        printf("%d is greater than %d\n", *num2, *num1);
    }
    else
    {
        printf("Both are equal\n");
    }
}

int main()
{
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    callByValue(num1, num2);
    callByAddress(&num1, &num2);

    return 0;
}
