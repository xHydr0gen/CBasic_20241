#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char masv[20], hoten[50];
    float diem;
} SinhVien;

void text_to_dat() {
    FILE *txt = fopen("bangdiem.txt", "r"), *dat = fopen("grade.dat", "wb");
    SinhVien sv;
    while (fscanf(txt, "%s %s %f", sv.masv, sv.hoten, &sv.diem) == 3)
        fwrite(&sv, sizeof(SinhVien), 1, dat);
    fclose(txt); fclose(dat);
}

void display_dat() {
    FILE *dat = fopen("grade.dat", "rb");
    SinhVien sv;
    while (fread(&sv, sizeof(SinhVien), 1, dat))
        printf("Ma SV: %s, Ho ten: %s, Diem: %.2f\n", sv.masv, sv.hoten, sv.diem);
    fclose(dat);
}

void search_update() {
    FILE *dat = fopen("grade.dat", "rb+");
    SinhVien sv; char masv[20]; int found = 0;
    printf("Nhap ma sinh vien: "); scanf("%s", masv);
    while (fread(&sv, sizeof(SinhVien), 1, dat)) {
        if (strcmp(sv.masv, masv) == 0) {
            printf("Ma SV: %s, Ho ten: %s, Diem: %.2f\n", sv.masv, sv.hoten, sv.diem);
            printf("Nhap diem moi: "); scanf("%f", &sv.diem);
            fseek(dat, -sizeof(SinhVien), SEEK_CUR);
            fwrite(&sv, sizeof(SinhVien), 1, dat);
            found = 1; break;
        }
    }
    if (!found) printf("Khong tim thay sinh vien co ma %s.\n", masv);
    fclose(dat);
}

int main() {
    int ch;
    do {
        printf("\n1. TextToDat\n2. Display Dat\n3. Search and Update\n4. Quit\nChon: ");
        scanf("%d", &ch);
        if (ch == 1) text_to_dat();
        else if (ch == 2) display_dat();
        else if (ch == 3) search_update();
    } while (ch != 4);
    return 0;
}
