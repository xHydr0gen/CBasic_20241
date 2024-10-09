#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF 1024

void cp_char(FILE *src, FILE *dst) {
    char c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dst);
    }
}

void cp_line(FILE *src, FILE *dst) {
    char buf[BUF];
    while (fgets(buf, BUF, src) != NULL) {
        fputs(buf, dst);
    }
}

void cp_block(FILE *src, FILE *dst, size_t size) {
    char *buf = (char *)malloc(size);
    size_t bytes;
    while ((bytes = fread(buf, 1, size, src)) > 0) {
        fwrite(buf, 1, bytes, dst);
    }
    free(buf);
}

long file_size(FILE *f) {
    fseek(f, 0L, SEEK_END);
    long size = ftell(f);
    rewind(f);
    return size;
}

int main() {
    char src_file[100], dst_file[100];
    int opt;
    size_t block_size;
    FILE *src, *dst;
    clock_t start, end;

    printf("Nhap file nguon: ");
    scanf("%s", src_file);

    src = fopen(src_file, "r");
    if (src == NULL) {
        printf("Khong mo duoc file nguon.\n");
        return 1;
    }



    if (file_size(src) < 640 * 1024) {
        printf("File phai co kich thuoc toi thieu 640KB.\n");
        fclose(src);
        return 1;
    }

    printf("Nhap file dich: ");
    scanf("%s", dst_file);

    do {
        printf("\nMenu:\n");
        printf("1. Sao chep ky tu\n");
        printf("2. Sao chep dong\n");
        printf("3. Sao chep khoi (kich thuoc tuy chon)\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &opt);

        if (opt == 4) {
            printf("Thoat chuong trinh.\n");
            break;
        }

        dst = fopen(dst_file, "w");
        if (dst == NULL) {
            printf("Khong mo duoc file dich.\n");
            fclose(src);
            return 1;
        }
        start = clock();

        switch (opt) {
            case 1:
                cp_char(src, dst);
                break;
            case 2:
                cp_line(src, dst);
                break;
            case 3:
                printf("Nhap kich thuoc khoi: ");
                scanf("%zu", &block_size);
                cp_block(src, dst, block_size);
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }

        // Tính thời gian kết thúc và hiển thị
        end = clock();
        double time_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;
        printf("Thoi gian sao chep: %.2f ms\n", time_ms);

        fclose(dst);

        rewind(src);

    } while (opt != 4);

    fclose(src);

    return 0;
}
