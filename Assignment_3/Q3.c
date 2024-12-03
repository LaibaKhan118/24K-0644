#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email);

int main()
{
    char *ptr;
    int length;

    printf("Enter the length of your email address: ");
    scanf("%d", &length);
    ptr = (char *)malloc(length + 1);
    if (ptr == NULL)
    {
        printf("Failed to allocate memory!\n");
        return 1;
    }

    printf("Enter your email address: ");
    scanf("%s", ptr);

    if (validateEmail(ptr))
    {
        printf("Valid Email\n");
    }
    else
    {
        printf("Invalid Email\n");
    }

    free(ptr);
    return 0;
}

int validateEmail(char *email)
{
    if (email == NULL || strlen(email) == 0)
    {
        return 0; // Invalid if email is empty
    }

    int size = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (email[i] == '@')
        {
            if (atIndex != -1)
            {
                return 0; // More than one '@' character
            }
            atIndex = i;
        }
        else if (email[i] == '.')
        {
            // Check if the dot is atleast a character after the @
            if (atIndex != -1 && i > atIndex + 1)
            {
                dotIndex = i;
            }
        }
    }

    // Validate position of '@' and '.'
    if (atIndex > 0 && dotIndex > atIndex + 1 && dotIndex < size - 1)
    {
        return 1;
    }

    return 0;
}
