/*
Write a C program that contains the following functions for different numerical conversions:
1. int BinaryToDecimal(int number); Converts a binary number to its decimal equivalent.
2. int DecimalToBinary(int number); Converts a decimal number to its binary equivalent.
3. void DecimalToHexadecimal(int number); Converts a decimal number to its hexadecimal
equivalent and prints it.
4. void HexadecimalToDecimal(string hexNumber); Converts a hexadecimal number to its
decimal equivalent and prints it.
5. void BinaryToHexadecimal(int number); Converts a binary number to its hexadecimal
equivalent and prints it.
6. void HexadecimalToBinary(string hexNumber); Converts a hexadecimal number to its
binary equivalent and prints it.
Each function should take an appropriate input and return or display the converted value. Ensure
that the program handles invalid inputs gracefully. Your program must display the menu which
function the user wants to call.
*/
#include <stdio.h>

int BinaryToDecimal(int number);
long long int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);
int main()
{
    int opt;
    long unsigned int num; // Assuming that the numbers inputted are within the range of unsigned int
    char hex[100];         // Assuming that the numbers inputted are under 100 characters
    printf("\t\t\tMenu\t\t\t\n\n");
    printf("1. Binary To Decimal\n");
    printf("2. Decimal To Binary\n");
    printf("3. Decimal To Hexadecimal\n");
    printf("4. Hexadecimal To Decimal\n");
    printf("5. Binary To Hexadecimal\n");
    printf("6. Hexadecimal To Binary\n");
    printf("\n Select one Option:\t");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("Enter a Binary number:\t");
        scanf("%ld", &num);
        long int dec = BinaryToDecimal(num);
        printf("Decimal Equivalent is:\t%ld", dec);
        break;

    case 2:
        printf("Enter a Decimal number:\t");
        scanf("%ld", &num);
        long long int bin = DecimalToBinary(num);
        printf("Binary Equivalent is:\t%lld", bin);
        break;

    case 3:
        printf("Enter a Decimal number:\t");
        scanf("%ld", &num);
        DecimalToHexadecimal(num);
        break;

    case 4:
        printf("Enter a Hexadecimal number:\t");
        scanf("%s", &hex);
        HexadecimalToDecimal(hex);
        break;

    case 5:
        printf("Enter a Binary number:\t");
        scanf("%ld", &num);
        BinaryToHexadecimal(num);
        break;
    case 6:
        printf("Enter a Hexadecimal number:\t");
        scanf("%s", &hex);
        HexadecimalToBinary(hex);
        break;

    default:
        printf("Invalid Menu Option\n");
        break;
    }
    return 0;
}

int BinaryToDecimal(int number)
{
    int dec = 0, r, exp = 1;
    while (number != 0)
    {
        r = number % 10;
        dec += (r * exp);
        number /= 10;
        exp *= 2;
    }
    return dec;
}

long long int DecimalToBinary(int number)
{
    long long int bin = 0;
    long int exp = 1;
    int r;
    while (number != 0)
    {
        r = number % 2;
        bin += (r * exp);
        number /= 2;
        exp *= 10;
    }
    return bin;
}
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number)
{
    long int hex, r, exp = 1;
    while (number != 0)
    {
        r = number % 10;
        hex += (r * exp);
        number /= 10;
        exp *= 2;
    }
    printf("Hexadecimal Equivalent is:\t%lx", hex);
}
void HexadecimalToBinary(char hexNumber[]);
