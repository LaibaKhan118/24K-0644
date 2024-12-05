#include <stdio.h>
#include <stdlib.h>

// Define the structure for Student
typedef struct {
    char name[50];
    int roll;
    float marks[5];
    float totalMarks;
    float percentage;
    char grade;
} Student;

// Function to calculate total marks, percentage, and grade
void calculateResults(Student* student) {
    student->totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        student->totalMarks += student->marks[i];
    }
    student->percentage = (student->totalMarks / 500) * 100;

    if (student->percentage >= 90) student->grade = 'A';
    else if (student->percentage >= 80) student->grade = 'B';
    else if (student->percentage >= 70) student->grade = 'C';
    else if (student->percentage >= 60) student->grade = 'D';
    else student->grade = 'F';
}

int main() {
    int n, choice, currentSize = 0;
    Student* students;

    // Get the initial size of the student array
    printf("Enter the initial number of students: ");
    scanf("%d", &n);

    // Allocate memory for 'n' students
    students = (Student*)calloc(n, sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Menu-driven program
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentSize == n) {
                    // Resize the array using realloc if full
                    n *= 2;
                    students = (Student*)realloc(students, n * sizeof(Student));
                    if (students == NULL) {
                        printf("Memory reallocation failed.\n");
                        return 1;
                    }
                }

                // Input student data
                printf("Enter name: ");
                scanf("%s", students[currentSize].name);
                printf("Enter roll number: ");
                scanf("%d", &students[currentSize].roll);
                printf("Enter marks for 5 subjects: ");
                for (int i = 0; i < 5; i++) {
                    scanf("%f", &students[currentSize].marks[i]);
                }

                // Calculate results
                calculateResults(&students[currentSize]);

                currentSize++;
                printf("Student added successfully!\n");
                break;

            case 2:
                if (currentSize == 0) {
                    printf("No students to display.\n");
                } else {
                    printf("\nStudent Records:\n");
                    for (int i = 0; i < currentSize; i++) {
                        printf("Name: %s, Roll: %d, Total: %.2f, Percentage: %.2f, Grade: %c\n",
                               students[i].name, students[i].roll, students[i].totalMarks,
                               students[i].percentage, students[i].grade);
                    }
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    // Free allocated memory
    free(students);

    return 0;
}
