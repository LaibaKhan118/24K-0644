// while loop or do while loop would be better for user input instead of for loop because while/ do-while are unconditional loops. We do not need to know 

#include<stdio.h>
int main() {
	int i;
	int sum = 0;
	do {
		printf("Enter a number (Enter zero to stop giving inputs):\t");
		scanf("%d", &i);
		sum += i;
	} while (i != 0);
	printf("Sum is: %d", sum);
}