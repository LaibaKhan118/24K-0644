#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char type[50];
    char growthStage[50];
    float expectedYield;
} Crop;

typedef struct
{
    float temperature;
    float rainfall;
    float windPatterns;
} WeatherForecast;

typedef struct
{
    char name[50];
    int operationalStatus; // 1 for active, 0 for inactive
    float fuelLevel;
    char schedule[100];
} Equipment;

typedef struct
{
    float soilNutrients;
    float pHLevel;
    float pestActivity;
} Sensor;

typedef struct
{
    char gpsCoordinates[100];
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int cropCount;
    WeatherForecast *weather;
    Equipment *equipmentArray;
    int equipmentCount;
    Sensor *sensors;
    int sensorCount;
} Field;

typedef struct
{
    Field *fields;
    int fieldCount;
} RegionalHub;

void addField(RegionalHub *hub);
void displayHubDetails(RegionalHub *hub);

int main()
{
    RegionalHub hub;
    hub.fields = NULL;
    hub.fieldCount = 0;

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Field\n");
        printf("2. Display Regional Hub Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addField(&hub);
            break;
        case 2:
            displayHubDetails(&hub);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    for (int i = 0; i < hub.fieldCount; i++)
    {
        free(hub.fields[i].crops);
        free(hub.fields[i].weather);
        free(hub.fields[i].equipmentArray);
        free(hub.fields[i].sensors);
    }
    free(hub.fields);

    return 0;
}

void addField(RegionalHub *hub)
{
    hub->fields = (Field *)realloc(hub->fields, (hub->fieldCount + 1) * sizeof(Field));
    Field *newField = &hub->fields[hub->fieldCount];
    hub->fieldCount++;

    printf("Enter GPS Coordinates: ");
    scanf(" %[^\n]s", newField->gpsCoordinates);
    printf("Enter Soil Health: ");
    scanf("%f", &newField->soilHealth);
    printf("Enter Moisture Level: ");
    scanf("%f", &newField->moistureLevel);

    // Crops
    printf("Enter number of crops: ");
    scanf("%d", &newField->cropCount);
    newField->crops = (Crop *)malloc(newField->cropCount * sizeof(Crop));
    for (int i = 0; i < newField->cropCount; i++)
    {
        printf("Enter Crop Type: ");
        scanf(" %[^\n]s", newField->crops[i].type);
        printf("Enter Growth Stage: ");
        scanf(" %[^\n]s", newField->crops[i].growthStage);
        printf("Enter Expected Yield: ");
        scanf("%f", &newField->crops[i].expectedYield);
    }

    // Weather forecast
    newField->weather = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    printf("Enter Temperature: ");
    scanf("%f", &newField->weather->temperature);
    printf("Enter Rainfall: ");
    scanf("%f", &newField->weather->rainfall);
    printf("Enter Wind Patterns: ");
    scanf("%f", &newField->weather->windPatterns);

    // Equipment
    printf("Enter number of equipment: ");
    scanf("%d", &newField->equipmentCount);
    newField->equipmentArray = (Equipment *)malloc(newField->equipmentCount * sizeof(Equipment));
    for (int i = 0; i < newField->equipmentCount; i++)
    {
        printf("Enter Equipment Name: ");
        scanf(" %[^\n]s", newField->equipmentArray[i].name);
        printf("Enter Operational Status (1 for active, 0 for inactive): ");
        scanf("%d", &newField->equipmentArray[i].operationalStatus);
        printf("Enter Fuel Level: ");
        scanf("%f", &newField->equipmentArray[i].fuelLevel);
        printf("Enter Schedule: ");
        scanf(" %[^\n]s", newField->equipmentArray[i].schedule);
    }

    // Sensors
    printf("Enter number of sensors: ");
    scanf("%d", &newField->sensorCount);
    newField->sensors = (Sensor *)malloc(newField->sensorCount * sizeof(Sensor));
    for (int i = 0; i < newField->sensorCount; i++)
    {
        printf("Enter Soil Nutrients Level: ");
        scanf("%f", &newField->sensors[i].soilNutrients);
        printf("Enter pH Level: ");
        scanf("%f", &newField->sensors[i].pHLevel);
        printf("Enter Pest Activity Level: ");
        scanf("%f", &newField->sensors[i].pestActivity);
    }

    printf("Field added successfully!\n");
}

void displayHubDetails(RegionalHub *hub)
{
    for (int i = 0; i < hub->fieldCount; i++)
    {
        Field *field = &hub->fields[i];
        printf("\nField %d:\n", i + 1);
        printf("GPS Coordinates: %s\n", field->gpsCoordinates);
        printf("Soil Health: %.2f\n", field->soilHealth);
        printf("Moisture Level: %.2f\n", field->moistureLevel);

        printf("Crops:\n");
        for (int j = 0; j < field->cropCount; j++)
        {
            printf("  Type: %s, Growth Stage: %s, Expected Yield: %.2f\n",
                   field->crops[j].type, field->crops[j].growthStage, field->crops[j].expectedYield);
        }

        printf("Weather Forecast:\n");
        printf("  Temperature: %.2f, Rainfall: %.2f, Wind Patterns: %.2f\n",
               field->weather->temperature, field->weather->rainfall, field->weather->windPatterns);

        printf("Equipment:\n");
        for (int j = 0; j < field->equipmentCount; j++)
        {
            printf("  Name: %s, Status: %s, Fuel Level: %.2f, Schedule: %s\n",
                   field->equipmentArray[j].name,
                   field->equipmentArray[j].operationalStatus ? "Active" : "Inactive",
                   field->equipmentArray[j].fuelLevel,
                   field->equipmentArray[j].schedule);
        }

        printf("Sensors:\n");
        for (int j = 0; j < field->sensorCount; j++)
        {
            printf("  Soil Nutrients: %.2f, pH Level: %.2f, Pest Activity: %.2f\n",
                   field->sensors[j].soilNutrients, field->sensors[j].pHLevel, field->sensors[j].pestActivity);
        }
    }
}
