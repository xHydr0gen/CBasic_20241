#include <stdio.h>

int i, j; 

int compare_arrays(int arr1[], int arr2[], int size) {
    for (i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i])
            return 0;  // Không trùng
    }
    return 1;  // Trùng
}

int compare_arrays_unordered(int arr1[], int arr2[], int size) {
    int checked[size];  
    for (i = 0; i < size; ++i) checked[i] = 0;  

    for (i = 0; i < size; ++i) {
        int found = 0;
        for (j = 0; j < size; ++j) {
            if (arr1[i] == arr2[j] && !checked[j]) {
                checked[j] = 1;  
                found = 1;
                break;
            }
        }
        if (!found) return 0;  
    }

    return 1;
}

int compare_arrays_order(int arr1[], int arr2[], int size) {
    int has_same_order = 0; 

    for (i = 0; i < size - 1; ++i) {
        int diffA = arr1[i + 1] - arr1[i];  
        int diffB = arr2[i + 1] - arr2[i];  
        
        if (diffA * diffB > 0) {
            has_same_order = 1;  
        }
    }

    return has_same_order;  
}

int main(void) {
    int SIZE;
    printf("Nhap SIZE: ");
    scanf("%d", &SIZE);  

    int input1[SIZE], input2[SIZE];

    printf("Vui long nhap danh sach %d so nguyen cho mang thu nhat:\n", SIZE);
    for (i = 0; i < SIZE; ++i) {
        scanf("%d", &input1[i]);
    }

    printf("Vui long nhap danh sach %d so nguyen cho mang thu hai:\n", SIZE);
    for (i = 0; i < SIZE; ++i) {
        scanf("%d", &input2[i]);
    }

    if (compare_arrays(input1, input2, SIZE) == 1)
        printf("Ca hai mang giong nhau o cac vi tri tuong ung!\n");
    else
        printf("Hai mang khong giong nhau o cac vi tri tuong ung.\n");

    if (compare_arrays_unordered(input1, input2, SIZE) == 1)
        printf("Ca hai mang chua cac phan tu giong nhau (khong quan tam vi tri)!\n");
    else
        printf("Hai mang khong chua cac phan tu giong nhau (khong quan tam vi tri).\n");

    if (compare_arrays_order(input1, input2, SIZE) == 1)
        printf("Ca hai mang co thu tu phan tu lien tiep giong nhau!\n");
    else
        printf("Hai mang khong co thu tu phan tu lien tiep giong nhau.\n");

    return 0;
}

