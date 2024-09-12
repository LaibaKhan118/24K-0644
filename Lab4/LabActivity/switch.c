#include<stdio.h>
int main() {
	int num;
	char letter;
	printf("Enter letter:\t");
	scanf("%c", &letter);
	printf("Enter number:\t");
	scanf("%d", &num);
	switch (letter) {
		case ('a' || 'A'):
			switch (num) {
				case 1:
					printf("April\n");
					break;
				case 2:
					printf("August\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('d'):
		case ('D'):
			switch (num) {
				case 1:
					printf("December\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('f'):
		case ('F'):
			switch (num) {
				case 1:
					printf("Feburary\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('j'):
		case ('J'):
			switch (num) {
				case 1:
					printf("January\n");
					break;
				case 2:
					printf("June\n");
					break;
				case 3:
					printf("July\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('m'):
		case ('M'):
			switch (num) {
				case 1:
					printf("March\n");
					break;
				case 2:
					printf("May\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('n'):
		case ('N'):
			switch (num) {
				case 1:
					printf("November\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('o'):
		case ('O'):
			switch (num) {
				case 1:
					printf("October\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		case ('s'):
		case ('S'):
			switch (num) {
				case 1:
					printf("September\n");
					break;
				default:
					printf("Month doesn't Exist\n");
			}
			break;
		default:
			printf("Month doesn't Exist\n");
	}
}