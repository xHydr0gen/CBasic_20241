#include <stdio.h>
#include <string.h>

char* layTen(char* hoten) {
    char *token = strtok(hoten, " ");
    char *tenCuoi = token;

    while (token != NULL) {
        tenCuoi = token;  
        token = strtok(NULL, " ");
    }
    return tenCuoi;
}

void swap(char arr[][100], int i, int j) {
    char temp[100];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

int main() {
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    char sinhvien[n][100];
    char copySinhvien[n][100];

    for (int i = 0; i < n; i++) {
        printf("Nhap ten day du cua  sinh vien %d: ", i + 1);
        fgets(sinhvien[i], sizeof(sinhvien[i]), stdin);
        sinhvien[i][strcspn(sinhvien[i], "\n")] = '\0'; 
        strcpy(copySinhvien[i], sinhvien[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            char temp1[100], temp2[100];
            strcpy(temp1, sinhvien[i]);
            strcpy(temp2, sinhvien[j]);

            if (strcmp(layTen(temp1), layTen(temp2)) > 0) {
                swap(sinhvien, i, j);
            }
        }
    }

    printf("\nDanh sach cac sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", sinhvien[i]);
    }

    // Ð?m s? lu?ng l?n nh?t các sinh viên có cùng tên
    int maxCount = 1;
    int count = 1;

    for (int i = 1; i < n; i++) {
        char temp1[100], temp2[100];
        strcpy(temp1, sinhvien[i - 1]);
        strcpy(temp2, sinhvien[i]);

        if (strcmp(layTen(temp1), layTen(temp2)) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
            }
            count = 1;
        }
    }
    if (count > maxCount) {
        maxCount = count;
    }

    printf("\nSo luong lon nhat cac sinh vien cung ten la: %d\n", maxCount);

    return 0;
}

