#include<stdio.h>
int main() {
	float num1, num2;
	char sign;
	printf("Select an operand 1:\t");
	scanf("%f", &num1);
	printf("Select an operand 2:\t");
	scanf("%f", &num2);
	printf("Select an operation (- + * /):\t");
	scanf(" %c", &sign);
	
	switch(sign) {
		case '+':
			printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
			break;
		case '/':
			if (num2 != 0)
				printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
			else
				printf("Undefined\n");
			break;
		default:
			printf("Wrong Operand\n");
	}
	return 0;
}