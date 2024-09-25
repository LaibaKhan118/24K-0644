#include<stdio.h>
int main (){
	int weekday, vacation;
	printf("Is it a weekday? (Enter 0 for no and 1 for yes):\t");
	scanf("%d", &weekday);
	printf("Are you on Vacation? (Enter 0 for no and 1 for yes):\t");
	scanf("%d", &vacation);
	if (weekday == 0 || vacation == 1) {	
		printf("True");
	}        
	else
		printf("False");
	return 0;
}