#include <stdio.h>

struct Distance {
    int feet;
    int inches;
};

void add(struct Distance* d1, struct Distance* d2, struct Distance* result) {
    result->feet = d1->feet + d2->feet;
    result->inches = d1->inches + d2->inches;


    if (result->inches >= 12) {
        result->feet += result->inches / 12;
        result->inches = result->inches % 12;
    }
}

int main() {
    struct Distance d1, d2, result;

    printf("Enter the first distance (feet and inches): ");
    scanf("%d %d", &d1.feet, &d1.inches);

    printf("Enter the second distance (feet and inches): ");
    scanf("%d %d", &d2.feet, &d2.inches);

    add(&d1, &d2, &result);

    printf("The total distance is %d feet %d inches.\n", result.feet, result.inches);

    return 0;
}
