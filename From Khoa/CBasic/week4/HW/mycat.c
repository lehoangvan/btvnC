#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_LINE 24

int file_page(char *filename){
	FILE *fptr;
	fptr = fopen(filename, "r");
	int n=0;
	char c = fgetc(fptr);
	while(c != EOF){
		if(c=='\n') n++;
		c = fgetc(fptr);
	}
	return n/PAGE_LINE + 1;
}

void mycat(char *filename){
  FILE *fptr;
  if ((fptr = fopen(filename, "r")) == NULL) {
    printf("Cannot open %s.\n", filename);
  }
  else {
    int n=file_page(filename);
    int p=0;
    while(p<n) {
  	char s[100];
  	int i;
	for(i=0;i<PAGE_LINE;i++) {
	  if(fgets(s,100,fptr)==NULL) break;
	  printf("%s", s);
	}
	p++;
	if(p<n) printf("Enter de sang trang\n");
        else printf("\nDa het file, enter de exit\n");
	scanf("%*c");
	
    }
  }
  fclose(fptr);
}

int main(int argc, char **argv) {
  if(argc!=2) printf("Phai truyen vao 1 tham so\n");
  else{
	  char filename[100];
	  int p;
	  strcpy(filename,argv[1]);
	  mycat(filename);
	}
  return 0;
}
