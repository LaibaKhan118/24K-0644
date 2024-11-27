/*Q: Define a structure Employee with fields name, id, salary, and a nested structure Address
(fields: city and zip_code). Write a program to input details for multiple employees,
store them in a file, and read them back to display.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char city[50];
    int zip;
} Address;

typedef struct
{
    char name[50];
    int id;
    float salary;
    Address residence;
} EmployeeInfo;

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    EmployeeInfo employee[n];

    FILE *fptr = fopen("employee_data.txt", "w+");

    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("\nEnter the name of employee %d: ", i + 1);
        fgets(employee[i].name, sizeof(employee[i].name), stdin);
        employee[i].name[strcspn(employee[i].name, "\n")] = '\0';
        printf("Enter the ID of employee %d: ", i + 1);
        scanf("%d", &employee[i].id);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &employee[i].salary);
        getchar();
        printf("Enter the city of the residence of employee %d: ", i + 1);
        fgets(employee[i].residence.city, sizeof(employee[i].residence.city), stdin);
        employee[i].residence.city[strcspn(employee[i].residence.city, "\n")] = '\0';
        printf("Enter the zip code of the residence of employee %d: ", i + 1);
        scanf("%d", &employee[i].residence.zip);

        fprintf(fptr, "Employee %d:\n  Name: %s\n  ID: %d\n  Salary: %.2f\n  Address: %s, %d\n\n", i + 1, employee[i].name, employee[i].id, employee[i].salary, employee[i].residence.city, employee[i].residence.zip);
    }

    rewind(fptr);
    printf("\n");
    char ch;
    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }

    fclose(fptr);
    return 0;
}
