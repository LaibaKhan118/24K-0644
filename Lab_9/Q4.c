/*Write a C program with a user-defined function calculate to perform basic arithmetic operations
such as addition, subtraction, multiplication, and division. The program should take two
numbers and an operation choice as input, and then use the function to perform the operation.*/

#include <stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    int c;
    float a, b;
    float num;
    printf("\tMenu\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n\n");
    printf("Choose an option:\t");
    scanf("%d", &c);
    printf("Enter Number 1:\t");
    scanf("%f", &a);
    printf("Enter Number 2:\t");
    scanf("%f", &b);
    switch(c) {
        case 1:
            num = add(a, b);
            printf("Sum is %.2f", num);
            break;
        case 2:
            num = subtract(a, b);
            printf("Sum is %.2f", num);
            break;
        case 3:
            num = multiply(a, b);
            printf("Sum is %.2f", num);
            break;
        case 4:
            if(b == 0) {
                printf("Undefined\n");
            }
            else {
                num = divide(a, b);
                printf("Sum is %.2f", num);
            }
            break;
        default:
            printf("Invalid Menu Option.\n");
    }
}

float add(float a, float b) {
    return a+b;
}
float subtract(float a, float b){
    return a-b;
}
float multiply(float a, float b) {
    return a*b;
}
float divide(float a, float b){
    return a/b;
}
