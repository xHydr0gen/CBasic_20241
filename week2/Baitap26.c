#include <stdio.h>
#include <stdlib.h>

void append_first_characters(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Khong the mo tep");
        exit(1);
    }

    char line[256];
    char first_characters[81];
    int index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '\n') {
            first_characters[index++] = line[0];
        }
    }
    first_characters[index] = '\0';

    fprintf(file, "\n%s\n", first_characters);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("su dung: %s <ten_tap_tin>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    append_first_characters(filename);

    printf("Done.\n");
    return 0;
}
