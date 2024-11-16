/*Write a recursive function bubbleSort that takes an array and its size. It performs the
bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
they are in the wrong order.*/

// Assuming we have to sort in ascending order
#include <stdio.h>

void bubbleSort(int arr[], int size);

int main()
{
    int arr[100], n, index;
    printf("Enter the number of Elements:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d:\t", i);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, size - 1);
}
