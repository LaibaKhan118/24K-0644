/*You are tasked with creating a program that generates a histogram based on user input. The user will provide a set of values, and your program will use loops to create a visual representation of
these values.
1. Input Handling: Write a function that takes an array of integers (the values) and the count of those integers as input.
2. Horizontal Histogram Function: Use loops to generate and print a histogram, where each value is represented by asterisks (*).
3. Vertical Histogram Function: Use loops to generate and print a vertical histogram, where each value is represented by asterisks (*).
*/

#include <stdio.h>

void horizontal(int arr[], int n);
void vertical(int arr[], int n);
int main()
{
    int arr[100];
    int n;
    printf("Enter the number of integers:\t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter integer %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }

    horizontal(arr, n);
    vertical(arr, n);
    return 0;
}

void horizontal(int arr[], int n)
{
    printf("\nHorizontal Histogram\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value %d (%d): ", i + 1, arr[i]);

        // Print '*' arr[i] times
        for (int j = 0; j < arr[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void vertical(int arr[], int n)
{
    // find max value in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("\nVertical Histogram\n\n");

    // Starting from the max value, print '*' for each value that is greater or equal to it
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    // Display the number of '*' printed in each column
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
