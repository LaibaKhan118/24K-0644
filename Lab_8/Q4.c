/*Write a C program to multiply two matrices of size 3x3 and display the result matrix. Also
subtract the resultant matrix from Matrix A as well.*/

#include <stdio.h>

int main()
{
    int n = 3;
    // Input Matrices' Elements
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter Element %d of row %d:\t", j + 1, i + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    int arr2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter Element %d of row %d:\t", j + 1, i + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Display Matrices
    printf("\nMatrix 1:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("]\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arr2[i][j]);
        }
        printf("]\n");
    }
    printf("\n");

    // Multiply matrices
    int product[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            product[i][j] = arr[i][j] * arr2[i][j];
        }
    }

    // Display Multiplied version
    printf("\nMultiplied Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", product[i][j]);
        }
        printf("]\n");
    }
    printf("\n");

    // Subtracting the new matrix from matrix 1
    int subtract[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            subtract[i][j] = arr[i][j] - product[i][j];
        }
    }

    // Display Multiplied version
    printf("\nSubtracted Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", subtract[i][j]);
        }
        printf("]\n");
    }
    printf("\n");

    return 0;
}
