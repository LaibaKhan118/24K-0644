/*Task 1: Write a program that calculates the sum of all the elements in array using pointers
(Note: Generate the array via user)*/

#include <stdio.h>

int sum(int *arr, int n);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[500];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int res = sum(arr, n);
    printf("The sum is: %d\n", res);
    return 0;
}

int sum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}
