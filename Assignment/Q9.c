#include <stdio.h>
#include <string.h>

void printGrid(char grid[][5]);
int main()
{
    printf("How to play:\nEnter W to move up\nEnter S to move down\nEnter A to move left\nEnter D to move right\nEnter Q to Quit\n");
    printf("Instructions: Move up, down, left or right to collect items \'I\' and avoid obstacles \'X\'.\n");
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}};

    printGrid(grid);

    char move;
    int item_count = 0;
    while (1)
    {
        printf("Move:\t");
        scanf("%c", &move);
        // if move up then change the postion of P to the one above it and put a space in i's previous position
        // print the new grid
    }
    return 0;
}

void printGrid(char grid[][5])
{
    printf("-----\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
}
