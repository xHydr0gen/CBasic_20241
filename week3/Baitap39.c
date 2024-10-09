#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filesplit(char *sourceFile, int N, char *outputFile1, char *outputFile2)
{
    FILE *source = fopen(sourceFile, "r");
    FILE *out1 = fopen(outputFile1, "w");
    FILE *out2 = fopen(outputFile2, "w");

    if (source == NULL || out1 == NULL || out2 == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }

    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), source))
    {
        if (count < N)
        {
            fputs(buffer, out1);
        }
        else
        {
            fputs(buffer, out2);
        }
        count++;
    }

    fclose(source);
    fclose(out1);
    fclose(out2);
    printf("File split successfully.\n");
}

void filemerge(char *inputFile1, char *inputFile2, char *outputFile)
{
    FILE *in1 = fopen(inputFile1, "r");
    FILE *in2 = fopen(inputFile2, "r");
    FILE *out = fopen(outputFile, "w");

    if (in1 == NULL || in2 == NULL || out == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), in1))
    {
        fputs(buffer, out);
    }

    while (fgets(buffer, sizeof(buffer), in2))
    {
        fputs(buffer, out);
    }

    fclose(in1);
    fclose(in2);
    fclose(out);
    printf("Files merged successfully.\n");
}

void fileread(char *inputFile)
{
    FILE *file = fopen(inputFile, "r");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }

    fclose(file);
}

int main()
{
    char sourceFile[] = "phone.dat";
    char file1[] = "phone1.dat";
    char file2[] = "phone2.dat";
    char mergedFile[] = "phonebook_merged.dat";

    int N = 10;

    filesplit(sourceFile, N, file1, file2);

    filemerge(file1, file2, mergedFile);

    printf("Content of merged file:\n");
    fileread(mergedFile);

    return 0;
}