/*Design a structure to store information about travel packages, including package name,
destination, duration, cost, and number of seats available. Write a program that allows
users to book a travel package and display available packages.*/

#include <stdio.h>

typedef struct
{
    char name[50];
    char dest[50];
    int duration;
    float cost;
    int n_seats;
} Package;

void displayPackages(Package packages[], int count);
void bookPackage(Package packages[], int count);

int main()
{
    int c;
    Package packages[3] = {
        {"Adventure Trip", "Amazon Rainforest", 7, 1500.00, 10},
        {"Beach Paradise", "Maldives", 5, 2000.00, 5},
        {"Cultural Tour", "Italy", 10, 2500.00, 8}};

    while (1)
    {
        printf("\nTravel Booking System\n1. View Available Packages\n2. Book a Package\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            displayPackages(packages, 3);
            break;
        case 2:
            bookPackage(packages, 3);
            break;
        case 3:
            printf("Exiting the system. Thank you!\n");
            return 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayPackages(Package packages[], int count) {
    printf("\nAvailable packages:\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nPackage %d\n", i+1);
        printf("Package Name: %s\n", packages[i].name);
        printf("Destination: %s\n", packages[i].dest);
        printf("Duration: %d\n", packages[i].duration);
        printf("Cost: %.2f\n", packages[i].cost);
        printf("No of Seats: %d\n", packages[i].n_seats);
    }
}

void bookPackage(Package packages[], int count) {
    int c;
    printf("Enter the number of the package you want to book: ");
    scanf("%d", &c);

    if (c < 1 || c > count)
    {
        printf("Invalid package number. Please try again.\n");
        return;
    }

    if (packages[c - 1].n_seats > 0)
    {
        packages[c - 1].n_seats--;
        printf("Booking successful for package '%s'. Remaining seats: %d\n",
               packages[c - 1].name, packages[c - 1].n_seats);
    }
    else
    {
        printf("Sorry, no seats available for package '%s'.\n", packages[c - 1].name);
    }
}
