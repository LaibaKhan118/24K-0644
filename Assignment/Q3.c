/*
You are working for a text-processing company that optimizes storage for large amounts of
written data. The company has identified a recurring issue: words in documents are often
unnecessarily lengthy due to repeated consecutive characters. Your task is to minimize these
words by reducing consecutive duplicate characters to a single instance of the character.
Operations:
Compress a Word: Write a function that takes a string (a word) as input and returns a minimized
version of the word, where all consecutive duplicate letters are reduced to one.
Multiple Word Compression: You will then apply this function to a list of words and return the
minimized version for each word.
Add a feature to calculate how many characters were removed during the compression process.
Input: words = [“booooook”, “coooool”, “heeeey”]
Output: [“bok”, “col”, “hey”]
*/

#include <stdio.h>
#include <string.h>
int check_Char(char arr[], int n);

int main()
{
    char words[100][100];
    int n, removed;
    printf("Enter Number of words: \t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter word %d:\t", i + 1);
        scanf(" %s", &words[i]);
    }

    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        int size = strlen(words[i]);
        removed = check_Char(words[i], size);
        removed += removed;
    }
    printf("]\n");
    printf("Total Removed Characters: %d", removed);
}

int check_Char(char str[], int n)
{
    char arr[n];
    int j = 0, count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 || (str[i] != str[i - 1]))
        {
            arr[j] = str[i];
            j++;
        }
        else
        {
            count++;
        }
    }
    printf("\"%s\", ", arr);
    return count;
}
