#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int teamID;
    char name[50];
    int wins;
    int losses;
} Team;

void addNewTeam(FILE *file) {
    Team team;
    printf("Enter Team ID: ");
    scanf("%d", &team.teamID);
    printf("Enter Team Name: ");
    scanf(" %[^\n]", team.name);
    printf("Enter Total Wins: ");
    scanf("%d", &team.wins);
    printf("Enter Total Losses: ");
    scanf("%d", &team.losses);

    fwrite(&team, sizeof(Team), 1, file);
    printf("Team added successfully!\n");
}

void updateTeamRecord(FILE *file) {
    int teamID, found = 0;
    Team team;

    printf("Enter Team ID to update: ");
    scanf("%d", &teamID);

    FILE *tempFile = fopen("temp.bin", "wb");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        return;
    }

    rewind(file);
    while (fread(&team, sizeof(Team), 1, file)) {
        if (team.teamID == teamID) {
            found = 1;
            int choice;
            printf("1. Add Win\n2. Add Loss\nEnter your choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                team.wins++;
            } else if (choice == 2) {
                team.losses++;
            } else {
                printf("Invalid choice.\n");
            }
        }
        fwrite(&team, sizeof(Team), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("teams.bin");
    rename("temp.bin", "teams.bin");

    if (found) {
        printf("Team record updated successfully!\n");
    } else {
        printf("Team not found.\n");
    }
}

void readHighestRecord(FILE *file) {
    Team team, highestWinTeam, highestPercentageTeam;
    int found = 0;
    double highestPercentage = 0.0;

    rewind(file);
    while (fread(&team, sizeof(Team), 1, file)) {
        if (!found || team.wins > highestWinTeam.wins) {
            highestWinTeam = team;
        }
        double totalMatches = team.wins + team.losses;
        if (totalMatches > 0) {
            double winPercentage = (double)team.wins / totalMatches * 100;
            if (!found || winPercentage > highestPercentage) {
                highestPercentage = winPercentage;
                highestPercentageTeam = team;
            }
        }
        found = 1;
    }

    if (found) {
        printf("Team with Highest Wins: %s (Wins: %d)\n", highestWinTeam.name, highestWinTeam.wins);
        printf("Team with Highest Win Percentage: %s (%.2f%%)\n", highestPercentageTeam.name, highestPercentage);
    } else {
        printf("No records found.\n");
    }
}

int main() {
    int choice;
    FILE *file = fopen("teams.bin", "ab+");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    do {
        printf("\nTeam Record Management\n");
        printf("1. Add New Team\n");
        printf("2. Update Team Record\n");
        printf("3. Read Highest Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewTeam(file);
                break;
            case 2:
                file = freopen("teams.bin", "rb+", file); // Reopen for update
                updateTeamRecord(file);
                file = freopen("teams.bin", "ab+", file); // Reopen for append
                break;
            case 3:
                readHighestRecord(file);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    fclose(file);
    return 0;
}
