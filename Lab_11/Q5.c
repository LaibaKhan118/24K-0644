/*Q: Define a structure Date with fields day, month, and year.Create another structure Event with fields event_name, date(nested Date structure), and location.Write a program to display all event details in a readable format.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char event_name[100];
    Date event_date;
    char location[200];
} Event;

int main()
{
    Event events[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter details for Event %d:\n", i + 1);

        printf("Enter event name: ");
        fgets(events[i].event_name, sizeof(events[i].event_name), stdin);
        events[i].event_name[strcspn(events[i].event_name, "\n")] = '\0';

        printf("Enter day of event: ");
        scanf("%d", &events[i].event_date.day);

        printf("Enter month of event: ");
        scanf("%d", &events[i].event_date.month);

        printf("Enter year of event: ");
        scanf("%d", &events[i].event_date.year);
        getchar();
        printf("Enter event location: ");
        fgets(events[i].location, sizeof(events[i].location), stdin);
        events[i].location[strcspn(events[i].location, "\n")] = '\0';
    }

    printf("\nEvent Details:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Event %d:\n", i + 1);
        printf("  Name      : %s\n", events[i].event_name);
        printf("  Date      : %d-%d-%d\n", events[i].event_date.day, events[i].event_date.month, events[i].event_date.year);
        printf("  Location  : %s\n", events[i].location);
        printf("\n");
    }

    return 0;
}
