/*Create a Function where it accepts a 2D array of strings where it sorts the string in the array
based on the first character’s ASCII Value in ascending order.
Example: {HELLO,JELLO,MELLO,TELLO,BELLO} //Input to function
Output from Function: {BELLO,HELLO,JELLO,MELLO,TELLO}
Hint: You can use the strcpy function for this to copy the array.*/

#include <stdio.h>
#include <string.h>

void sortStrings(char arr[][20], int n);
int main()
{
    char str[100][20];
    int n;
    printf("Enter the number of strings:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter String %d:\t", i + 1);
        scanf(" %[^\n]s", str[i]);
    }

    sortStrings(str, n);

    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%s", str[i]);
        if (i + 1 != n)
        {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
void sortStrings(char arr[][20], int n)
{
    char temp[20];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
