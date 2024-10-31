/*Implement a function that checks if a given integer is a prime number. Use this function in the
main program to check if numbers entered by the user are prime.*/

#include <stdio.h>
void isPrime(int a);
int main() {
    int num;
    while(1) {
        printf("Enter a Number (Zero to Exit):\t");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Exiting...");
            break;
        }
        isPrime(num);
    }
}

void isPrime(int a) {
    int factors = 0;
    for (int i = 1; i <= a; i++)
    {
        if(a % i == 0) {
            factors++;
        }
    }
    if(factors == 2) {
        printf("%d is a prime number.\n", a);
    }
    else {
        printf("%d is not a prime number.\n", a);
    }
}
