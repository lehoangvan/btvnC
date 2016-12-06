#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fix_file(FILE *fptr1, FILE *fptr2){
  char c;
  while(1){
    c = fgetc(fptr1);
    if (c == EOF)
      return;
    else
      if(c=='\n') fputc('\n', fptr2);
      fputc(c, fptr2);
  }
}

int main(int argc, char *argv[]) {
  if(argc == 3) {
    FILE *fptr1, *fptr2;
    char input[100];
    char output[100];
    strcpy(input,argv[1]);
    strcpy(output,argv[2]);
    fptr1 = fopen(input, "r");
    fptr2 = fopen(output, "w");
    if (fptr1 == NULL)
      printf("Cannot open %s.\n", input);
    else
      fix_file(fptr1,fptr2);
    
    printf("File fixed.\n");
    fclose(fptr1);
    fclose(fptr2);
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
