/*Q: Two friends, A and B, are playing the game of matchsticks. In this game, a group of N matchsticks is placed on the table. The players can pick any number of matchsticks from 1 to 4 (both inclusive) during their chance. The player who takes the last match stick wins the game. If A starts first, how many matchsticks should he pick on his 1st turn such that he is guaranteed to win the game or determine if it’s impossible for him to win? Write a function which returns -1 if it’s impossible for A to win the game, else return the number of matchsticks he should pick on his 1st turn such that he is guaranteed to win.
 */

#include <stdio.h>

int win(int sticks);
int main()
{
    int num_of_sticks;
    printf("Enter the number of matchsticks:\t");
    scanf("%d", &num_of_sticks);

    int sticks = win(num_of_sticks);

    if (sticks == -1)
    {
        printf("It is impossible for player A to win\n");
    }
    else
    {
        printf("Start by picking %d sticks to win\n", sticks);
    }
    return 0;
}
int win(int sticks)
{
    if (sticks % 5 == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 1; i <= 4; i++)
        {
            if ((sticks - i) % 5 == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
