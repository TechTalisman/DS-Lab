#include <stdio.h>

typedef struct
{
    char name[100];
    int age;
    int total_marks;
} Student;

int main()
{
    Student students[2];
    int i;
    float average;

    printf("Enter details of the students:\n");

    for (i = 0; i < 2; i++)
    {
        printf("\nStudent-%d\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);

        printf("Enter total marks: ");
        scanf("%d", &students[i].total_marks);
    }

    printf("\nDetails of the students:\n");

    for (i = 0; i < 2; i++)
    {
        printf("\nStudent-%d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Total Marks: %d\n", students[i].total_marks);
    }

    average = (students[0].total_marks + students[1].total_marks) / 2.0;

    printf("\nAverage marks of 2 students: %.2f\n", average);

    return 0;
}
