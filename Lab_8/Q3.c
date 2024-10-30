/*Write a C program to find the saddle point(s) in each 3x3 matrix. A saddle point is an element
that is the smallest in its row and the largest in its column.*/

#include <stdio.h>

int main()
{
    int n = 3;
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
    for (int i = 0; i < n; i++)
    {
        printf("[  ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
    int min, max, c, flag = 0;
    for (int i = 0; i < n; i++)
    {
        min = arr[i][0];
        c = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                c = j;
            }
        }
        max = 0;
        for (int k = 0; k < n; k++)
        {
            if (arr[k][c] > max)
            {
                max = arr[k][c];
            }
        }
        if (min == max)
        {
            printf("Saddle point is: %d\n", max);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No Saddle point\n");
    }

    return 0;
}
