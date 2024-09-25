#include<stdio.h>
int main() {
	float cost, saved, new;
	printf("Enter the cost of shopping:\t");
	scanf("%f", &cost);
	if(cost >= 500.00) {
		if(cost < 2000.00) {
			saved = (5*cost)/100;
			new = cost - saved;
		}
		else if (cost >= 2000.00 && cost < 4000.00) {
			saved = (10 * cost)/100;
			new = cost - saved;
		}
		else if (cost >= 4000.00 && cost < 6000.00) {
			saved = (20 * cost)/100;
			new = cost - saved;
		}
		else {
			saved = (35 * cost)/100;
			new = cost - saved;
		}
		printf("Your Total was: %.2f\nAfter Discount, you Saved: %.2f\nYour New Total is: %.2f\n", cost, saved, new);
	}
	else
	printf("you are not eligible for a discount\n");
	return 0;
}