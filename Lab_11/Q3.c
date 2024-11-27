/*Q: Create a function to replace a word in a file with another word.
Read the file into memory, perform a search and replace, and write the modified
content back to the file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1024

void findAndReplace(const char *filename, const char *oldWord, const char *newWord)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open the file %s!\n", filename);
        return;
    }

    // temporary file for modified content
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Could not open temporary file for writing.\n");
        fclose(fptr);
        return;
    }

    char line[LENGTH];
    while (fgets(line, sizeof(line), fptr))
    {
        char *pos;
        while ((pos = strstr(line, oldWord)) != NULL)
        {
            *pos = '\0';
            fprintf(tempFile, "%s%s", line, newWord);
            strcpy(line, pos + strlen(oldWord));
        }
        fprintf(tempFile, "%s", line);
    }

    fclose(fptr);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);
    printf("Successfully replaced '%s' with '%s' in %s.\n", oldWord, newWord, filename);
}

int main()
{
    char filename[LENGTH];
    char old_word[LENGTH];
    char new_word[LENGTH];

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter the word to be replaced: ");
    fgets(old_word, sizeof(old_word), stdin);
    old_word[strcspn(old_word, "\n")] = '\0';

    printf("Enter the new word: ");
    fgets(new_word, sizeof(new_word), stdin);
    new_word[strcspn(new_word, "\n")] = '\0';

    findAndReplace(filename, old_word, new_word);
    return 0;
}
