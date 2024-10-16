// 2022 mid A, Q3
// Given the cards of two people, check who has the stronger hand.
#include <stdio.h>

int main() {
    int a_ranks[5], b_ranks[5];
    char a_suit[5], b_suit[5], r = 'N';
    int a_same_s = 0, b_same_s = 0, a_same_r = 0, b_same_r = 0, alice = 0, bob = 0, draw = 0, a_strength = 0, b_strength = 0;
    printf("\n\t\t\tWelcome\n\n");
    printf("Usgae: Use 11 for Jack, 12 for Queen, 13 for King, and 14 for Ace\nUse h for hearts, d for diamonds, c for clubs, and s spades\n");
    
    do {
        printf("\nEnter Alice's cards:\n\n");
        for (int i = 0; i < 5; i++) {
            printf("Enter Card Number:\t");
            scanf("%d", &a_ranks[i]);
            printf("Enter the card's suit (h, d, c, s):\t");
            scanf(" %c", &a_suit[i]);
        }
        
        // Flush
        for (int i = 0; i < 5; i++) {
            a_same_s = 0;
            for (int j = 0; j < 5; j++) {
                if (a_suit[i] == a_suit[j]) {
                    a_same_s++;
                }
            }
        }
        
        // pair of 3's
        for (int i = 0; i < 5; i++) {
            a_same_r = 0;
            for (int j = 0; j < 5; j++) {
                if (a_ranks[i] == a_ranks[j]) {
                    a_same_r++;
                }
            }
        }
        
        if (a_same_s == 5) {
            a_strength = 1;
        }
        else if(a_same_r == 3) {
            a_strength = 2;
        }
        else {
            a_strength = 3;
        }
        
        printf("\nEnter Bob's cards:\n");
        for (int i = 0; i < 5; i++) {
            printf("Enter Card Number:\t");
            scanf("%d", &b_ranks[i]);
            printf("Enter the card's suit (h, d, c, s):\t");
            scanf(" %c", &b_suit[i]);
        }
        
        // Flush
        for (int i = 0; i < 5; i++) {
            b_same_s = 0;
            for (int j = 0; j < 5; j++) {
                if (b_suit[i] == b_suit[j]) {
                    b_same_s++;
                }
            }
        }
        
        // pair of 3's
        for (int i = 0; i < 5; i++) {
            b_same_r = 0;
            for (int j = 0; j < 5; j++) {
                if (b_ranks[i] == b_ranks[j]) {
                    b_same_r++;
                }
            }
        }
        
        if (b_same_s == 5) {
            b_strength = 1;
        }
        else if(b_same_r == 3) {
            b_strength = 2;
        }
        else {
            b_strength = 3;
        }
        
        // Winner
        if (a_strength > b_strength){
            printf("Winner is Alice\n");
            alice++;
        }
        else if (b_strength > a_strength){
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
