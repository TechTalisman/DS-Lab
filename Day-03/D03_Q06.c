#include <stdio.h>

void displayPolynomial(int poly[], int degree) {
    int first = 1;

    for (int i = degree; i >= 0; i--) {
        if (poly[i] == 0) {
            continue;
        }

        if (!first) {
            if (poly[i] > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (poly[i] < 0) {
            printf("-");
        }

        int coefficient = poly[i] < 0 ? -poly[i] : poly[i];

        if (i == 0) {
            printf("%d", coefficient);
        } else if (i == 1) {
            if (coefficient != 1) {
                printf("%d", coefficient);
            }
            printf("x");
        } else {
            if (coefficient != 1) {
                printf("%d", coefficient);
            }
            printf("x^%d", i);
        }

        first = 0;
    }

    if (first) {
        printf("0");
    }

    printf("\n");
}

int main() {
    int deg1, deg2;

    printf("Enter the maximum degree of the first polynomial: ");
    scanf("%d", &deg1);

    int poly1[deg1 + 1];

    printf("Enter coefficients for Polynomial-1 from lowest degree to highest degree: ");

    for (int i = 0; i <= deg1; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the maximum degree of the second polynomial: ");
    scanf("%d", &deg2);

    int poly2[deg2 + 1];

    printf("Enter coefficients for Polynomial-2 from lowest degree to highest degree: ");

    for (int i = 0; i <= deg2; i++) {
        scanf("%d", &poly2[i]);
    }

    int maxDegree = (deg1 > deg2) ? deg1 : deg2;
    int result[maxDegree + 1];

    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }

    for (int i = 0; i <= deg1; i++) {
        result[i] += poly1[i];
    }

    for (int i = 0; i <= deg2; i++) {
        result[i] += poly2[i];
    }

    printf("\nResultant Polynomial: ");
    displayPolynomial(result, maxDegree);

    return 0;
}
