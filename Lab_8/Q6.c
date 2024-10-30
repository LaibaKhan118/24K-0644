/*Print a pascal's triangle using nested loops*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        int number = 1;
        for (int k = 0; k <= i; k++)
        {
            printf("%d ", number);
            number = number * (i - k) / (k + 1);
        }
        printf("\n");
    }

    return 0;
}
