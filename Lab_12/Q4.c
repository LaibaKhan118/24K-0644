/*Write a program that ask the user to enter the total N no of characters in user's name {First
Name + Last Name} to create a dynamic array of characters. After create a dynamic array of
that 'N' no of characters using malloc or calloc function. Finally copy your full name in it that has already been taken from the user before
Dynamic Array = "Muhib Ahmed";*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    char *ptr, name[100];
    printf("Enter the total number of characters in your name (first+last): ");
    scanf("%d", &N);
    N += 2; // 2 more for the null terminator and the space between first nad last name
    printf("Enter Your Name: ");
    scanf(" %[^\n]s", name);
    ptr = (char *)calloc(N, 1);
    if (ptr == NULL)
    {
        printf("Cannot Allocate memory\n");
        return 1;
    }
    
    strncpy(ptr, name, N);
    printf("Dynamic Array: %s\n", ptr);
    free(ptr);
    return 0;
}
