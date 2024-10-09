#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define STR 50

typedef struct {
    char m[STR];
    int mem;
    float s, p;
} P;

P db[MAX];
int cnt = 0;

void impTxt(char *fn) {
    FILE *f = fopen(fn, "r");
    if (!f) return;
    cnt = 0;
    while (fscanf(f, "%s %d %f %f", db[cnt].m, &db[cnt].mem, &db[cnt].s, &db[cnt].p) != EOF) cnt++;
    fclose(f);
    FILE *out = fopen("db.dat", "wb");
    if (out) {
        fwrite(db, sizeof(P), cnt, out);
        fclose(out);
    }
}

void impBin(char *fn, int mode, int st) {
    FILE *f = fopen(fn, "rb");
    if (!f) return;
    if (mode == 1) cnt = fread(db, sizeof(P), MAX, f);
    else {
        fseek(f, sizeof(P) * st, SEEK_SET);
        cnt = fread(db, sizeof(P), MAX - st, f);
    }
    fclose(f);
}

void prtAll() {
    for (int i = 0; i < cnt; i++)
        printf("%s %dGB %.2f\" %.2f$\n", db[i].m, db[i].mem, db[i].s, db[i].p);
}

void findM(char *model) {
    for (int i = 0; i < cnt; i++) {
        if (!strcmp(db[i].m, model)) {
            printf("%s %dGB %.2f\" %.2f$\n", db[i].m, db[i].mem, db[i].s, db[i].p);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    int ch, mode, st;
    char fn[STR], mdl[STR];

    while (1) {
        printf("\n1. Txt\n2. Binary\n3. Prt\n4. Find\n5. Exit\nCh: ");
        scanf("%d", &ch);
        if (ch == 5) break;
        switch (ch) {
            case 1:
                printf("File: ");
                scanf("%s", fn);
                impTxt(fn);
                break;
            case 2:
                printf("File: ");
                scanf("%s", fn);
                printf("Mode (1:All, 2:Part): ");
                scanf("%d", &mode);
                if (mode == 2) {
                    printf("Start: ");
                    scanf("%d", &st);
                }
                impBin(fn, mode, st);
                break;
            case 3:
                prtAll();
                break;
            case 4:
                printf("Model: ");
                scanf("%s", mdl);
                findM(mdl);
                break;
        }
    }
    return 0;
}
