#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000   // Maximum number of words in a file
#define MAX_LENGTH 80    // Maximum length of a line

// Function prototypes
void findLongestWords(char words[][MAX_LENGTH], int wordCount, char longestWords[3][MAX_LENGTH]);
void concatenateWords(char *line, char *result);
void processFile(const char *inputFileName, const char *outputFileName);

int main() {
    // Process the input file and generate the output file
    processFile("input.txt", "output.txt");

    return 0;
}

// Function to find the three longest words in the list
void findLongestWords(char words[][MAX_LENGTH], int wordCount, char longestWords[3][MAX_LENGTH]) {
    int lengths[MAX_WORDS];
    for (int i = 0; i < wordCount; i++) {
        lengths[i] = strlen(words[i]);
    }

    // Find the three longest words
    for (int i = 0; i < 3; i++) {
        int maxIndex = -1;
        int maxLength = -1;
        for (int j = 0; j < wordCount; j++) {
            if (lengths[j] > maxLength) {
                maxLength = lengths[j];
                maxIndex = j;
            }
        }
        strcpy(longestWords[i], words[maxIndex]);
        lengths[maxIndex] = -1;  // Mark as used
    }
}

// Function to concatenate words surrounded by <s> and remove the <s> tags
void concatenateWords(char *line, char *result) {
    char *start = strstr(line, "<s>");
    char *end;
    char concatenated[MAX_LENGTH] = "";

    while (start != NULL) {
        end = strstr(start, "</s>");
        if (end != NULL) {
            char temp[MAX_LENGTH];
            strncpy(temp, start + 3, end - start - 3);  // Copy the content inside <s> tags
            temp[end - start - 3] = '\0';
            strcat(concatenated, temp);
            start = strstr(end + 4, "<s>");
        } else {
            break;
        }
    }

    // Replace the <s> block in the line with the concatenated word
    strcpy(result, line);
    char *tagStart = strstr(result, "<s>");
    if (tagStart) {
        strcpy(tagStart, concatenated);
    }
}

// Function to process the input file and generate the output file
void processFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Could not open input or output file.\n");
        return;
    }

    char words[MAX_WORDS][MAX_LENGTH];
    char longestWords[3][MAX_LENGTH];
    char line[MAX_LENGTH];
    int wordCount = 0;

    // Read words from the file
    while (fscanf(inputFile, "%s", words[wordCount]) == 1) {
        wordCount++;
    }

    // Find the longest words
    findLongestWords(words, wordCount, longestWords);

    // Reset the file pointer to process line by line
    rewind(inputFile);

    printf("The 3 longest words are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", longestWords[i]);
    }

    // Process each line
    while (fgets(line, MAX_LENGTH, inputFile)) {
        // Add <L> tags to the longest words
        for (int i = 0; i < 3; i++) {
            char *pos = strstr(line, longestWords[i]);
            if (pos) {
                char temp[MAX_LENGTH];
                strncpy(temp, line, pos - line);
                temp[pos - line] = '\0';
                strcat(temp, "<L>");
                strcat(temp, longestWords[i]);
                strcat(temp, "<L>");
                strcat(temp, pos + strlen(longestWords[i]));
                strcpy(line, temp);
            }
        }

        // Concatenate words surrounded by <s> tags
        char result[MAX_LENGTH];
        concatenateWords(line, result);

        // Write the modified line to the output file
        fprintf(outputFile, "%s", result);
    }

    fclose(inputFile);
    fclose(outputFile);
}
