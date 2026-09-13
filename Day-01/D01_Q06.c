#include <stdio.h>

typedef struct
{
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2)
{
    Complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;

    return result;
}

void multiplyComplex(Complex *c1, Complex *c2, Complex *result)
{
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

void printComplex(Complex c)
{
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main()
{
    Complex c1, c2, result;
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter real and imaginary part of first complex number: ");
                scanf("%f %f", &c1.real, &c1.imag);

                printf("Enter real and imaginary part of second complex number: ");
                scanf("%f %f", &c2.real, &c2.imag);

                result = addComplex(c1, c2);

                printf("Sum: ");
                printComplex(result);
                break;

            case 2:
                printf("Enter real and imaginary part of first complex number: ");
                scanf("%f %f", &c1.real, &c1.imag);

                printf("Enter real and imaginary part of second complex number: ");
                scanf("%f %f", &c2.real, &c2.imag);

                multiplyComplex(&c1, &c2, &result);

                printf("Product: ");
                printComplex(result);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
