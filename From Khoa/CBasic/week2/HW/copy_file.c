#include <stdio.h>

int main(void) {
  FILE *fptr1, *fptr2;
  char filename[]= "haiku.txt";
  char file_copy[]="haiku_copy.txt";
  char c;
  fptr1 = fopen(filename, "r");
  fptr2 = fopen(file_copy, "w");
  if (fptr1 == NULL){
    printf("Cannot open %s.\n", filename);
  }
  else if (fptr2 == NULL){
    printf("Cannot open %s.\n", file_copy);
  }
  else {
    c= fgetc(fptr1);
    while(c!=EOF) {
      fputc(c,fptr2);
      c= fgetc(fptr1);
      
    } 
    printf("File copied. Ready to close the files.\n");
    fclose(fptr1);
    fclose(fptr2);
  }
}
