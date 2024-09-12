#include<stdio.h>
int main() {
	char ch;
	printf("Enter a charachter:\t");
	scanf("%c", &ch);
	if (ch >= 48 && ch <= 57)
		printf("This is a Number\n");
	else if (ch >= 65 && ch <= 90)
		printf("This is a Capital Letter\n");
	else if (ch >= 97 && ch <= 122)
		printf("This is a Small Letter\n");
	else
		printf("This is a speacial Character\n"); 
	return 0;
}