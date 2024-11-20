/*Define a date structure with variables day, month and year. Write functions to
1. Calculate the number of days between two days.
2. Find the day of the week for a given date
3. Check if a date is valid accounting for leap years.*/

#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int n_days(Date d1, Date d2);
int day_of_week(Date date);
int valid_Date(Date date);
int leap_yr(int year);
int days_from_start(Date date);

int main()
{
    Date date_1, date_2;
    int op;
    while (1)
    {
        printf("\nMenu\t\t\n");
        printf("1. Calculate days between two dates.\n2. Find the Day of the week\n3. Check if the Date is Valid or not\n4. Exit\n");
        printf("Select an option:\t");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Date 1:\n");
            printf("Enter the day(DD):\t");
            scanf("%d", &date_1.day);
            printf("Enter the month(MM):\t");
            scanf("%d", &date_1.month);
            printf("Enter the year(YYYY):\t");
            scanf("%d", &date_1.year);

            printf("Date 2:\n");
            printf("Enter the day(DD):\t");
            scanf("%d", &date_2.day);
            printf("Enter the month(MM):\t");
            scanf("%d", &date_2.month);
            printf("Enter the year(YYYY):\t");
            scanf("%d", &date_2.year);

            if (!valid_Date(date_1) || !valid_Date(date_2))
            {
                printf("One or both dates are invalid.\n");
                break;
            }

            int days = n_days(date_1, date_2);
            printf("The Number of Days Between Date 1 and Date 2: %d", days);
            break;

        case 2:
            printf("Date:\n");
            printf("Enter the day (DD):\t");
            scanf("%d", &date_1.day);
            printf("Enter the month (MM):\t");
            scanf("%d", &date_1.month);
            printf("Enter the year (YYYY):\t");
            scanf("%d", &date_1.year);

            char all_days[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

            printf("Day of the week for the given date: %s\n", all_days[day_of_week(date_1)]);
            break;

        case 3:
            printf("Date:\n");
            printf("Enter the day(DD):\t");
            scanf("%d", &date_1.day);
            printf("Enter the month(MM):\t");
            scanf("%d", &date_1.month);
            printf("Enter the year(YYYY):\t");
            scanf("%d", &date_1.year);

            if (valid_Date(date_1))
            {
                printf("The date is valid.\n");
            }
            else
            {
                printf("The date is invalid.\n");
            }
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;
            break;

        default:
            printf("Invalid option.\n");
            break;
        }
    }
    return 0;
}

int leap_yr(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_from_start(Date date)
{
    int days = date.day;
    for (int i = 0; i < date.year; i++)
    {
        days += leap_yr(i) ? 366 : 365;
    }

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < date.month - 1; i++)
    {
        days += months[i];
    }

    if (leap_yr(date.year) && date.month > 2)
    {
        days++;
    }
    return days;
}

int n_days(Date d1, Date d2)
{
    int n;
    int days_1 = days_from_start(d1);
    int days_2 = days_from_start(d2);

    n = (days_1 > days_2) ? (days_1 - days_2) : (days_2 - days_1);
    return n;
}

int day_of_week(Date date)
{
    int day = date.day;
    int month = date.month;
    int year = date.year;

    // Zeller’s Congruence

    if (month < 3)
    {
        month += 12;
        year--;
    }

    int week_day = (day + (13 * (month + 1) / 5) + (year % 100) + ((year % 100) / 4) + ((year / 100) / 4) + 5 * (year / 100)) % 7;
    return week_day;
}

int valid_Date(Date date)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.year < 1 || date.day < 1 || date.month < 1 || date.month > 12)
        return 0;
    if (leap_yr(date.year) && date.month == 2)
    {
        return (date.day <= 29) ? 1 : 0;
    }
    else
    {
        return (date.day <= daysInMonth[date.month - 1]) ? 1 : 0;
    }
}
