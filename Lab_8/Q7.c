#include <stdio.h>

int main()
{
    int n = 6;
    int i = 0;

    while (i < n)
    {
        int j = n - 1;
        while (j > i)
        {
            printf(" ");
            j--;
        }

        j = 0;
        while (j < i)
        {
            if (i > 2 && (j > 0 && j < i - 1))
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
            j++;
        }

        j = n;
        while (j > i)
        {
            printf("  ");
            j--;
        }

        j = 0;
        while (j < i)
        {
            if (i > 2 && (j > 0 && j < i - 1))
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
            j++;
        }

        j = n;
        while (j > i)
        {
            printf("  ");
            j--;
        }

        j = 0;
        while (j < i)
        {
            if (i > 2 && (j > 0 && j < i - 1))
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
            j++;
        }

        printf("\n");
        i++;
    }

    return 0;
}
