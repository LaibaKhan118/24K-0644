// 2024 mid A - section B, Q 3
//  Create a C program to check if poitive integer is deficient, abundant, or perfect. Input number, find divisors, sum the divisors, if sum > number, numbber is bundant, if sum < num, nuber is  deficient, or if num = sum, number is perfect.Display number, class, and divisors. 

#include <stdio.h>

int main() {
    int n, sum = 0;
    do {
        printf("Enter a positive integer:\t");
        scanf("%d", &n);
    } while(n <= 0);
    
    int divi[n/2];
    int j = 0;
    for (int i = 1; i <= n/2; i++) {
        divi[i] = 0;
        if (n % i == 0) {
            divi[j] = i;
            sum+=i;
            j++;
        }
    }
    
    printf("\nThe number: %d\nClassificaion: ", n);
    if(sum > n) {
        printf("Abundant\n");
    } else if(sum < n) {
        printf("Deficient\n");
    } else {
        printf("Perfect\n");
    }
    printf("List of Divisors:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ", divi[i]);
    }
    return 0;
}
