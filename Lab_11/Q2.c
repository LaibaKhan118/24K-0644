/*Q: How would you implement a program to count the occurrences of each word in a text file? Write the approach and code.*/

/*Assuming that the user gives a word to search it in an existing file rather then us finding the count of each and every word in the file*/

/* Approach:
First ask the user to enter the name of the text file and the word to search for.
Then open the file using the fopen() function and check if it was successfully opened. If the file cannot be opened, we print an error message and exit the program.
Now, read each word from the file using the fscanf() function and store it in a buffer. Compare the buffer with the word to search for using the strcmp() function. If the two strings are equal, increment a counter.
After reading the entire file, we print the number of occurrences of the word in the file.
Finally, we close the file using the fclose() function.*/

#include <stdio.h>
#include <string.h>

#define Length 100

int main()
{
    char fileName[Length], word[Length];
    printf("Enter the file path of a file with the extension (.txt): ");
    scanf("%s", fileName);
    printf("Enter the word to search (case sensitive): ");
    scanf("%s", word);

    FILE *fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        printf("cannot open the file.");
        return 1;
    }

    char buffer[Length];
    int count = 0;

    while (fscanf(fptr, "%s", buffer) != EOF)
    {
        if (strcmp(buffer, word) == 0)
        {
            count++;
        }
    }

    printf("The word %s occurs %d times in the file: %s", word, count, fileName);

    fclose(fptr);
    return 0;
}