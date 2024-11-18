/*Defne a date structure with variables day, month and year. Write functions to
1. Calculate the number of days between two days.
2. Find the day of the week for a given date
3. Check if a date is valid accounting for leap years.*/

#include <stdio.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;

int n_days (Date d1, Date d2);
void Day_of_week(Date d);
int leap(int yr);
void valid_Date(Date d);

int main()
{
    Date d1 = {1, 1, 2000};
    Date d2 = {1,1,2024};
    
    return 0;
}
