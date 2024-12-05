/*Q4: Student Struct with File Handling

Create a program to manage student data using a structure with the following fields:
name, roll , and marks (5 subjects).
Perform the following tasks:

1. Add student data (name, roll, marks).
2. Save the student data to a file.
3. Display student data.
4. Calculate total marks, percentage, and grade based on marks.
5. Write updated results back to the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct {
    char name[50];
    int roll;
    int marks[5];
    int totalMarks;
    float percentage;
    char grade;
} Student;

// Function prototypes
void addStudent(Student *student);
void calculateResults(Student *student);
void saveToFile(Student *students, int count, const char *filename);
void readFromFile(const char *filename);
char calculateGrade(float percentage);

int main() {
    const char *filename = "student_data.txt";
    int choice, studentCount = 0;

    // Array to hold students
    Student students[100];

    while (1) {
        printf("\n*** Student Management System ***\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save Data to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (studentCount < 100) {
                    printf("\nAdding a new student...\n");
                    addStudent(&students[studentCount]);
                    calculateResults(&students[studentCount]);
                    studentCount++;
                } else {
                    printf("Maximum student limit reached!\n");
                }
                break;

            case 2:
                printf("\nDisplaying students from the file:\n");
                readFromFile(filename);
                break;

            case 3:
                printf("\nSaving data to the file...\n");
                saveToFile(students, studentCount, filename);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add student data
void addStudent(Student *student) {
    printf("Enter student's name: ");
    scanf(" %[^\n]", student->name); // Read string with spaces
    printf("Enter roll number: ");
    scanf("%d", &student->roll);
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &student->marks[i]);
    }
}

// Function to calculate total marks, percentage, and grade
void calculateResults(Student *student) {
    student->totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        student->totalMarks += student->marks[i];
    }
    student->percentage = (float)student->totalMarks / 5;
    student->grade = calculateGrade(student->percentage);
}

// Function to calculate grade based on percentage
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    if (percentage >= 80) return 'B';
    if (percentage >= 70) return 'C';
    if (percentage >= 60) return 'D';
    return 'F';
}

// Function to save student data to a file
void saveToFile(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Name: %s\n", students[i].name);
        fprintf(file, "Roll: %d\n", students[i].roll);
        fprintf(file, "Marks: ");
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%d ", students[i].marks[j]);
        }
        fprintf(file, "\nTotal Marks: %d\n", students[i].totalMarks);
        fprintf(file, "Percentage: %.2f\n", students[i].percentage);
        fprintf(file, "Grade: %c\n\n", students[i].grade);
    }

    fclose(file);
    printf("Data saved successfully to %s.\n", filename);
}

// Function to read student data from a file
void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading or file does not exist!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
