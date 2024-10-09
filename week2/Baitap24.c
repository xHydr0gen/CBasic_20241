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
	if(argc!=4){
		printf("Loi");
		return 1;
		
		
	}
//	if(strcmp(argv[1] ,"uconvert")!=0){
//		printf("Loi");
//		return 0;
//	}
	
	
		
	char *input_file = argv[1];
	int q = atoi(argv[2]); //chuyen xau thanh so
	char *output_file = argv[3];

	FILE *t = fopen(input_file,"r");
	if(t == NULL){
       printf("Loi");
       return 0;


    }
    FILE *p = fopen(output_file,"w");
    if(p == NULL){
    	printf("Loi");
    	return 0;
	}
	char ch;
	while((ch=fgetc(t))!=EOF){
		if(ch>=65&&ch<=90){
			if(ch+q>90){
				ch= ch+q-26;
			}
			else if(ch+q<65){
				ch=ch+q+26;
			}
			else ch = ch+q;
		}
		fputc(ch,p);
		
	}
	fclose(t);
	fclose(p);

    return 0;
}






