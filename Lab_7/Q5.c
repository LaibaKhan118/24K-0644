/*Q: Write a program to read 10 integers into an array. Then, use loops to find the
frequency of each element in the array (how many times each number occurs).*/
/*With and with nested loops*/

/*==== No Nested Loops ====*/

#include <stdio.h>

int main()
{
    // Assuming the user will only enter positive numbers
    int arr[10];
    printf("Instructions: Enter Only positive numbers.\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Finding the max number entered by the user and using it as the length of the frequency array
    int max = -9999;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int freq[max];
    // Initializing Every element with 0
    for (int i = 0; i <= max; i++)
    {
        freq[i] = 0;
    }
    // Finding frequency
    for (int i = 0; i < 10; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        if (freq[i] > 0)
            printf("%d is repeated %d time(s)\n", i, freq[i]);
    }

    return 0;
}
/*
#include <stdio.h>

int main()
{
    // Assuming that the user will not put any number greater than 9
    int arr[10], freq[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d",&arr[i]);
        freq[arr[i]]++;
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (freq[i] != 0) {
            printf("%d: %d times\n", i, freq[i]);
        }
    }
        return 0;
}
*/

/*==== Nested Loops ====*/
/*The Best*/
/*
#include <stdio.h>
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter %d number:\t", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        int counted = 0;
        for (int k = 0; k < i; k++)
        {
            if (arr[k] == arr[i])
            {
                counted = 1;
                break;
            }
        }

        if (!counted)
        {
            int count = 0;
            for (int j = 0; j < 10; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            printf("%d is %d time\n", arr[i], count);
        }
    }
    return 0;
}

*/
