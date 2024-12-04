/*Q1: Probability of Last Person in Proper Seat

Imagine there are n people in line to board a plane with n seats. The first person loses their boarding pass and sits in a random seat. Every subsequent passenger will sit in their assigned seat if it's available; otherwise, they will take a random seat.
Question: What is the probability that the last person will sit in their proper seat?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a single boarding process
int simulateBoarding(int n)
{
    int seats[n]; // Array representing seats (0 means unoccupied, 1 means occupied)
    for (int i = 0; i < n; i++)
    {
        seats[i] = 0; // Initialize all seats as unoccupied
    }

    int firstPersonSeat = rand() % n; // First person picks a random seat
    seats[firstPersonSeat] = 1;       // Mark that seat as occupied

    for (int i = 1; i < n - 1; i++)
    { // Loop through remaining passengers (except the last)
        if (seats[i] == 0)
        {                 // If their seat is available
            seats[i] = 1; // They sit in their assigned seat
        }
        else
        {
            // Otherwise, they pick a random unoccupied seat
            int randomSeat;
            do
            {
                randomSeat = rand() % n;
            } while (seats[randomSeat] == 1);
            seats[randomSeat] = 1; // Mark the random seat as occupied
        }
    }

    // Check if the last person sits in their proper seat
    return seats[n - 1] == 0; // Return 1 if last person's seat is unoccupied, 0 otherwise
}

int main()
{
    int n, trials;
    printf("Enter the number of passengers (n): ");
    scanf("%d", &n);

    printf("Enter the number of simulation trials: ");
    scanf("%d", &trials);

    srand(time(0)); // Seed the random number generator with the current time

    int successCount = 0; // Counter for successful cases (last person sits in their proper seat)

    for (int i = 0; i < trials; i++)
    {
        successCount += simulateBoarding(n); // Add 1 if the last person sits in their seat
    }

    // Calculate and display the probability
    double probability = (double)successCount / trials;
    printf("Probability that the last person sits in their proper seat: %.6f\n", probability);

    return 0;
}
