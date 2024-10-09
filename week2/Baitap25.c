
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES_PER_PAGE 5

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("khong the mo tep");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void display_file_paginated(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Kkhong the mo tep");
        exit(1);
    }

    char line[256];
    int line_count = 0;
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        if (++line_count >= LINES_PER_PAGE) {
            printf("-- nhan enter --\n");
            getchar();
            line_count = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("su dung: %s <ten_tap_tin> [-p]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    if (argc == 3 && strcmp(argv[2], "-p") == 0) {
        display_file_paginated(filename);
    } else {
        display_file(filename);
    }

    return 0;
}
