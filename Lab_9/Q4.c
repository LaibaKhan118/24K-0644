/*Write a C program with a user-defined function calculate to perform basic arithmetic operations
such as addition, subtraction, multiplication, and division. The program should take two
numbers and an operation choice as input, and then use the function to perform the operation.*/

#include <stdio.h>

void calculate(float a, float b, char op);

int main()
{
    float num1, num2;
    char operation;
    float num;

    printf("Enter Number 1:\t");
    scanf("%f", &num1);
    printf("Enter Number 2:\t");
    scanf("%f", &num2);
    printf("Select an operation to perform (+, -, *, /):\t");
    scanf(" %c", &operation);

    calculate(num1, num2, operation);
    return 0;
}

void calculate(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        printf("Sum is %.2f", a + b);
        break;

    case '-':
        printf("Difference is %.2f", a - b);
        break;

    case '*':
        printf("Product is %.2f", a * b);
        break;

    case '/':
        if (b == 0)
        {
            printf("Undefined\n");
        }
        else
        {
            printf("Division is %.2f", a / b);
        }
        break;

    default:
        printf("Invalid Operation Symbol.\n");
    }
}
