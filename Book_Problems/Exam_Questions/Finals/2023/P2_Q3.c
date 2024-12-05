#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find all Goldbach pairs for the given even numbers
int** goldbach_pairs(int* even_numbers, int n) {
    // Allocate memory for the result (2D array)
    int** result = (int**)malloc((n + 1) * sizeof(int*)); // +1 for the terminating pair (-1, -1)
    int index = 0;

    // Iterate through each even number
    for (int i = 0; i < n; i++) {
        int even = even_numbers[i];
        result[index] = (int*)malloc(2 * sizeof(int)); // Allocate memory for one pair

        // Find the first Goldbach pair
        for (int j = 2; j <= even / 2; j++) {
            if (isPrime(j) && isPrime(even - j)) {
                result[index][0] = j;       // First prime
                result[index][1] = even - j; // Second prime
                index++;
                break; // Stop after finding the first pair
            }
        }
    }

    // Add the terminating pair (-1, -1)
    result[index] = (int*)malloc(2 * sizeof(int));
    result[index][0] = -1;
    result[index][1] = -1;

    return result;
}

int main() {
    int even_numbers[100], n = 0;

    printf("Enter even numbers (end input with -1): ");
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == -1) break;
        even_numbers[n++] = num; // Store the input number in the array
    }

    // Find Goldbach pairs
    int** goldbachPairs = goldbach_pairs(even_numbers, n);

    // Print the results
    printf("Goldbach pairs:\n");
    for (int i = 0; goldbachPairs[i][0] != -1; i++) {
        printf("(%d, %d) ", goldbachPairs[i][0], goldbachPairs[i][1]);
        free(goldbachPairs[i]); // Free memory for each pair
    }

    printf("\n");
    free(goldbachPairs); // Free the 2D array memory

    return 0;
}
