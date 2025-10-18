// Name: Yiğit Can Yıldız
// Student ID: 231ADB119
// File: Lab5_task2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for saving");
        exit(1);
    }
    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);
    fclose(fp);
}

Student load_student(const char *filename) {
    FILE *fp = fopen(filename, "r");
    Student s;
    if (fp == NULL) {
        perror("Error opening file for loading");
        exit(1);
    }
    fscanf(fp, "%s %d %f", s.name, &s.age, &s.gpa);
    fclose(fp);
    return s;
}

int main() {
    Student s1 = {"Alice", 21, 3.75};
    Student s2;

    printf("Saving student to file...\n");
    save_student(s1, "student.txt");

    printf("Loading student from file...\n");
    s2 = load_student("student.txt");

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);
    return 0;
}
