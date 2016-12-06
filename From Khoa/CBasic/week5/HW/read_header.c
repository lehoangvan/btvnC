#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct HEADER {
  int filesize;
  char date_create[30];
  char author[30]; 
} HEADER;

int read_header(FILE *fptr){
	HEADER h;
  	int n=0;
  	n = fread(&h,sizeof(HEADER),1,fptr);
  	if(n!=0){
  		printf("File size: %d\n", h.filesize);
  		printf("Date create: %s", h.date_create);
  		printf("Author: %s\n", h.author);
	  	return 1;
	}
  	return 0;
}

int main(int argc, char **argv){
  if(argc == 2) {
    FILE *fpin = fopen(argv[1],"rb");
      if(!read_header(fpin)) printf("File chua co header\n");
    fclose(fpin);
  }
  else printf("Nhap sai! Phai truyen vao 1 tham so\n");
  return 0;
}