#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0, n;
    printf("Enter the number of columns per row: ");
    scanf("%d", &n);

    int **matrix = (int **)calloc(100, sizeof(int *));
    for (int i = 0; i < 100; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter the matrix rows (enter -1 to stop):\n");
    while (1)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == -1)
            break;
        matrix[m][0] = temp;

        for (int j = 1; j < n; j++)
        {
            scanf("%d", &matrix[m][j]);
        }
        m++;
    }

    int **result = (int **)calloc(m - 2, sizeof(int *));
    for (int i = 0; i < m - 2; i++)
    {
        result[i] = (int *)calloc(n - 2, sizeof(int));
    }

    for (int i = 0; i < m - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    result[i][j] += matrix[x][y];
                }
            }
        }
    }

    printf("\nResultant matrix dimensions: %dx%d\n", m - 2, n - 2);

    for (int i = 0; i < m - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 100; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < m - 2; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
