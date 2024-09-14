#include<stdio.h>
int main() {
	// Havn't learned strings to input a name
	int id;
	float units, bill, surcharge, total;
	printf("Customer ID:\t");
	scanf("%d", &id);
	printf("Units Consumed:\t");
	scanf("%f", &units);
	if (units <= 199) {
		bill = units * 16.20;
		printf("Amount charges @Rs. %.2f per unit: %.2f\n", 16.20, bill);
	}
	else if (units >= 200 && units < 300) {
		bill = units * 20.10;
		printf("Amount charges @Rs. %.2f per unit: %.2f\n", 20.10, bill);
	}
	else if (units >= 300 && units < 500) {
		bill = units * 27.10;
		printf("Amount charges @Rs. %.2f per unit: %.2f\n", 27.10, bill);
	}
	else {
		bill = units * 35.90;
		printf("Amount charges @Rs. %.2f per unit: %.2f\n", 35.90, bill);
	}
	
	if (bill > 18000) {
		surcharge = (15 * bill) / 100;
	}
	else {
		surcharge = 0.00;
	}
	printf("Surcharge Amount: %.2f\n", surcharge);
	total = bill + surcharge;
	printf("Net Amount Payable: %.2f\n", total);

}
























