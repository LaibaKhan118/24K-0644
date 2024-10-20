#include <stdio.h>
int main()
{
    int arr[6];
    for (int i = 0; i < 6; i++)
    {
        printf("Enter element %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n\nEntered Array: { ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");

    int temp;

    printf("Shifted Array: { ");
    for (int i = 0; i < 6; i++)
    {
        temp = arr[i];
        arr[i] = arr[6 - 1];
        arr[6 - 1] = temp;

        printf("%d ", arr[i]);
    }
    printf("}\n");
}
