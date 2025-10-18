// Name: Yiğit Can Yıldız
// Student ID: 231ADB119
// File: Lab5_task1.c

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    printf("Writing lines to data.txt...\n");
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "Working with files is fun!\n");
    fclose(fp);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("Reading contents:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
