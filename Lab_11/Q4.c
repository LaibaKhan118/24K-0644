/*Q: Create a program that defines a structure Student with fields roll_no, name, and
another nested structure Marks (fields: maths, science, and english). Use an array of
Student to store data for 5 students and calculate the average marks for each student.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    float math;
    float science;
    float english;
} Marks;

typedef struct
{
    int roll_no;
    char name[50];
    Marks score;
} StudentInfo;

float avg(float s1, float s2, float s3);

int main()
{
    StudentInfo student[5];
    float average = 0.0;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the roll number of the student %d: ", i + 1);
        scanf("%d", &student[i].roll_no);
        getchar(); // Consume newline left by scanf
        printf("Enter the name of the student %d: ", i + 1);
        fgets(student[i].name, sizeof(student[i].name), stdin);
        // Remove newline character from name, if present
        student[i].name[strcspn(student[i].name, "\n")] = '\0';
        printf("Enter the math marks of the student %d: ", i + 1);
        scanf("%f", &student[i].score.math);
        printf("Enter the science marks of the student %d: ", i + 1);
        scanf("%f", &student[i].score.science);
        printf("Enter the english marks of the student %d: ", i + 1);
        scanf("%f", &student[i].score.english);
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        average = avg(student[i].score.math, student[i].score.science, student[i].score.english);
        printf("Average marks of %s (Roll No: %d) is %.2f\n", student[i].name, student[i].roll_no, average);
    }

    return 0;
}

float avg(float s1, float s2, float s3)
{
    return ((s1 + s2 + s3) / 3);
}
