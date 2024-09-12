#include<stdio.h>
int main() {
	int num;
	printf("Enter a number:\t");
	scanf("%d", &num);
	if ((num >= 0) && (num % 2 == 0) && (num % 10 == 0))
		printf("This number is acceptable\n");
	else
		printf("This number is not acceptable\n");
	return 0;
}