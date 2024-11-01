#include <stdio.h>
#include <ctype.h>
#define size 5

void print_grid(char grid[size][size]);
void move_player(char grid[size][size], char move);

int player_row = 4, player_col = 4, score = 0;
int main()
{
    printf("How to play:\nEnter W to move up\nEnter S to move down\nEnter A to move left\nEnter D to move right\nEnter Q to Quit\n");
    printf("Instructions: Move up, down, left or right to collect items \'I\' and avoid obstacles \'X\'. Collect all three Items to win.\n");
    char grid[size][size] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}};

    print_grid(grid);

    char move;
    while (1)
    {
        printf("Move:\t");
        scanf(" %c", &move);
        move = toupper(move);
        if(move == 'Q') {
            printf("Exiting...\n");
            return 0;
        }
        move_player(grid, move);
        if(score == 3) {
            printf("Congratulations!\n You have collected all Items!\n");
            return 0;
        }
        print_grid(grid);
    }
    return 0;
}

void print_grid(char grid[size][size])
{
    printf("-----\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
}

void move_player(char grid[size][size], char move) {
    int n_row = player_row;
    int n_col = player_col;
    
    switch(move){
        case 'W':
            n_row--;
            break;
        case 'S':
            n_row++;
            break;
        case 'A':
            n_col--;
            break;
        case 'D':
            n_col++;
            break;
        default:
            return;
     }
     if(n_row < 0 || n_row >= size || n_col < 0 || n_col >= size) {
         printf("No space to move!\n\n");
         return;
     }
     if(grid[n_row][n_col] == 'X') {
         printf("Can't Move, Obstacle Ahead.\n\n");         return;
     }
    if(grid[n_row][n_col] == 'I') {
         printf("Item Collected!\n");         
         score++;
         printf("Your current score is %d\n\n", score);
    }
    grid[player_row][player_col] = ' ';
    player_row = n_row;
    player_col = n_col;
    grid[player_row][player_col] = 'P';
}
