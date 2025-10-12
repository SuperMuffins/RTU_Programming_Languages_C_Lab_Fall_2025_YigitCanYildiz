#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    int n, i;
    struct Student *students;

    printf("Enter number of students: ");
    scanf("%d", &n);

    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for student %d (Name ID Grade): ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
    }

    printf("\n%-6s %-10s %-6s\n", "ID", "Name", "Grade");
    for (i = 0; i < n; i++) {
        printf("%-6d %-10s %.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    free(students);
    return 0;
}
