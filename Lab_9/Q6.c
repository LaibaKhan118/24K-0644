/*Create a function that returns the maximum and minimum element in an integer array. Use this
function in the main program to find the maximum and minimum from an array entered by the
user.*/

#include <stdio.h>

void min_max(int arr[], int size);
int main()
{
    int arr[100], n;
    printf("Enter the number of elements:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }
    min_max(arr, n);
    return 0;
}
void min_max(int arr[], int size)
{
    int small = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
    }
    printf("\nThe Minimum Element is %d\n", small);

    int large = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    printf("The Maximum Element is %d\n", large);
}
