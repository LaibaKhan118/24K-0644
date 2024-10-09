#include<stdio.h>
int main() {
	int i, num = 25;
	for(i = 1; i <= num; i++) {
		if(i <= 5 || i >= 21) {
			printf("* ");
		}
		else if(((i >= 6 && i <= 10) || (i >= 16 && i <= 20)) && (i % 5 == 2 || i % 5 == 4)) {
            			printf("* ");
        	}
        	else if(i >= 11 && i <= 15 && (i % 5 == 3)) {
            		printf("* ");
        	}
        	else {
            		printf("  ");
        	}
        	if(i % 5 == 0) {
            		printf("\n");
        	}
    	}
    	return 0;
}

