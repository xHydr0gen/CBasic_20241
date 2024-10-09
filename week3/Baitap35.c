#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

int main() {
    Contact phonebook[MAX];
    int n, i;
    FILE *file;

    printf("Nhap so luong lien he (toi da %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("So luong vuot qua gioi han %d\n", MAX);
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Nhap thong tin cho lien he thu %d:\n", i + 1);
        printf("Ten: ");
        scanf(" %[^\n]", phonebook[i].name);  
        printf("So dien thoai: ");
        scanf("%s", phonebook[i].phone);
        printf("Email: ");
        scanf("%s", phonebook[i].email);
    }

    file = fopen("phonebook.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return 1;
    }
    fwrite(phonebook, sizeof(Contact), n, file);
    fclose(file);

    Contact read_contacts[MAX];
    file = fopen("phonebook.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return 1;
    }
    fread(read_contacts, sizeof(Contact), n, file);
    fclose(file);

    printf("\nDanh sach lien he doc tu file:\n");
    for (i = 0; i < n; i++) {
        printf("Lien he %d:\n", i + 1);
        printf("Ten: %s\n", read_contacts[i].name);
        printf("So dien thoai: %s\n", read_contacts[i].phone);
        printf("Email: %s\n", read_contacts[i].email);
        printf("\n");
    }

    return 0;
}
