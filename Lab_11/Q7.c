/*Q: Define a structure Company with fields name, year_established, and an array
departments containing the names of up to 5 departments. Write a program to display
company details including all departments.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int estab_yr;
    char departs[5][50];
} Company;

int main()
{
    int n, d_n;
    printf("Enter the number of companies: ");
    scanf("%d", &n);
    getchar();
    Company companies[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of company %d: ", i + 1);
        fgets(companies[i].name, sizeof(companies[i].name), stdin);
        companies[i].name[strcspn(companies[i].name, "\n")] = '\0';
        printf("Enter the year of establishment of company %d: ", i + 1);
        scanf("%d", &companies[i].estab_yr);
        printf("Enter the number of departments in the company %d: ", i + 1);
        scanf("%d", &d_n);
        getchar();
        for (int j = 0; j < d_n; j++)
        {
            printf("  Enter the name of department %d: ", j + 1);
            fgets(companies[i].departs[j], sizeof(companies[i].departs[j]), stdin);
            companies[i].departs[j][strcspn(companies[j].departs[j], "\n")] = '\0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Company %d Details:\nName: %s\nEstablishment Year: %d\nDepartments:\n", i + 1, companies[i].name, companies[i].estab_yr);
        for (int j = 0; j < d_n; j++)
        {
            printf("  %d. %s\n", j + 1, companies[i].departs[j]);
        }
        printf("\n");
    }

    return 0;
}
