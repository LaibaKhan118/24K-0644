#include<stdio.h>
int main() {
	// In question it says to ask if coffe size is double or manual... I am assuming that 'manual' is a typo and it was 'single'
	char type, size;
	int water, sugar, mix1, coffee, milk, mix2, total;
	printf("What type of coffee? (Enter b for black and w for white):\t");
	scanf("%c", &type);
	printf("What size do you want? (Enter d for double and s for single):\t");
	scanf(" %c", &size);
	switch (type){
		case 'w':
		case 'W':
			water = 15;
			sugar = 15;
			mix1 = 20;
			coffee = 2;
			milk = 4;
			mix2 = 20;
			total = water+sugar+mix1+coffee+milk;mix2;
			switch (size) {
				case 'd':
				case 'D':
					printf("Put Water -> time: %.2f minutes\n", water*1.5);
					printf("Sugar -> time: %.2f minutes\n", sugar*1.5);
					printf("Mix Well -> time: %.2f minutes\n", mix1)*1.5;
					printf("Add Coffee -> time: %.2f minutes\n", coffee*1.5);
					printf("Add milk -> time: %.2f minutes\n", milk*1.5);
					printf("Mix Well -> time: %.2f minutes\n", mix2*1.5);
					printf("Total time is: %.2f minutes\n", total*1.5);
					break;
					
				case 's':
				case 'S':
					printf("Put Water -> time: %d minutes\n", water);
					printf("Sugar -> time: %d minutes\n", sugar);
					printf("Mix Well -> time: %d minutes\n", mix1);
					printf("Add Coffee -> time: %d minutes\n", coffee);
					printf("Add milk -> time: %d minutes\n", milk);
					printf("Mix Well -> time: %d minutes\n", mix2);
					printf("Total time is: %d minutes\n", total);
					break;
					
				default:
					printf("Invalid Input\n");	
			}
			break;
			
		case 'b':
		case 'B':
			water = 20;
			sugar = 20;
			mix1 = 25;
			coffee = 15;
			milk = 0;
			mix2 = 25;
			total = water+sugar+mix1+coffee+milk;mix2;
			switch (size) {
				case 'd':
				case 'D':
					printf("Put Water -> time: %d minutes\n", water*1.5);
					printf("Sugar -> time: %d minutes\n", sugar*1.5);
					printf("Mix Well -> time: %d minutes\n", mix1)*1.5;
					printf("Add Coffee -> time: %d minutes\n", coffee*1.5);
					printf("Add milk -> time: %d minutes\n", milk*1.5);
					printf("Mix Well -> time: %d minutes\n", mix2*1.5);
					printf("Total time is: %d minutes\n", total*1.5);
					break;
					
				case 's':
				case 'S':
					printf("Put Water -> time: %d minutes\n", water);
					printf("Sugar -> time: %d minutes\n", sugar);
					printf("Mix Well -> time: %d minutes\n", mix1);
					printf("Add Coffee -> time: %d minutes\n", coffee);
					printf("Add milk -> time: %d minutes\n", milk);
					printf("Mix Well -> time: %d minutes\n", mix2);
					printf("Total time is: %d minutes\n", total);
					break;
					
				default:
					printf("Invalid Input\n");	
			}
			break;
			
		default:
			printf("Invalid Input\n");
			
	}
}