/*One of the master coders designed a subscript block that stores random characters in a multidimensional array. You are asked to design a program that will find a given string in a multidimensional array of characters. The search for characters can be present and operational from left to right and top to down only. The program should create a 6 x 5 2D array and populate it with random alphabet characters. After that, the program should print it in a tabular form as shown below. Search the user-entered string in the 2D array, if it is present then add a point to the score, if it is not available then subtract one. Print the score at every input. The program stops asking and re-populates the 2D array with new random characters when the user enters “END” as the string.
[NOTE: After generating random numbers, the last row should have your student ID’s last four
digits]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROW 6
#define COL 5

char random_char();
int find(const char str[], const char arr[ROW][COL]);
int main()
{
    srand(time(NULL)); // Current time for random number
    char puzzle[ROW][COL] = {0};

    // My roll number in last row
    puzzle[5][0] = '0';
    puzzle[5][1] = '6';
    puzzle[5][2] = '4';
    puzzle[5][3] = '4';

    // Random Characters in the rest
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (puzzle[i][j] == 0)
            {
                puzzle[i][j] = random_char();
            }
        }
    }

    // Printing the matrix
    for (int i = 0; i < ROW; i++)
    {
        printf("[ ");
        for (int j = 0; j < COL; j++)
        {
            printf("%c  ", puzzle[i][j]);
        }
        printf("]\n");
    }

    // String to search in the matrix
    char str[ROW];
    int score = 0;
    while (1)
    {
        printf("\nEnter a string to search (END to stop):\t");
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = toupper(str[i]);
        }

        // Exit if h ur entered 'end'
        if (strcmp(str, "END") == 0)
        {
            return 0;
        }
        
        int found = find(str, puzzle);
        score += found;
        if (found == 1)
        {
            printf("%s is present\nScore: %d\t", str, score);
        }
        else
        {
            printf("%s is not present\nScore: %d\t", str, score);
        }
    }
    return 0;
}

char random_char()
{
    return (rand() % 26) + 'A';
}

int find(const char str[], const char arr[ROW][COL])
{
    int len = strlen(str);

    // Check each row for the string
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j <= COL - len; j++)
        {
            // Compare the substring with the string
            if (strncmp(&arr[i][j], str, len) == 0)
            {
                return 1;
            }
        }
    }

    // Check each column for the string
    for (int j = 0; j < COL; j++)
    {
        for (int i = 0; i <= ROW - len; i++)
        {
            // Compare the substring with the string
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (arr[i + k][j] != str[k])
                {
                    found = 0;
                    break;
                }
            }
            if (found)
            {
                return 1;
            }
        }
    }

    return -1; // String not found
}
