/*Using Task. 4, resize that dynamic array of character and append the array with your studentId.
That student id must be taken input from the user.
DynamicArray = "Muhib Ahmed"; // Before

DynamicArray = "K241234 Muhib Ahmed"; // After the text append*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    char *ptr, id[20];
    printf("Enter the total number of characters in your name (first+last with the space): ");
    scanf("%d", &N);
    getchar();

    ptr = (char *)malloc((N + 1) * sizeof(char));
    if (ptr == NULL)
    {
        printf("Cannot Allocate memory\n");
        return 1;
    }

    printf("Enter Your Name: ");
    fgets(ptr, N + 1, stdin);
    ptr[strcspn(ptr, "\n")] = '\0';
    getchar();

    printf("Dynamic Array: %s\n", ptr);

    printf("Enter Your ID (YYK-XXXX): ");
    scanf("%[^\n]s", id);

    int len = N + strlen(id) + 2;
    ptr = (char *)realloc(ptr, len * sizeof(char));
    if (ptr == NULL)
    {
        printf("Cannot Allocate memory\n");
        return 1;
    }

    memmove((ptr + strlen(id) + 1), ptr, N + 1);
    memcpy(ptr, id, strlen(id));
    ptr[strlen(id)] = ' ';

    printf("After reallocation: %s\n", ptr);

    free(ptr);
    return 0;
}
