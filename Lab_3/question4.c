#include <stdio.h>

int main()
{
	int fuel_avg, forward_fuel, return_fuel, fuel_used, total_fuel;
	printf("Enter you car's fuel average (km/liter): \t");
	scanf("%d", &fuel_avg);
	// We could've used if-else statement but it would only check once, and we won't be able to check if the user entered the wrong number again. 
	while (fuel_avg <=0) {
		printf("Please Enter a positive number that is greater than zero:\t");
		scanf("%d", &fuel_avg);
	}
	fuel_used = 1207 / fuel_avg;
	forward_fuel = fuel_used * 118;
	return_fuel = fuel_used * 123;
	total_fuel = forward_fuel + return_fuel;
	printf("The fuel used in the trip forward costed %d\nThe fuel used in the trip back costed %d\nTotal fuel cost is %d\n", forward_fuel, return_fuel, total_fuel);
}
