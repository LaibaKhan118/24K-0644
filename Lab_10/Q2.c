#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Coordinates;

float tri_area(Coordinates p1, Coordinates p2, Coordinates p3);
int check(Coordinates p1, Coordinates p2, Coordinates p3, Coordinates p4, Coordinates p);

int main()
{
    Coordinates A, B, C, D, point;
    printf("Enter the  coordinates of the top-right point:\n");
    printf("X:");
    scanf("%f", &A.x);
    printf("Y:");
    scanf("%f", &A.y);

    printf("Enter the  coordinates of the bottom-right point:\n");
    printf("X:");
    scanf("%f", &B.x);
    printf("Y:");
    scanf("%f", &B.y);

    printf("Enter the  coordinates of the bottom-left point:\n");
    printf("X:");
    scanf("%f", &C.x);
    printf("Y:");
    scanf("%f", &C.y);

    printf("Enter the coordinates of the top-left point:\n");
    printf("X:");
    scanf("%f", &D.x);
    printf("Y:");
    scanf("%f", &D.y);

    printf("Enter the  coordinates of the point to check:\n");
    printf("X:");
    scanf("%f", &point.x);
    printf("Y:");
    scanf("%f", &point.y);

    int result = check(A, B, C, D, point);
    if (result == 1)
    {
        printf("\nYes\n");
    }
    else
    {
        printf("\nNo\n");
    }
    return 0;
}

float tri_area(Coordinates p1, Coordinates p2, Coordinates p3)
{
    float area = fabs(((p1.x) * (p2.y - p3.y) + (p2.x) * (p3.y - p1.y) + (p3.x) * (p1.y - p2.y)) / 2.0);
    return area;
}
int check(Coordinates p1, Coordinates p2, Coordinates p3, Coordinates p4, Coordinates p)
{
    float rect_area = tri_area(p1, p2, p3) + tri_area(p1, p4, p3);
    float A1 = tri_area(p1, p2, p);
    float A2 = tri_area(p3, p4, p);
    float A3 = tri_area(p1, p4, p);
    float A4 = tri_area(p2, p3, p);
    float sum = A1 + A2 + A3 + A4;

    const float EPSILON = 1e-6;
    if (fabs(sum - rect_area) < EPSILON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
