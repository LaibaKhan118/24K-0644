#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_CHARACTERS 100

// Define the GameCharacter structure
typedef struct
{
    char name[81]; // Name of the character (max length = 80 chars + 1 for null terminator)
    int HP;        // Health points
    int AP;        // Attack points
    int DP;        // Defense points
} GameCharacter;

// Function prototypes
int validateCharacter(GameCharacter character);
void createCharacters(GameCharacter characters[], int *count);
void displayCharacters(GameCharacter characters[], int count);
void simulateBattle(GameCharacter characters[], int count);

int main()
{
    GameCharacter characters[MAX_CHARACTERS];
    int count = 0;
    char choice;

    while (1)
    {
        printf("\n1. Create Characters\n2. Display Characters\n3. Simulate Battle\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            createCharacters(characters, &count);
            break;
        case '2':
            displayCharacters(characters, count);
            break;
        case '3':
            simulateBattle(characters, count);
            break;
        case '4':
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to validate a character based on the given rules
int validateCharacter(GameCharacter character)
{
    if (character.HP + character.AP + character.DP != 10)
        return 0; // Rule: HP + AP + DP = 10
    if (character.HP < 1 || character.HP > 5)
        return 0; // Rule: HP between 1 and 5
    if (character.AP < 1 || character.AP > 5)
        return 0; // Rule: AP between 1 and 5
    if (character.DP < 1 || character.DP > 5)
        return 0; // Rule: DP between 1 and 5
    if (character.HP == character.AP || character.HP == character.DP || character.AP == character.DP)
        return 0; // Rule: No points can be same
    return 1;
}

// Function to create characters
void createCharacters(GameCharacter characters[], int *count)
{
    while (1)
    {
        GameCharacter newCharacter;

        printf("\nEnter character name (max 80 characters): ");

        // Read the character's name
        scanf(" %80s", newCharacter.name);

        // Read HP, AP, and DP
        printf("Enter HP (1-5): ");
        scanf("%d", &newCharacter.HP);
        printf("Enter AP (1-5): ");
        scanf("%d", &newCharacter.AP);
        printf("Enter DP (1-5): ");
        scanf("%d", &newCharacter.DP);

        // Validate the character
        if (validateCharacter(newCharacter))
        {
            characters[*count] = newCharacter;
            (*count)++;
            printf("Character added successfully.\n");
        }
        else
        {
            printf("Invalid character attributes. Please try again.\n");
        }

        // Check if the user presses the Escape key
        printf("Press 'Enter' to continue, or 'Escape' to stop adding characters...\n");
        char key = getch(); // Wait for a key press
        if (key == 27)
        { // ASCII value for Escape key is 27
            printf("Exiting character creation...\n");
            break;
        }
    }
}

// Function to display characters
void displayCharacters(GameCharacter characters[], int count)
{
    printf("\nDisplaying all characters:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, HP: %d, AP: %d, DP: %d\n", characters[i].name, characters[i].HP, characters[i].AP, characters[i].DP);
    }
}

// Function to simulate a battle
void simulateBattle(GameCharacter characters[], int count)
{
    if (count < 2)
    {
        printf("At least two characters are required for a battle.\n");
        return;
    }

    int index1, index2;
    printf("Enter index of first character (0 to %d): ", count - 1);
    scanf("%d", &index1);
    printf("Enter index of second character (0 to %d): ", count - 1);
    scanf("%d", &index2);

    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count || index1 == index2)
    {
        printf("Invalid indexes. Try again.\n");
        return;
    }

    GameCharacter *char1 = &characters[index1];
    GameCharacter *char2 = &characters[index2];

    printf("Simulating battle between %s and %s...\n", char1->name, char2->name);

    // Battle logic
    int damageToChar1 = char2->AP - char1->DP;
    int damageToChar2 = char1->AP - char2->DP;

    if (damageToChar1 < 0)
        damageToChar1 = 0;
    if (damageToChar2 < 0)
        damageToChar2 = 0;

    int finalHP1 = char1->HP - damageToChar1;
    int finalHP2 = char2->HP - damageToChar2;

    printf("%s's final HP: %d\n", char1->name, finalHP1);
    printf("%s's final HP: %d\n", char2->name, finalHP2);

    if (finalHP1 > finalHP2)
    {
        printf("%s wins!\n", char1->name);
    }
    else if (finalHP1 < finalHP2)
    {
        printf("%s wins!\n", char2->name);
    }
    else
    {
        printf("It's a tie!\n");
    }
}
