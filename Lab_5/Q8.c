#include<stdio.h>
int main() {
	int roll_n, year, month, semester, batch, section_n, time, type;
	char section;
	printf("Enter Your Roll Number (XXXXXX) (without hyphen or letter k):\t");
	scanf("%d", &roll_n);
	if ((roll_n / 1000000) != 0) {
		printf("Invalid Input\n");
		return 0;
	} else if ((roll_n / 1000000 == 0) && ((roll_n % 1000000)/100000 == 0)) {
		printf("Invalid Input\n");
		return 0;
	}
	batch = (roll_n / 10000) + 2000;
	printf("Enter Current Year (XXXX):\t");
	scanf("%d", &year);
	if ((year / 10000) != 0) {
		printf("Invalid Input\n");
		return 0;
	} else if (((year / 10000) == 0) && ((year%10000)/1000 == 0)) {
		printf("Invalid Input\n");
		return 0;
	} else if (year < batch) {
		printf("Invalid Input\n");
		return 0;
	}
	printf("Enter Current Month (XX):\t");
	scanf("%d", &month);
	if (month <= 0 || month > 12) {
		printf("Invalid Input\n");
		return 0;
	}

	// Assuming there are only 2 semesters 1. Fall (July to Dec) and 2. Spring (Jan to June)
	type = ((month >= 1 && month <= 6) ? 1 : 2);

	// Assuming that there are only 9 sections A to I and that section number (i.e. third digit of the roll number) is never 0
	section_n = (roll_n /1000) % 10;
	if(section_n < 1){
		printf("Invalid Roll Number\n");
		return 0;
	}
	
	section = ((section_n == 1) ? 'A' : (section_n == 2) ? 'B' : (section_n == 3) ? 'C' : (section_n == 4) ? 'D' : (section_n == 5) ? 'E' : (section_n == 6) ? 'F' : (section_n == 7) ? 'G' : (section_n == 8) ? 'H' : 'I');
	
	time = year - batch;
	semester = ((time == 0 ? ((type == 1) ? 0 : 1) :
		  ((time == 1) ? ((type == 1) ? 2 : 3) :
		  ((time == 2) ? ((type == 1) ? 4 : 5): 
		  ((time == 3) ? ((type == 1) ? 6 : 7) : 
		  ((time == 4) ? ((type == 1) ? 8 : 9): 10))))));
	if (semester > 8) { 
		printf("Already Graduated\n");
		return 0;
	}
	printf(" Roll number: %d\n Registration Year: %d\n Section: %c\n Semester: %d\n", roll_n, batch, section, semester);
	return 0;
}