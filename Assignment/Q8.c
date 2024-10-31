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
#include <string.h>
#include <math.h>

long int BinaryToDecimal(long long unsigned int number);
long long int DecimalToBinary(long int number);
void DecimalToHexadecimal(long int number);
long int HexadecimalToDecimal(const char *hexNumber);
void BinaryToHexadecimal(long long unsigned int number);
void HexadecimalToBinary(const char *hexNumber);
int main()
{
    int opt;
    long long unsigned int bin;
    long unsigned int num;
    char hex[100]; // Assuming that the numbers inputted are under 100 characters
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
        scanf("%lld", &bin);
        long int dec = BinaryToDecimal(bin);
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
        long int number = HexadecimalToDecimal(hex);
        printf("Decimal Equivalent: %ld", number);
        break;

    case 5:
        printf("Enter a Binary number:\t");
        scanf("%lld", &bin);
        BinaryToHexadecimal(bin);
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

long int BinaryToDecimal(long long unsigned int number)
{
    long int dec = 0, r, exp = 1;
    while (number != 0)
    {
        r = number % 10;
        dec += (r * exp);
        number /= 10;
        exp *= 2;
    }
    return dec;
}

long long int DecimalToBinary(long int number)
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

void DecimalToHexadecimal(long int number)
{
    long long int bin = DecimalToBinary(number);
    long int hex = BinaryToDecimal(bin);
    printf("Hexadecimal Equivalent is:\t%X", hex);
}

long int HexadecimalToDecimal(const char *hexNumber)
{
    long int num = 0;
    int dig = 0;
    int size = strlen(hexNumber);
    int start = (hexNumber[1] == 'x' || hexNumber[1] == 'X') ? 2 : 0;
    for (int i = size - 1; i >= start; i--)
    {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
        {
            dig = (hexNumber[i] - '0');
        }
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
        {
            dig = (hexNumber[i] - 'A' + 10);
        }
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f')
        {
            dig = (hexNumber[i] - 'a' + 10);
        }
        else
        {
            printf("Invalid Input\n");
        }
        num += dig * pow(16, size - 1 - i);
    }

    return num;
}

void BinaryToHexadecimal(long long unsigned int number)
{
    long int hex = BinaryToDecimal(number);
    printf("Hexadecimal Equivalent is:\t%X", hex);
}

void HexadecimalToBinary(const char *hexNumber)
{
    long int dec = HexadecimalToDecimal(hexNumber);
    long long int binary = DecimalToBinary(dec);
    printf("Binary Equivalent:\t%lld", binary);
}
