#include<stdio.h>
int main() {
	int i, num;
	int prime = 1;
	printf("Enter a number to check:\t");
	scanf("%d", &num);
	for(i = 2; i < num; i++){
		if(num%i==0){
			prime = 0;
			break;
		}
	}
	if (prime == 1) {
		printf("This is a prime number\n");
	}
	else
		printf("This is not a prime number\n");
}