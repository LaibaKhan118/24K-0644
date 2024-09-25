#include<stdio.h>
int main (){
	float cal, fat, f_cal, cal_percent;
	printf("Enter Number of Calories:\t");
	scanf("%f", &cal);
	printf("Enter grams of Fat:\t");
	scanf("%f", &fat);
	if(cal < 0 || fat < 0) {
		printf("Invalid Input\n");
		return 0;
	}
	else {
		f_cal = fat * 9;
		if (f_cal > cal) {
			printf("Either Number of Calories or grams of fat were inccorectly entered\n");
			return 0;
		}	
		else {
			cal_percent = f_cal/cal;
			printf("Percentage of Calories that come from Fat is: %.2f\n", cal_percent);
		}	

	}
	return 0;
}