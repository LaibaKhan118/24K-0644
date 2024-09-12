#include<stdio.h>
int main() {
	int num;
	char letter;
	printf("Enter letter:\t");
	scanf("%c", &letter);
	printf("Enter number:\t");
	scanf("%d", &num);
	if ((letter == 'a' || letter == 'A') && num == 1)
		printf("April\n");
	else if ((letter == 'a' || letter == 'A') && num == 2)
		printf("August\n");
	else if ((letter == 'd' || letter == 'D') && num == 1)
		printf("December\n");
	else if ((letter == 'f' || letter == 'F') && num == 1)
		printf("Feburary\n");
	else if ((letter == 'j' || letter == 'J') && num == 1)
		printf("January\n");
	else if ((letter == 'j' || letter == 'J') && num == 2)
		printf("June\n");
	else if ((letter == 'j' || letter == 'J') && num == 3)
		printf("July\n");
	else if ((letter == 'm' || letter == 'M') && num == 1)
		printf("March\n");
	else if ((letter == 'm' || letter == 'M') && num == 2)
		printf("May\n");
	else if ((letter == 'n' || letter == 'N') && num == 1)
		printf("November\n");
	else if ((letter == 'o' || letter == 'O') && num == 1)
		printf("October\n");
	else if ((letter == 's' || letter == 'S') && num == 1)
		printf("September\n");
	else
		printf("Month doesn't Exist\n");
}