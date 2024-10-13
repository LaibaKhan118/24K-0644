// Check if a given iISBN is corret or not
#include<stdio.h>
int main() {
	char isbn[10];
	int sum = 0;
	printf("Enter ISBN:\t");
	scanf("%10s", isbn);
	for (int i = 0; i < 10; i++) {
	    if (isbn[i] == '\0') {
	        printf("Invalid input. The ISBN must be 10 charachers long\n");
	        return 0;
	    }
	}
	for (int i = 9, j = 1; i >= 0, j <= 10; i--, j++) {
		switch(isbn[i]) {
			case '0':
				sum += 0*j;
				break;
			case '1':
				sum += 1*j;
				break;
			case '2':
				sum += 2*j;
				break;
			case '3':
				sum += 3*j;
				break;
			case '4':
				sum += 4*j;
				break;
			case '5':
				sum += 5*j;
				break;
			case '6':
				sum += 6*j;
				break;
			case '7':
				sum += 7*j;
				break;
			case '8':
				sum += 8*j;
				break;
			case '9':
				sum += 9*j;
				break;
			case 'x':
			case 'X':
				sum += 10*j;
				break;
			default:
				printf("Invalid Input\n");
				return 0;
		}
	}
	if (sum % 11 == 0)
		printf("This is a valid ISBN\n");
	else
		printf("This is not a valid ISBN\n");
	return 0;
}
