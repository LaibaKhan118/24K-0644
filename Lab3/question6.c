#include <stdio.h>

int main()
{
	float x1, x2, y1, y2, slope;
	printf("Enter the value of x1: \t");
	scanf("%f", &x1);
	printf("Enter the value of x2: \t");
	scanf("%f", &x2);
	printf("Enter the value of y1: \t");
	scanf("%f", &y1);
	printf("Enter the value of y2: \t");
	scanf("%f", &y2);
	slope = (y2 - y1) / (x2 - x1);
	printf("The slope is %.3f\n", slope);
}