#include <stdio.h>

int main() {
	float salary, tax_rate, tax, income;
	printf("Enter the salary: \n");
	scanf("%f",&salary);
	printf("Enter the tax rate: \n");
	scanf("%f",&tax_rate);
	tax = (salary*tax_rate)/100;
	income = salary - tax;
	printf("The tax payble is %.2f\nYour salary after tax deduction would be %.2f\n", tax, income);
}