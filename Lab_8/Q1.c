/*Write a C program that generates a sequence of prime numbers within a given range using
nested loops.*/
#include <stdio.h>

int main()
{
    int start, end, factors;
    printf("Enter the staring number:\t");
    scanf("%d", &start);
    printf("Enter the ending number:\t");
    scanf("%d", &end);
    for (int num = start; num <= end; num++)
    {
        factors = 0;
        for (int i = 2; i <= num; i++)
        {
            if (num % i == 0)
            {
                factors++;
            }
        }
        if (factors == 1)
        {
            printf("%d  ", num);
        }
    }

    return 0;
}
