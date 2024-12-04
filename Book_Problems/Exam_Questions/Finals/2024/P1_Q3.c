/*Q3: Triangle Area Using Heron’s Formula & Sorting

1. Take the sides of a triangle and calculate its area using Heron’s formula:
    S = \sqrt{p(p-a)(p-b)(p-c)}
2. Sort the calculated areas of multiple triangles in ascending order.
3. It is guaranteed that all areas are unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcArea(float a, float b, float c);
void sort(double *areas, int n);

int main()
{
    int n;
    printf("Enter the number of triangles: ");
    scanf("%d", &n);

    double *areas = (double *)calloc(n, sizeof(double));
    if (areas == NULL)
    {
        printf("Error whle allocating memory.\n");
        return 0;
    }
    float a, b, c;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the side a: ");
        scanf("%f", &a);
        printf("Enter the side b: ");
        scanf("%f", &b);
        printf("Enter the side c: ");
        scanf("%f", &c);

        areas[i] = calcArea(a, b, c);

        if (areas[i] <= 0)
        {
            printf("Invalid side inputs.\n");
            i--;
        }
        else
        {
            printf("Area of triangle %d: %lf\n", i + 1, areas[i]);
        }
    }

    sort(areas, n);

    printf("\nList of areas in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Area of triangle %d: %lf\n", i + 1, areas[i]);
    }

    free(areas);

    return 0;
}

double calcArea(float a, float b, float c)
{
    double p = (a + b + c) / 2.0;
    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}
void sort(double *areas, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (areas[j] > areas[j + 1])
            {
                int temp = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = temp;
            }
        }
    }
}