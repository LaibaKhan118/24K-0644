#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Content
{
    char title[100];
    double rating;
    int runtime; // in minutes
    char encodingFormats[100];
};

struct UserProfile
{
    double *engagementRow;
    double *devicePreferences;
};

double **allocateDeviceMatrix(int numUsers, int numDevices);
double **allocateEngagementMatrix(int numUsers, int numCategories);
void displayMatrix(double **matrix, int rows, int cols);
void displayUserProfile(const struct UserProfile *user, int numCategories, int numDevices);
void displayContent(const struct Content *content);
void inputUserProfile(struct UserProfile *user, int numCategories, int numDevices);
void inputContent(struct Content *content);

int main()
{
    int numUsers, numCategories, numDevices;

    printf("Enter number of users: ");
    scanf("%d", &numUsers);
    printf("Enter number of categories: ");
    scanf("%d", &numCategories);
    printf("Enter number of devices: ");
    scanf("%d", &numDevices);

    struct UserProfile *users = (struct UserProfile *)malloc(numUsers * sizeof(struct UserProfile));
    struct Content *content = (struct Content *)malloc(numCategories * sizeof(struct Content));
    double **engagementMatrix = allocateEngagementMatrix(numUsers, numCategories);
    double **deviceMatrix = allocateDeviceMatrix(numUsers, numDevices);

    for (int i = 0; i < numCategories; i++)
    {
        printf("Enter details for content %d:\n", i + 1);
        inputContent(&content[i]);
    }

    for (int i = 0; i < numUsers; i++)
    {
        printf("Enter details for user %d:\n", i + 1);
        inputUserProfile(&users[i], numCategories, numDevices);
    }

    printf("\n--- Content Information ---\n");
    for (int i = 0; i < numCategories; i++)
    {
        displayContent(&content[i]);
    }

    printf("\n--- User Profiles ---\n");
    for (int i = 0; i < numUsers; i++)
    {
        displayUserProfile(&users[i], numCategories, numDevices);
    }

    printf("\n--- Engagement Matrix ---\n");
    displayMatrix(engagementMatrix, numUsers, numCategories);

    printf("\n--- Device Matrix ---\n");
    displayMatrix(deviceMatrix, numUsers, numDevices);

    for (int i = 0; i < numUsers; i++)
    {
        free(users[i].engagementRow);
        free(users[i].devicePreferences);
    }
    for (int i = 0; i < numUsers; i++)
    {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);
    free(users);
    free(content);

    return 0;
}

void inputContent(struct Content *content)
{
    printf("Enter content title: ");
    getchar();
    fgets(content->title, sizeof(content->title), stdin);
    content->title[strcspn(content->title, "\n")] = '\0';
    printf("Enter content rating: ");
    scanf("%lf", &content->rating);
    printf("Enter content runtime (in minutes): ");
    scanf("%d", &content->runtime);
    printf("Enter content encoding formats: ");
    getchar();
    fgets(content->encodingFormats, sizeof(content->encodingFormats), stdin);
    content->encodingFormats[strcspn(content->encodingFormats, "\n")] = '\0';
}

void inputUserProfile(struct UserProfile *user, int numCategories, int numDevices)
{
    user->engagementRow = (double *)malloc(numCategories * sizeof(double));
    user->devicePreferences = (double *)malloc(numDevices * sizeof(double));
    for (int i = 0; i < numCategories; i++)
    {
        printf("Enter engagement score for category %d: ", i + 1);
        scanf("%lf", &user->engagementRow[i]);
    }
    for (int i = 0; i < numDevices; i++)
    {
        printf("Enter device preference for device %d: ", i + 1);
        scanf("%lf", &user->devicePreferences[i]);
    }
}

void displayContent(const struct Content *content)
{
    printf("Title: %s\n", content->title);
    printf("Rating: %.2lf\n", content->rating);
    printf("Runtime: %d minutes\n", content->runtime);
    printf("Encoding Formats: %s\n", content->encodingFormats);
}

void displayUserProfile(const struct UserProfile *user, int numCategories, int numDevices)
{
    printf("Engagement Scores:\n");
    for (int i = 0; i < numCategories; i++)
    {
        printf("Category %d: %.2lf\n", i + 1, user->engagementRow[i]);
    }
    printf("Device Preferences:\n");
    for (int i = 0; i < numDevices; i++)
    {
        printf("Device %d: %.2lf\n", i + 1, user->devicePreferences[i]);
    }
}

void displayMatrix(double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double **allocateEngagementMatrix(int numUsers, int numCategories)
{
    double **matrix = (double **)malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++)
    {
        matrix[i] = (double *)malloc(numCategories * sizeof(double));
        for (int j = 0; j < numCategories; j++)
        {
            printf("Enter engagement score for user %d, category %d: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

double **allocateDeviceMatrix(int numUsers, int numDevices)
{
    double **matrix = (double **)malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++)
    {
        matrix[i] = (double *)malloc(numDevices * sizeof(double));
        for (int j = 0; j < numDevices; j++)
        {
            printf("Enter device preference for user %d, device %d: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}
