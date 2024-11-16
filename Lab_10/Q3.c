#include <stdio.h>

#define MAX_TEMP 40.0

void check_temp(float temp[], int n, int index);

int main()
{
    float temp[100];
    int n;
    printf("Enter number of temperature inputs you want to check:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter temperature %d:\t", i + 1);
        scanf("%f", &temp[i]);
    }
    check_temp(temp, n, 0);

    return 0;
}

void check_temp(float temp[], int n, int index)
{
    static int count = 0;

    if (index < n)
    {
        if (temp[index] > MAX_TEMP)
        {
            count++;
        }
        check_temp(temp, n, index + 1);
    }
    else {
        printf("The temperature exceeded %d times\n", count);
        return;
    }
}
