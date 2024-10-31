/*Create a function that returns the maximum and minimum element in an integer array. Use this
function in the main program to find the maximum and minimum from an array entered by the
user.*/

#include <stdio.h>

int min(int arr[], int size);
int max(int arr[], int size);
int main()
{
    int arr[100], n;
    printf("Enter the number of elements:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d:\t", i+1);
        scanf("%d",&arr[i]);
    }
    int smallest = min(arr, n);
    int greatest = max(arr, n);
    printf("\nThe Maximum Element is %d\n", greatest);
    printf("The Minimum Element is %d\n", smallest);
    return 0;
}
int min(int arr[], int size)
{
    int small = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i]<small){
            small = arr[i];
        }
    }
    return small;
}

int max(int arr[], int size)
{
    int large = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    return large;
}
