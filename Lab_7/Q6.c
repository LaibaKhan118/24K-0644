/*Given an array arr[] of size N which contains elements from 0 to N-1, you need to
find one of the elements occurring more than once in the given array.
Input:
Array Size =5
Element 1=1
Element 2=2
Element 3=3
Element 4=2
Element 5=5
Output:
Number 2 occur more than once.
Note: You cannot utilize nested loops.*/

#include <stdio.h>

int main()
{
    int n;
    printf("Array size:\t");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Finding the max number entered by the user and using it as the length of the frequency array
    int max = -9999;
    for (int i = 0; i < n; i++)
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
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        if (freq[i] > 1)
            printf("Number %d occurs more than once\n", i);
    }

    return 0;
}
