/*Write a program to copy the contents of one file to another. (Create a File with some
dummy data, The data is not required to be formatted)*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr1, *fptr2;
    char text[100];
    fptr1 = fopen("sample1.txt", "w");
    fprintf(fptr1, "Hello World");
    fclose(fptr1);

    fptr1 = fopen("sample1.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open the file");
        return 1;
    }
    fptr2 = fopen("copy.txt", "w");
    fscanf(fptr1, "%[^\n]s", text);
    fprintf(fptr2, "%s", text);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
