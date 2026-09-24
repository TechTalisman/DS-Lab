
#include <stdio.h>

// Define the structure Date
struct Date {
    int day;
    int month;
    int year;
};

// Define the structure Employee with nested Date structure
struct Employee {
    int emp_id;
    char name[50];
    struct Date doj;
};

int main() {
    struct Employee emp;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", emp.name);

    // Input date of joining details
    printf("Enter Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp.doj.day, &emp.doj.month, &emp.doj.year);

    // Display employee details
    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Employee Name: %s\n", emp.name);
    printf("Date of Joining: %02d-%02d-%04d\n",
           emp.doj.day,
           emp.doj.month,
           emp.doj.year);

    return 0;
}
