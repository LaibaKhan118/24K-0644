#include <stdio.h>

void printElements(int arr[], int size, int index);
int main()
{
    int num[] = {1, 5, 2, 4, 6, 8};
    int i = 0;
    int len = sizeof(num) / sizeof(num[0]);
    printElements(num, len, i);
    return 0;
}
void printElements(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }
    else
    {
        printf("%d  ", arr[index]);
        printElements(arr, size, index + 1);
    }
}
