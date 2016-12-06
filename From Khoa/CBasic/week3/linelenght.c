#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line_char_num(FILE *fptr1, FILE *fptr2){
  char s[200];
  while(fgets(s,200,fptr1)!=NULL){
      fprintf(fptr2,"%d %s",(int)strlen(s),s);
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
    if (fptr1 == NULL) {
      printf("Cannot open %s.\n", input);
      return 0;
    }
    else
      line_char_num(fptr1,fptr2);
    
    printf("Process is completed.\n");
    fclose(fptr1);
    fclose(fptr2);
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
