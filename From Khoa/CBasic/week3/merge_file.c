#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(FILE *fptr1, FILE *fptr2, FILE *fptr3){
  char s1[200], *s11;
  char s2[200], *s22;
  s11 = fgets(s1,200,fptr1);
  s22 = fgets(s2,200,fptr2);
  while(1) {
    if(s11!=NULL) {
      fprintf(fptr3,"%s",s1);
      s11 =fgets(s1,200,fptr1);
    }
    if(s22!=NULL) {
      fprintf(fptr3,"%s",s2);
      s22 = fgets(s2,200,fptr2);
    }
    if(s11==NULL && s22==NULL) break;
  }
}

int main(int argc, char *argv[]) {
  if(argc == 4) {
    FILE *fptr1, *fptr2, *fptr3;
    char input1[100];
    char input2[100];
    char output[100];
    strcpy(input1,argv[1]);
    strcpy(input2,argv[2]);
    strcpy(output,argv[3]);
    fptr1 = fopen(input1, "r");
    fptr2 = fopen(input2, "r");
    fptr3 = fopen(output, "w");
    if (fptr1 == NULL) {
      printf("Cannot open %s.\n", input1);
      return 0;
    }
    else if (fptr2 == NULL) {
      printf("Cannot open %s.\n", input2);
      return 0;
    }
    else
      merge(fptr1,fptr2,fptr3);
    
    printf("Process is completed.\n");
    fclose(fptr1);
    fclose(fptr2);
  }
  else printf("Nhap sai! Phai truyen vao 4 doi so\n");
  return 0;
}
