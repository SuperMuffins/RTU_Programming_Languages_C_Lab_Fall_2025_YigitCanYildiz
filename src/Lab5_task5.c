// Name: Yiğit Can Yıldız
// Student ID: 231ADB119
// File: Lab5_task5.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

float calculate_average_gpa(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    int id;
    char name[50];
    float gpa, sum = 0.0;
    int count = 0;

    while (fscanf(fp, "%d %s %f", &id, name, &gpa) == 3) {
        sum += gpa;
        count++;
    }

    fclose(fp);
    if (count == 0) return 0.0;
    return sum / count;
}

void save_average(float avg, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(fp, "Average GPA of all students: %.2f\n", avg);
    fclose(fp);
    printf("Average GPA saved to %s\n", filename);
}

int main() {
    float avg = calculate_average_gpa("students.txt");

    if (avg < 0) {
        printf("Could not read students file.\n");
        return 1;
    }

    printf("Average GPA: %.2f\n", avg);
    save_average(avg, "average_gpa.txt");
    return 0;
}
