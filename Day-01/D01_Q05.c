
#include <stdio.h>

typedef struct
{
    int emp_id;
    char name[100];
    char designation[100];
    int basic_salary;
    float hra_percent;
    float da_percent;
} Employee;

int main()
{
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    printf("\nEnter details of %d employees:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee-%d\n", i + 1);

        printf("Enter employee ID: ");
        scanf("%d", &employees[i].emp_id);

        printf("Enter name: ");
        scanf("%s", employees[i].name);

        printf("Enter designation: ");
        scanf("%s", employees[i].designation);

        printf("Enter basic salary: ");
        scanf("%d", &employees[i].basic_salary);

        printf("Enter HRA percentage: ");
        scanf("%f", &employees[i].hra_percent);

        printf("Enter DA percentage: ");
        scanf("%f", &employees[i].da_percent);
    }

    printf("\nInformation of %d employees:\n", n);

    for (i = 0; i < n; i++)
    {
        float hra = employees[i].basic_salary *
                    (employees[i].hra_percent / 100);

        float da = employees[i].basic_salary *
                   (employees[i].da_percent / 100);

        float gross_salary = employees[i].basic_salary + hra + da;

        printf("\nEmployee-%d\n", i + 1);
        printf("Employee ID: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: Rs. %.2f\n",
               (float)employees[i].basic_salary);
        printf("HRA: Rs. %.2f\n", hra);
        printf("DA: Rs. %.2f\n", da);
        printf("Gross Salary: Rs. %.2f\n", gross_salary);
    }

    return 0;
}
