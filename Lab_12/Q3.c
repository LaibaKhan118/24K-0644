/*Task 3:
Write a C Program to Find Largest Number in an array Using Dynamic Memory Allocation. Note:
The array must be dynamically resized and initially the array size will be taken by the user and
then resized by the user
Example arr[5]={1,2,3,4,5}
//After resizing
Arr[7]={1,2,3,4,5,6,7}
Take the same array and resize it.*/

#include <stdio.h>
#include <stdlib.h>

int largest(const int *arr, int n);

int main()
{
    int n, rn, *ptr;
    printf("Enter the number of Elements: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Cannot Allocate Memory\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", ptr + i);
    }
    int large = largest(ptr, n);

    printf("\nArray: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\nLargest Number: %d\n", large);

    printf("\nEnter the number for resizing: ");
    scanf("%d", &rn);
    ptr = realloc(ptr, rn * sizeof(int));
    if (ptr == NULL)
    {
        printf("Cannot Allocate Memory\n");
        return 1;
    }
    if (rn > n)
    {
        for (int i = n; i < rn; i++)
        {
            printf("Enter Element %d: ", i + 1);
            scanf("%d", ptr + i);
        }
    }

    int large2 = largest(ptr, rn);

    printf("Resized Array: ");
    for (int i = 0; i < rn; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\nLargest Number after reallocation: %d\n", large2);
    free(ptr);
    return 0;
}

int largest(const int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
