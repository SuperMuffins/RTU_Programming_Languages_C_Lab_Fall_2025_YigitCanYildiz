// Name: Yiğit Can Yıldız
// Student ID: 231ADB119
// File: Lab5_task3.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;
const char *filename = "students.txt";

void load_students() {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("No existing file found. Starting fresh.\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &students[student_count].id,
                  students[student_count].name,
                  &students[student_count].gpa) == 3) {
        student_count++;
    }
    fclose(fp);
}

void save_students() {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error saving students");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    fclose(fp);
    printf("Data saved successfully.\n");
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list full!\n");
        return;
    }

    Student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    students[student_count++] = s;
    printf("Student added successfully!\n");
}

void list_students() {
    if (student_count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d. ID: %d | Name: %s | GPA: %.2f\n",
               i + 1, students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    int choice;

    load_students();

    while (1) {
        printf("\n==== Student Management System ====\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_students();
                break;
            case 2:
                add_student();
                break;
            case 3:
                save_students();
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
