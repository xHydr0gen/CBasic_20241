#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int stt;
    char masv[20];
    char hoten[50];
    char sdt[20];
    float diem;
} Student;

int main(int argc, char *argv[]) {
    
    if (argc < 4) {
        printf("HAY GHI DUNG CU PHAP NHE\n");
        return 1;
    }

    int i = 0, sl = 0;
    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Khong the mo file %s\n", input_filename);
        return 1;
    }

    // Cấp phát bộ nhớ ban đầu cho n sinh viên
    int n; scanf("%d",&n);
    Student *a = (Student *)malloc(n * sizeof(Student));
    if (a == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
            printf("Nhap thong tin sinh vien thu %d (STT MaSV HoTen SDT Diem):\n", i+1);
            scanf("%d %s %s %s %f", &a[i].stt, a[i].masv, a[i].hoten, a[i].sdt, &a[i].diem);
    }
    
    fclose(input_file);  

    if (argc - 3 != n) {
        printf("So luong diem khong dung, yeu cau nhap %d diem.\n", sl);
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i].diem = atof(argv[i + 3]);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Khong the mo file %s\n", output_filename);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(output_file, "%d %s %s %s %.2f\n", a[i].stt, a[i].masv, a[i].hoten, a[i].sdt, a[i].diem);
    }

    fclose(output_file);
 
    // NHẬP THÊM
    int them;
    printf("Can nhap them bao nhieu sinh vien: ");
    scanf("%d", &them);

    if (them > 0) {
        a = (Student *)realloc(a, (n + them) * sizeof(Student));
        if (a == NULL) {
            printf("Khong du bo nho khi realloc de them sinh vien.\n");
            return 1;
        }

        for (i = n-1; i < n+them; i++) {
            printf("Nhap thong tin sinh vien thu %d (STT MaSV HoTen SDT Diem):\n", i + 1);
            scanf("%d %s %s %s %f", &a[sl].stt, a[sl].masv, a[sl].hoten, a[sl].sdt, &a[sl].diem);
            sl++;
        }

        output_file = fopen(output_filename, "a");
        if (output_file == NULL) {
            printf("Khong the mo file %s\n", output_filename);
            return 1;
        }

        for (i = n - them; i < sl; i++) {
            fprintf(output_file, "%d %s %s %s %.2f\n", a[i].stt, a[i].masv, a[i].hoten, a[i].sdt, a[i].diem);
        }

        fclose(output_file);
    }

    printf("Da ghi du lieu vao file %s\n", output_filename);

    free(a);

    return 0;
}
