/*Write a recursive function linearSearch that takes an array, its size, the target element
to search for, and the current index. It checks if the target is at the current index and
continues searching in the subsequent indices until it either finds the target or exhausts
the array.*/

#include <stdio.h>

void linearSearch(int arr[], int n, int num, int start);

int main()
{
    int arr[100], size, target, index;
    printf("Enter the number of elements the Array have:\t");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d:\t", i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to find:\t");
    scanf("%d",&target);
    printf("Enter the index to start searching from:\t");
    scanf("%d",&index);
    linearSearch(arr, size, target, index);

    return 0;
}

void linearSearch(int arr[], int n, int num, int start){
    if (start >= n) {
        printf("Not Found\n");
        return;
    }
    if(arr[start] == num) {
        printf("the number %d is present at the index %d", num, start);
    }
    else {
        linearSearch(arr, n, num, start + 1);
    }
}
