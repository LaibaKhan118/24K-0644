/*Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of
each employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.*/

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int employeeCode;
    char employeeName[100];
    struct tm dateOfJoining; // using pre-defined structure of date
} Employee;


void Data(Employee *emp);

void Tenure(Employee emp[], int n);

int main() {
    Employee employees[4];
    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        Data(&employees[i]);
    }
    Tenure(employees, 4);
    return 0;
}

void Data(Employee *emp)
{
    printf("Enter code: ");
    scanf("%d", &emp->employeeCode);
    printf("Enter name: ");
    scanf(" %[^\n]s", emp->employeeName);
    printf("Enter date of joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp->dateOfJoining.tm_mday, &emp->dateOfJoining.tm_mon, &emp->dateOfJoining.tm_year);
    emp->dateOfJoining.tm_mon -= 1;
    emp->dateOfJoining.tm_year -= 1900;
}

void Tenure(Employee emp[], int n)
{
    int count = 0;
    time_t now;
    struct tm current;
    time(&now);
    current = *localtime(&now);

    printf("\nEmployees with tenure > 3 years:\n");

    for (int i = 0; i < n; i++)
    {
        int tenure = current.tm_year - emp[i].dateOfJoining.tm_year;
        if (current.tm_mon < emp[i].dateOfJoining.tm_mon || (current.tm_mon == emp[i].dateOfJoining.tm_mon && current.tm_mday < emp[i].dateOfJoining.tm_mday))
        {
            tenure--;
        }

        if (tenure > 3)
        {
            printf("\nCode: %d\n", emp[i].employeeCode);
            printf("Name: %s\n", emp[i].employeeName);
            printf("DOJ: %02d-%02d-%04d\n", emp[i].dateOfJoining.tm_mday, emp[i].dateOfJoining.tm_mon + 1, emp[i].dateOfJoining.tm_year + 1900);
            printf("Tenure: %d years\n", tenure);
            count++;
        }
    }

    printf("\nTotal: %d\n", count);
}
