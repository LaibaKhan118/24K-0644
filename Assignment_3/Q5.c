#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***initializeInventory(int numSpecies, int *suppliesCount);
void addSupplies(char ***speciesSupplies, int speciesIndex, int *suppliesCount);
void updateSupply(char ***speciesSupplies, int speciesIndex, int suppliesCount);
void removeSpecies(char ***speciesSupplies, int *suppliesCount, int *numSpecies, int speciesIndex);
void displayInventory(char ***speciesSupplies, int *suppliesCount, int numSpecies);

int main()
{
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    int *suppliesCount = (int *)malloc(numSpecies * sizeof(int));
    char ***speciesSupplies = initializeInventory(numSpecies, suppliesCount);

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
        {
            int speciesIndex;
            printf("Enter species index (0 to %d): ", numSpecies - 1);
            scanf("%d", &speciesIndex);
            if (speciesIndex >= 0 && speciesIndex < numSpecies)
            {
                addSupplies(speciesSupplies, speciesIndex, suppliesCount);
            }
            else
            {
                printf("Invalid species index.\n");
            }
            break;
        }
        case 2:
        {
            int speciesIndex;
            printf("Enter species index (0 to %d): ", numSpecies - 1);
            scanf("%d", &speciesIndex);
            if (speciesIndex >= 0 && speciesIndex < numSpecies)
            {
                updateSupply(speciesSupplies, speciesIndex, suppliesCount[speciesIndex]);
            }
            else
            {
                printf("Invalid species index.\n");
            }
            break;
        }
        case 3:
        {
            int speciesIndex;
            printf("Enter species index (0 to %d): ", numSpecies - 1);
            scanf("%d", &speciesIndex);
            removeSpecies(speciesSupplies, suppliesCount, &numSpecies, speciesIndex);
            break;
        }
        case 4:
            displayInventory(speciesSupplies, suppliesCount, numSpecies);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    for (int i = 0; i < numSpecies; i++)
    {
        for (int j = 0; j < suppliesCount[i]; j++)
        {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    free(suppliesCount);

    return 0;
}

// ===== Functions =====
char ***initializeInventory(int numSpecies, int *suppliesCount)
{
    char ***speciesSupplies = (char ***)malloc(numSpecies * sizeof(char **));
    for (int i = 0; i < numSpecies; i++)
    {
        speciesSupplies[i] = NULL;
        suppliesCount[i] = 0;
    }
    return speciesSupplies;
}

void addSupplies(char ***speciesSupplies, int speciesIndex, int *suppliesCount)
{
    int numSupplies;
    printf("Enter the number of supplies to add for species %d: ", speciesIndex + 1);
    scanf("%d", &numSupplies);

    speciesSupplies[speciesIndex] = (char **)realloc(speciesSupplies[speciesIndex], (suppliesCount[speciesIndex] + numSupplies) * sizeof(char *));

    for (int i = 0; i < numSupplies; i++)
    {
        printf("Enter supply name: ");
        char buffer[100];
        scanf("%s", buffer);

        speciesSupplies[speciesIndex][suppliesCount[speciesIndex]] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(speciesSupplies[speciesIndex][suppliesCount[speciesIndex]], buffer);
        suppliesCount[speciesIndex]++;
    }
}

void updateSupply(char ***speciesSupplies, int speciesIndex, int suppliesCount)
{
    if (suppliesCount == 0)
    {
        printf("No supplies to update for this species.\n");
        return;
    }

    int supplyIndex;
    printf("Enter the index of the supply to update (0 to %d): ", suppliesCount - 1);
    scanf("%d", &supplyIndex);

    if (supplyIndex < 0 || supplyIndex >= suppliesCount)
    {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter the new supply name: ");
    char buffer[100];
    scanf("%s", buffer);

    free(speciesSupplies[speciesIndex][supplyIndex]);
    speciesSupplies[speciesIndex][supplyIndex] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(speciesSupplies[speciesIndex][supplyIndex], buffer);
}

void removeSpecies(char ***speciesSupplies, int *suppliesCount, int *numSpecies, int speciesIndex)
{
    if (speciesIndex < 0 || speciesIndex >= *numSpecies)
    {
        printf("Invalid species index.\n");
        return;
    }

    for (int i = 0; i < suppliesCount[speciesIndex]; i++)
    {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++)
    {
        speciesSupplies[i] = speciesSupplies[i + 1];
        suppliesCount[i] = suppliesCount[i + 1];
    }

    (*numSpecies)--;
}

void displayInventory(char ***speciesSupplies, int *suppliesCount, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Species %d supplies: ", i + 1);
        for (int j = 0; j < suppliesCount[i]; j++)
        {
            printf("%s ", speciesSupplies[i][j]);
        }
        printf("\n");
    }
}
