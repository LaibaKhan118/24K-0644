/*You are working as a software engineer at a company that manages a large database of customer
transactions. Each transaction is stored as a string that contains encoded information about the
customer. However, some transactions may have been duplicated due to system errors, and
these duplicates appear in scrambled order. Your task is to identify and group these "scrambled"
transactions together, as they represent the same customer activity. Two transactions are
considered scrambled if they contain the same letters but in a different order (anagrams).You are
provided with a list of transaction strings. You need to write a program that groups these
scrambled transactions into separate categories, returning each group of related transactions
together.
Example
Input transactions = ["eat", "tea", "tan", "ate", "nat", "bat"]
Expected Output: [['bat'], ['nat', 'tan'], ['ate', 'eat', 'tea']]
*/

#include <stdio.h>
#include <string.h>

int sum(char str[]);
int freq(char str[][100], int n, char *target);
void sort(char str[][100], int n);
int main()
{
    char str[100][100];
    int n;
    printf("Enter the number of codes:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter code %d:\t", i + 1);
        scanf(" %s", str[i]);
    }

    sort(str, n);

    for (int i = 0; i < n; i++)
    {
        int count = freq(str, n, str[i]);
        char arr[count];
        for (int j = 0; j < n; j++)
        {
            if (sum(str[i]) == sum(str[j]))
            {
                strcpy(arr[i], str[i]);
            }
        }

        for (int k = 0; k < count; k++)
        {
            printf("%s, ", arr[k]);
        }

        // if(i==0 || sum(str[i]) == sum(str[i+1]))
        //     printf("[");
        // else
        //     printf("], ");
        // printf("\'%s\', ", str[i]);
    }

    return 0;
}

int sum(char str[])
{
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += (int)str[i];
    }
    return sum;
}

int freq(char str[][100], int n, char *target)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(str[i], target) == 0)
        {
            count++;
        }
    }
    return count;
}

void sort(char str[][100], int n)
{
    char temp[100];
    for (int i = 0; i < n - 1; i++)
    {
        int sum_1, sum_2;
        for (int j = i + 1; j < n; j++)
        {
            sum_1 = sum(str[i]);
            sum_2 = sum(str[j]);

            if (sum_2 < sum_1)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}
