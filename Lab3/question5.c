#include <stdio.h>

int main()
{
	float P, R, T, interest;
	printf("Enter the Princpal (ranging from 100 to 1000000): \t");
	scanf("%f", &P);
	printf("Enter the Rate of Interest (ranging from 5 to 10 percent): \t");
	scanf("%f", &R);
	printf("Enter the Time Period (ranging from 1 to 10 years): \t");
	scanf("%f", &T);
	interest = (P * R * T) / 100.0;
	printf("The simple interest is %.2f\n", interest);
}