#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *input,  int d){
  FILE *fptr;

  fptr = fopen(input, "r+");

  if (fptr == NULL) {
    printf("Cannot open %s.\n", input);
    return;
  }
  else {
    char c;
    while(1) {
      c= fgetc(fptr);
      if(c==EOF) break;
      fseek(fptr,-1,SEEK_CUR);
      if(c>='a' && c<='z') {
	if(c+d>='a' && c+d<='z') fputc(c+d,fptr);
	else fputc(c+d-26,fptr);
      }
      else if(c>='A' && c<='Z') {
	if(c+d>='A' && c+d<='Z') fputc(c+d,fptr);
	else fputc(c+d-26,fptr);
      }
      else fputc(c+d,fptr);
    }
    fclose(fptr);
  }
  printf("File %s has been encrypted!\n",input);
}



int main(int argc, char *argv[]){
  if(argc == 3) {
    char input[100];
    strcpy(input,argv[1]);
    int d = atoi(argv[2]);
    encrypt(input,d);
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
