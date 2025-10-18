// Name: Yiğit Can Yıldız
// Student ID: 231ADB119
// File: Lab5_task4.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void save_binary(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for binary write");
        exit(1);
    }
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Saving student in binary format...\n");
}

Student load_binary(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file for binary read");
        exit(1);
    }
    fread(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Loading student from binary file...\n");
    return s;
}

int main() {
    Student s1 = {"Alice", 21, 3.75};
    Student s2;

    save_binary(s1, "student_bin.dat");
    s2 = load_binary("student_bin.dat");

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    FILE *fp = fopen("student_bin.dat", "rb");
    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        long size = ftell(fp);
        printf("Binary file size: %ld bytes\n", size);
        fclose(fp);
    }

    return 0;
}
