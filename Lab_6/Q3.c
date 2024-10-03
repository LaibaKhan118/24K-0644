#include<stdio.h>
int main() {
	int i, num, a=0, b=1, c;
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
		printf("The Series = ");
		do {
			printf("%d ", a);
			c = a + b;
			a = b;
			b = c;
		} while(a<=num);
	}
	else
		printf("This is not a prime number\n");
}