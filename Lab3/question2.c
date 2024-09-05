#include <stdio.h>

int main() {
	int a, b, temp;
	printf("Enter the first number(a): \n");
	scanf("%d",&a);
	printf("Enter the second number(b): \n");
	scanf("%d",&b);
	temp = a;
	a = b;
	b = temp;
	printf("a is: %d and b is: %d", a, b);
}