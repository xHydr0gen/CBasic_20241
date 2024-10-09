#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char *argv[]) {
//	for(int i = argc-1;i>0;i--){
//		printf("%s ",argv[i]);
//		
//	}
	if(argc!=3){
		printf("Loi");
		return 1;
		
		
	}
	if(strcmp(argv[1] ,"uconvert")!=0){
		printf("Loi");
		return 0;
	}
	
	
		
	char *input_file = argv[2];
	

	FILE *t = fopen(input_file,"r+");
	if(t == NULL){
       printf("Loi");
       return 0;


    }
    
    fseek(t,0, SEEK_END);  // di chuyen con tro file toi cuoi de lay kich thuoc
    int file_size = ftell(t);  //lay kich thuoc file  , file_size la so phan tu
    rewind(t);  //quay lai dau file de doc
    
    char *buffer = (char *)malloc(file_size + 1);  //+1 de chua ky tu NULL
    if(buffer == NULL){
    	printf("Loi khong the cap phat");
    	fclose(t);
    	return 1;
	}
    fread(buffer,1, file_size,t);  //doc noi dung file vao bufer  , file_size o day la so phan tu duoc doc
    buffer[file_size] = '\0';  // ket thuc chuoi
    for(int i =0; i<file_size;i++){
    	buffer[i] = toupper(buffer[i]);
    	
    	
	}
    rewind(t);//quay lai dau file de ghi
    fwrite(buffer,1, file_size,t);
    

//	char ch;
//	while((ch = fgetc(t)) != EOF){
//		if(ch<=122&&ch>=97){
//			ch = toupper(ch);
//		}
//		fputc(ch,t);
//		
//	}
	





	fclose(t);
//	fclose(p);

	
    return 0;
}
