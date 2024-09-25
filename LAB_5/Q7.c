#include<stdio.h>
int main() {
	int num;
	printf("Enter Num:\t");
	scanf("%d", &num);
	((num % 10 == 0) ? printf("Last Digit is Zero") : printf("Last Digit is non-zero"));
	return 0;
}