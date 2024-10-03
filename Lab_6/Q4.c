#include<stdio.h>
int main() {
	int i, num, original, digi;
	int sum = 0;
	printf("Enter a number to check:\t");
	scanf("%d", &num);
	original = num;
	while(num!=0) {
		digi = num % 10;
		sum = sum + (digi*digi*digi);
		num = num/10;
	}
	if(original == sum) {
		printf("This is an Armstrong Number\n");
	}
	else {
		printf("This is not an Armstrong Number\n");
	}
}