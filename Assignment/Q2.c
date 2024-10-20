/*A popular beverage company is looking to optimize their marketing campaigns by understanding
the frequency of characters used in their promotional slogans. They believe that analyzing these
patterns can help them tailor their messaging to specific demographics and improve brand recall.
You've been tasked with creating a C code function to analyze the character frequency in a list of
slogans provided by the marketing team. This analysis will help identify the most common letters
used in their slogans, which can inform future marketing strategies.*/

#include <stdio.h>

void countChar(char arr[]);

int main()
{
    char slogan[100][100];
    int n, count;
    printf("Enter Number of slogans: \t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter slogan %d:\t", i + 1);
        scanf(" %[^\n]s", &slogan[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Slogan %d: %s: {", i + 1, slogan[i]);
        countChar(slogan[i]);
        printf("}\n");
    }

    return 0;
}

void countChar(char slogan[])
{
    int count;
    for (int i = 0; slogan[i] != '\0'; i++)
    {
        char ch = slogan[i];
        int already_counted = 0;

        for (int k = 0; k < i; k++)
        {
            if (slogan[k] == ch)
            {
                already_counted = 1;
                break;
            }
        }

        if (!already_counted)
        {
            count = 0;
            for (int i = 0; slogan[i] != '\0'; i++)
            {
                if (slogan[i] == ch)
                {
                    count++;
                }
            }
            printf("\'%c\': %d, ", ch, count);
        }
    }
}
