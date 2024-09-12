#include<stdio.h>
int main() {
	int num;
	printf("Enter a number:\t");
	scanf("%d", &num);
	if (num%3==0)
		printf("This number is multiple of 3\n");
	else
		printf("This number is not a multiple of 3");
	return 0;
}