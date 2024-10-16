// 2022 mid A, Q3
// Given the cards of two people, check who has the stronger hand.
#include <stdio.h>

int main() {
    int a_ranks[5], b_ranks[5], a_r_freq[15] = {0}, b_r_freq[15] = {0}, a_s_freq[4] = {0}, b_s_freq[4] = {0};
    char a_suit[5], b_suit[5], r = 'N';
    int a_same_s = 0, b_same_s = 0, a_same_r = 0, b_same_r = 0, alice = 0, bob = 0, draw = 0, a_strength = 0, b_strength = 0;
    printf("\n\t\t\tWelcome\n\n");
    printf("Usgae: Use 11 for Jack, 12 for Queen, 13 for King, and 14 for Ace\nUse h for hearts, d for diamonds, c for clubs, and s spades\n");
    
    do {
        printf("\nEnter Alice's cards:\n\n");
        for (int i = 0; i < 5; i++) {
            printf("Enter Card Number:\t");
            scanf("%d", &a_ranks[i]);
            a_r_freq[a_ranks[i]]++;
            printf("Enter the card's suit (h, d, c, s):\t");
            scanf(" %c", &a_suit[i]);
        }
        
        // Flush
        for (int i = 0; a_suit[i] != '\0'; i++) {
            switch (a_suit[i]) {
                case 'h':
                    a_s_freq[0]++; // Increment for 'h'
                    break;
                case 'd':
                    a_s_freq[1]++; // Increment for 'd'
                    break;
                case 's':
                    a_s_freq[2]++; // Increment for 's'
                    break;
                case 'c':
                    a_s_freq[3]++; // Increment for 'c'
                    break;
                default:
                    break; // Ignore other characters
            }
        }
        for (int i = 0; i < 4; i++) {
            if (a_s_freq[i] == 5) {
                a_same_s =1;
                break;
            }
        }
        // pair of 3's
        for (int i = 0; i < 15; i++) {
            if(a_r_freq[i] == 3) {
                a_same_r = 1; //true
                break;
            }
        }
        
        if (a_same_s == 1) {
            a_strength = 1;
        }
        else if(a_same_r == 1) {
            a_strength = 2;
        }
        else {
            a_strength = 3;
        }
        
        printf("\nEnter Bob's cards:\n");
        for (int i = 0; i < 5; i++) {
            printf("Enter Card Number:\t");
            scanf("%d", &b_ranks[i]);
            b_r_freq[b_ranks[i]]++;
            printf("Enter the card's suit (h, d, c, s):\t");
            scanf(" %c", &b_suit[i]);
        }
        
        // Flush
        for (int i = 0; b_suit[i] != '\0'; i++) {
            switch (b_suit[i]) {
                case 'h':
                    b_s_freq[0]++; // Increment for 'h'
                    break;
                case 'd':
                    b_s_freq[1]++; // Increment for 'd'
                    break;
                case 's':
                    b_s_freq[2]++; // Increment for 's'
                    break;
                case 'c':
                    b_s_freq[3]++; // Increment for 'c'
                    break;
                default:
                    break; // Ignore other characters
            }
        }
        for (int i = 0; i < 4; i++) {
            if (b_s_freq[i] == 5) {
                b_same_s =1;
                break;
            }
        }
        // pair of 3's
        for (int i = 0; i < 15; i++) {
            if(b_r_freq[i] == 3) {
                b_same_r = 1; //true
                break;
            }
        }
        
        if (b_same_s == 1) {
            b_strength = 1;
        }
        else if(b_same_r == 1) {
            b_strength = 2;
        }
        else {
            b_strength = 3;
        }
        
        // Winner
        if (a_strength < b_strength){
            printf("Winner is Alice\n");
            alice++;
        }
        else if (b_strength < a_strength){
            printf("Winner is Bob\n");
            bob++;
        }
        else {
            printf("Draw.\n");
            draw++;
        }
        
        // Another round?
        printf("\nEnter Y if you want play another round:\t");
        scanf(" %c", &r);
    } while(r == 'y' || r == 'Y');
    
    printf("\n\nResults\nWins of Alice: %d\nWins of Bob: %d\nDraw: %d\n", alice, bob, draw);
    return 0;
}
