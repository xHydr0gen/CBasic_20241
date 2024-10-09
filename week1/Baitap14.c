// Author: Nguyen Minh Loc
#include <stdio.h>
#include <string.h>

char str[1001];
char del[] = ".?!,\n\t ";

int main () {
    // Doc xau input
    fgets(str, sizeof(str), stdin);
    
    // Thay the ky tu xuong dong -> ket thuc xau
    str[strcspn(str, "\n")] = '\0';
    
    // strtok() de tach xau input thanh cac tu dua theo cac ky tu trong mang del
    char *token = strtok(str, del);
    
    // In cac tu ra man hinh
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, del);
    }
    return 0;
}