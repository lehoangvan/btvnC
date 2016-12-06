#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK 10

typedef struct HEADER {
	int filesize;
	char date_create[30];
	char author[30]; 
} HEADER;

void copy_file(FILE *fptr1, FILE *fptr2){
  char *s;
  s = malloc(BLOCK);
  int n;
  while(!feof(fptr1)){
    n = fread(s,sizeof(char),BLOCK,fptr1);
    fwrite(s,sizeof(char),n,fptr2);
  }
}

int copy_header(FILE *fptr1, FILE *fptr2){
  HEADER h;
  int n=0;
  n = fread(&h,sizeof(HEADER),1,fptr1);
  if(n!=0){
  	fwrite(&h,sizeof(HEADER),1,fptr2);  
  	return 1;
  }
  return 0;
}

int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

HEADER create_header(FILE *fpin){
	HEADER h;
	h.filesize = fsize(fpin);

	time_t rawtime; 
    struct tm *timeinfo; 
    time(&rawtime); 
    timeinfo = localtime(&rawtime); 
    strcpy(h.date_create,asctime(timeinfo));

    strcpy(h.author,"Anh Khoa");

    return h;
}

int main(int argc, char **argv){
	if(argc == 2) {
		FILE *fpin = fopen(argv[1],"rb");
		FILE *fbuff = fopen("buffer","wb");

		HEADER h = create_header(fpin);
		fwrite(&h,sizeof(HEADER),1,fbuff);
		copy_file(fpin, fbuff);
		fclose(fbuff);
		fclose(fpin);

		fpin = fopen(argv[1],"w+b");
		fbuff = fopen("buffer","rb");
		copy_header(fbuff,fpin);
		copy_file(fbuff, fpin);
		fclose(fbuff);
		fclose(fpin);
		remove("buffer");
	} 
	else printf("Nhap sai! Phai truyen vao 1 tham so\n");
	return 0;
}