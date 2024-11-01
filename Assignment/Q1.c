/*Write a c program to find the second smallest element in an array.
Input 5 elements in the array (value must be <9999) :
element - 0 : 0
element - 1 : 9
element - 2 : 4
element - 3 : 6
element - 4 : 5
Expected Output :
The Second smallest element in the array is : 4*/

#include <stdio.h>

int main()
{
    int arr[5];
    int small = 9999, sec_small;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Element %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < small)
        {
            sec_small = small;
            small = arr[i];
        }
        else if (arr[i] < sec_small && arr[i] != small)
        {
            sec_small = arr[i];
        }
    }
    printf("The Second Smallest Element in the Array is: %d", sec_small);
    return 0;
}
