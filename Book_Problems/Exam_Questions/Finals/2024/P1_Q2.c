/*Q2:  Matrix Operations (2D Arrays and Pointers)

Perform the following operations on a 2D matrix:
1. Take input for a matrix of size n x m.
2. Find the maximum value from each row and the minimum value from each column.
3. Take two additional matrices and perform:
     Matrix addition and Matrix multiplication
4. Check if the matrix is symmetric.
5. Display the matrices in a readable format.
6. Deallocate the memory at the end.*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void findMaxRowMinCol(int **matrix, int rows, int cols);
int isSymmetric(int **matrix, int rows, int cols);
int **allocateMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);
void matrixAddition(int **mat1, int **mat2, int **result, int rows, int cols);
void matrixMultiplication(int **mat1, int **mat2, int **result, int r1, int c1, int c2);

int main()
{
    int rows, cols;

    // Input dimensions for the first matrix
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the first matrix
    int **matrix = allocateMatrix(rows, cols);

    // Take input for the first matrix
    printf("Enter the elements of the matrix:\n");
    inputMatrix(matrix, rows, cols);

    // Display the matrix
    printf("Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Find maximum value from each row and minimum value from each column
    findMaxRowMinCol(matrix, rows, cols);

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, rows, cols))
    {
        printf("The matrix is symmetric.\n");
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }

    // Perform matrix addition and multiplication with two additional matrices
    int **matrix2 = allocateMatrix(rows, cols);
    int **addResult = allocateMatrix(rows, cols);
    int **multiplyResult = allocateMatrix(rows, cols);

    printf("\nEnter elements for a second matrix (for addition and multiplication):\n");
    inputMatrix(matrix2, rows, cols);

    printf("\nMatrix 1:\n");
    printMatrix(matrix, rows, cols);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows, cols);

    // Matrix addition
    matrixAddition(matrix, matrix2, addResult, rows, cols);
    printf("\nResult of Matrix Addition:\n");
    printMatrix(addResult, rows, cols);

    // Matrix multiplication
    matrixMultiplication(matrix, matrix2, multiplyResult, rows, cols, cols);
    printf("\nResult of Matrix Multiplication:\n");
    printMatrix(multiplyResult, rows, cols);

    // Free dynamically allocated memory
    freeMatrix(matrix, rows);
    freeMatrix(matrix2, rows);
    freeMatrix(addResult, rows);
    freeMatrix(multiplyResult, rows);

    return 0;
}

// Function to allocate memory for a matrix
int **allocateMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free allocated memory
void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to take input for a matrix
void inputMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the maximum value from each row and the minimum value from each column
void findMaxRowMinCol(int **matrix, int rows, int cols)
{
    // Maximum of each row
    printf("\nMaximum value in each row:\n");
    for (int i = 0; i < rows; i++)
    {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        printf("Row %d: %d\n", i + 1, max);
    }

    // Minimum of each column
    printf("\nMinimum value in each column:\n");
    for (int j = 0; j < cols; j++)
    {
        int min = matrix[0][j];
        for (int i = 1; i < rows; i++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        printf("Column %d: %d\n", j + 1, min);
    }
}

// Function to check if a matrix is symmetric
int isSymmetric(int **matrix, int rows, int cols)
{
    if (rows != cols)
        return 0; // A symmetric matrix must be square

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

// Function to perform matrix addition
void matrixAddition(int **mat1, int **mat2, int **result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(int **mat1, int **mat2, int **result, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
