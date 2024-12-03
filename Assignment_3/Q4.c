#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **ratings;
    int totalScore;
} Employee;

void inputEmployees(Employee *employees, int numEmployees, int numPeriods);
void displayPerformance(Employee *employees, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(Employee *employees, int numEmployees, int numPeriods);
int findHighestRatedPeriod(Employee *employees, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(Employee *employees, int numEmployees, int numPeriods);

int main()
{
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    Employee employees;
    inputEmployees(&employees, numEmployees, numPeriods);

    displayPerformance(&employees, numEmployees, numPeriods);

    int bestEmployee = findEmployeeOfTheYear(&employees, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", bestEmployee + 1);

    int bestPeriod = findHighestRatedPeriod(&employees, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", bestPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(&employees, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++)
    {
        free(employees.ratings[i]);
    }
    free(employees.ratings);

    return 0;
}

void inputEmployees(Employee *employees, int numEmployees, int numPeriods)
{
    employees->ratings = (int **)malloc(numEmployees * sizeof(int *));
    employees->totalScore = 0;

    for (int i = 0; i < numEmployees; i++)
    {
        employees->ratings[i] = (int *)malloc(numPeriods * sizeof(int));

        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            do
            {
                printf("  Period %d (1-10): ", j + 1);
                scanf("%d", &employees->ratings[i][j]);
            } while (employees->ratings[i][j] < 1 || employees->ratings[i][j] > 10);

            employees->totalScore += employees->ratings[i][j];
        }
    }
}

void displayPerformance(Employee *employees, int numEmployees, int numPeriods)
{
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("%d ", employees->ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(Employee *employees, int numEmployees, int numPeriods)
{
    int bestEmployee = -1;
    double highestAverage = 0.0;

    for (int i = 0; i < numEmployees; i++)
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += employees->ratings[i][j];
        }
        double average = (double)total / numPeriods;

        if (average > highestAverage)
        {
            highestAverage = average;
            bestEmployee = i;
        }
    }

    return bestEmployee;
}

int findHighestRatedPeriod(Employee *employees, int numEmployees, int numPeriods)
{
    int bestPeriod = -1;
    double highestAverage = 0.0;

    for (int j = 0; j < numPeriods; j++)
    {
        int total = 0;
        for (int i = 0; i < numEmployees; i++)
        {
            total += employees->ratings[i][j];
        }
        double average = (double)total / numEmployees;

        if (average > highestAverage)
        {
            highestAverage = average;
            bestPeriod = j;
        }
    }

    return bestPeriod;
}

int findWorstPerformingEmployee(Employee *employees, int numEmployees, int numPeriods)
{
    int worstEmployee = -1;
    double lowestAverage = 11.0;

    for (int i = 0; i < numEmployees; i++)
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += employees->ratings[i][j];
        }
        double average = (double)total / numPeriods;

        if (average < lowestAverage)
        {
            lowestAverage = average;
            worstEmployee = i;
        }
    }

    return worstEmployee;
}
