#include <stdio.h>

struct Point {
    int x;
    int y;
};

void display(struct Point p) {
    printf("Point coordinates are: (%d, %d)\n", p.x, p.y);
}

int main() {
    struct Point p1;

    printf("Enter the coordinates (x y) of the point: ");
    scanf("%d %d", &p1.x, &p1.y);

    display(p1);

    return 0;
}
