// 2022 mid Q2
// Write a C program to simulate the parking management system:

#include <stdio.h>

int main() {
    int l_space, m_space, s_space, n, type;
    int score = 0, large = 0, med = 0, small = 0;
    
    printf("\n\t\t\tParking Management System\n\n");
    
    printf("Enter the number of available large spaces:\t");
    scanf("%d", &l_space);
    printf("Enter the number of available medium spaces:\t");
    scanf("%d", &m_space);
    printf("Enter the number of available small spaces:\t");
    scanf("%d", &s_space);
    
    printf("Enter the number cars:\t");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Choose a size number:\t");
        printf("1. Large Car\t2. Medium Car\t3. Small Car\t");
        scanf("%d", &type);
        switch(type) {
            case 1:
                if(l_space > 0) {
                    l_space--;
                    large++;
                    score += 5;
                    printf("Large car parked in large space.\n");
                } 
                else {
                    score -= 50;
                    printf("No space available for a large car.\n");
                }
                break;
            case 2:
                if(m_space > 0) {
                    m_space--;
                    med++;
                    score += 5;
                    printf("Medium car parked in medium space.\n");
                }
                else if(l_space > 0) {
                    l_space--;
                    large++;
                    score += 10;
                    printf("Medium car parked in large space.\n");
                }
                else {
                    score -= 50;
                    printf("No space available for a medium car.\n");
                }
                break;
            case 3:
                if(s_space > 0) {
                    s_space--;
                    small++;
                    score += 5;
                    printf("Small car parked in small space.\n");
                }
                else if(m_space > 0) {
                    m_space--;
                    med++;
                    score += 10;
                    printf("Small car parked in medium space.\n");
                }
                else if(l_space > 0) {
                    l_space--;
                    large++;
                    score += 10;
                    printf("Small car parked in large space.\n");
                } 
                else {
                    score -= 50;
                    printf("No space available for a small car.\n");
                }
                break;
            default:
                printf("Invalid Input");
                return 0;
        }
    }
    
    printf("\nFeedback score: %d\n", score);
    printf("Occupied Large Space: %d\n", large);
    printf("Occupied Medium Space: %d\n", med);
    printf("Occupied Small Space: %d\n", small);
    return 0;
}
