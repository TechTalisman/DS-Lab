
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

struct Student getdetail() {
    struct Student s;

    printf("Enter student name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter student age: ");
    scanf("%d", &s.age);

    printf("Enter student marks: ");
    scanf("%f", &s.marks);

    return s;
}

int main() {
    struct Student student;

    student = getdetail();

    printf("\nStudent Details\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}
