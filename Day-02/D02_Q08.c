#include <stdio.h>

struct Point {
    int x;
    int y;
};

void modify(struct Point* p) {
    p->x += 5;
    p->y += 5;
}

int main() {
    struct Point p1;

    printf("Enter the coordinates (x y) of the point: ");
    scanf("%d %d", &p1.x, &p1.y);

    modify(&p1);

    printf("Modified point coordinates are: (%d, %d)\n", p1.x, p1.y);

    return 0;
}
