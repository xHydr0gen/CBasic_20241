#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS, FAIL};
struct Student {
    int stt;
    char masv[20];
    char hoten[50];
    char sdt[20];
    float diem;
};
int i,sl;

int main() {

    FILE *input_file = fopen    .txt", "r");
    if (input_file == NULL) {
        printf("Khong the mo file danh_sach_lop.txt\n");
        return 1;
    }
    struct Student students[20];
    while (fscanf(input_file, "%d %s %s %s", &students[i].stt, students[i].masv, students[i].hoten, students[i].sdt)==4)
    {       sl++;i++;

        }

    fclose(input_file);

    for (int i = 0; i < sl; i++) {
        printf("nhap diem %s: ", students[i].hoten);
        scanf("%f", &students[i].diem);
    }

    FILE *output_file = fopen("bangdiem.txt", "w");
    if (output_file == NULL) {
        printf("Khong the mo file bangdiem.txt\n");
        return 1;
    }


    for (int i = 0; i < sl; i++) {
        fprintf(output_file, "%d %s %s %s %.2f\n", students[i].stt, students[i].masv, students[i].hoten, students[i].sdt, students[i].diem);
    }
    fclose(output_file);



    return 0;
}
