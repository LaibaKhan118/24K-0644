#include <stdio.h>

int main() {
    int n;

    // Input the size of the square matrix
    printf("Enter the size of the matrix (odd number): ");
    scanf("%d", &n);

    // Check if n is odd
    if (n % 2 == 0) {
        printf("The size of the matrix must be an odd number.\n");
        return 1;
    }

    int matrix[n][n];
    int sum = 0;

    // Input the elements of the matrix
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the border elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Border elements: top row, bottom row, left column, or right column
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                sum += matrix[i][j];
            }
        }
    }

    // Output the sum of border elements
    printf("Sum of border elements: %d\n", sum);

    return 0;
}
