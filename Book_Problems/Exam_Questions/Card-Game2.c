// 2022 mid B, Q3
// Given the cards of two people, check who has the stronger hand.
#include <stdio.h>

int main() {
	int a_ranks[5], b_ranks[5], a_freq[15] = {0}, b_freq[15] = {0};
	char a_suit[5], b_suit[5], r = 'N';
	int a_pair = 0, b_pair = 0, a_kind_4 = 0, b_kind_4 = 0, alice = 0, bob = 0, draw = 0, a_strength = 0, b_strength = 0, count;
	printf("\n\t\t\tWelcome\n\n");
	printf("Usgae: Use 11 for Jack, 12 for Queen, 13 for King, and 14 for Ace\nUse h for hearts, d for diamonds, c for clubs, and s spades\n");

	do {
		printf("\nEnter Alice's cards:\n\n");
		for (int i = 0; i < 5; i++) {
			printf("Enter Card Number:\t");
			scanf("%d", &a_ranks[i]);
			a_freq[a_ranks[i]]++;
			// Commenting out the input of suit letters because I am not if I should include it or not since it's of no use
			/*printf("Enter the card's suit (h, d, c, s):\t");
			scanf(" %c", &a_suit[i]);*/
		}


		for (int i = 2; i < 15; i++) {
			// 4 of a kind
			if (a_freq[i] == 4) {
				a_kind_4 = 1;
			}
            // pair of 2
			else if (a_freq[i] == 2) {
				a_pair++;
			}
		}

		if (a_kind_4 == 1) {
			a_strength = 1;
		}
		else if(a_pair == 2) {
			a_strength = 2;
		}
		else {
			a_strength = 3;
		}

		printf("\nAlice's strength: %d\n", a_strength);

		printf("\nEnter Bob's cards:\n");
		for (int i = 0; i < 5; i++) {
			printf("Enter Card Number:\t");
			scanf("%d", &b_ranks[i]);
			b_freq[b_ranks[i]]++;
			// Commenting out the input of suit letters because I am not if I should include it or not since it's of no use
			/*printf("Enter the card's suit (h, d, c, s):\t");
			scanf(" %c", &b_suit[i]);*/
		}

		for (int i = 2; i < 15; i++) {
			// 4 of a kind
			if (b_freq[i] == 4) {
				b_kind_4 = 1;
			}
			// pair of 2
			else if (b_freq[i] == 2) {
				b_pair++;
			}
		}

		if (b_kind_4 == 1) {
			b_strength = 1;
		}
		else if(b_pair == 2) {
			b_strength = 2;
		}
		else {
			b_strength = 3;
		}

		printf("\nBob's strength: %d\n", b_strength);

		// Winner
		if (a_strength < b_strength) {
			printf("Winner is Alice\n");
			alice++;
		}
		else if (b_strength < a_strength) {
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
