#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  char* subStr(char* s1,char *t, int offset, int number){
       strncpy(t, s1 + offset, number);
       t[number] = '\0';
       return t;
  }

int main(){
    
    char t =(char)malloc(1000*sizeof(char));
    char s =(char)malloc(1000*sizeof(char));
    scanf("%[^\n]",s);
    getchar();
    int number; scanf("%d",&number);
    int offset; scanf("%d",&offset);
    
    if(number>(strlen(s)-offset)){
        number=strlen(s)-offset;
    }
    subStr(s,t,offset,number);
    printf("%s",t);
    return 0;
}
