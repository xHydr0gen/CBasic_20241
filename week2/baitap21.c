#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Loi.\n");
        print_usage();
        return 1;
    }


    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        printf("Loi:%s.\n", argv[1]);
        return 1;
    }

    // M? t?p tin ðích ð? ghi
    FILE *dest_file = fopen(argv[2], "w");
    if (dest_file == NULL) {
        printf("Loi:%s.\n", argv[2]);
        fclose(source_file);
        return 1;
    }

  
    char ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    printf("Sao chép thành công tu %s sang %s.\n", argv[1], argv[2]);
    
    return 0;
}
