#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 100

// Structure to represent a course
typedef struct {
    int course_id;
    float gpa;
    int credit_hours;
    int semester_number;
} Course;

// Function prototypes
float calculateSGPA(Course courses[], int courseCount, int semester);
float calculateCGPA(Course courses[], int courseCount);

int main() {
    Course courses[MAX_COURSES];
    int courseCount = 0;
    int semesterCount = 0;

    // Input courses
    printf("Enter the number of courses: ");
    scanf("%d", &courseCount);

    printf("Enter the course details (course_id gpa credit_hours semester_number):\n");
    for (int i = 0; i < courseCount; i++) {
        scanf("%d %f %d %d", &courses[i].course_id, &courses[i].gpa, &courses[i].credit_hours, &courses[i].semester_number);
        if (courses[i].semester_number > semesterCount) {
            semesterCount = courses[i].semester_number;
        }
    }

    // Calculate SGPA for each semester
    for (int sem = 1; sem <= semesterCount; sem++) {
        float sgpa = calculateSGPA(courses, courseCount, sem);
        printf("Semester %d : %.2f\n", sem, sgpa);
    }

    // Calculate CGPA
    float cgpa = calculateCGPA(courses, courseCount);
    printf("CGPA : %.2f\n", cgpa);

    return 0;
}

// Function to calculate SGPA for a specific semester
float calculateSGPA(Course courses[], int courseCount, int semester) {
    float totalGradePoints = 0;
    int totalCreditHours = 0;

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].semester_number == semester) {
            totalGradePoints += courses[i].gpa * courses[i].credit_hours;
            totalCreditHours += courses[i].credit_hours;
        }
    }

    if (totalCreditHours == 0) return 0.0; // Avoid division by zero
    return totalGradePoints / totalCreditHours;
}

// Function to calculate CGPA for all courses
float calculateCGPA(Course courses[], int courseCount) {
    float totalGradePoints = 0;
    int totalCreditHours = 0;
    int uniqueCourseIds[MAX_COURSES];
    int uniqueCount = 0;

    for (int i = 0; i < courseCount; i++) {
        // Check if the course_id is already processed
        int isDuplicate = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (courses[i].course_id == uniqueCourseIds[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If it's not a duplicate, process it
        if (!isDuplicate) {
            uniqueCourseIds[uniqueCount++] = courses[i].course_id;
            totalGradePoints += courses[i].gpa * courses[i].credit_hours;
            totalCreditHours += courses[i].credit_hours;
        }
    }

    if (totalCreditHours == 0) return 0.0; // Avoid division by zero
    return totalGradePoints / totalCreditHours;
}
