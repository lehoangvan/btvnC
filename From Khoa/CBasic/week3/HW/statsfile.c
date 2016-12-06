#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int character[128];

void count(char* file){
  FILE *fptr = fopen(file,"r");
  if(fptr==NULL) {
    printf("Can't open file %s\n",file);
  }
  else {
    char c;
    do {
      c = fgetc (fptr);
      c=tolower(c);
      character[c]++;
    } while (c != EOF);
  }
  fclose(fptr);
}

void print_result(){
  FILE *fptr = fopen("sourcestats.txt","w");
  for(int i=0;i<128;i++){
    if(character[i]!=0 && i=='\n') fprintf(fptr,"Character \\n appears %d times\n",character[i]);
    else if(character[i]!=0) fprintf(fptr,"Character %c appears %d times\n",i,character[i]);
  }
  fclose(fptr);
}

int main(int argc, char *argv[]) {
  if(argc == 2) {
    count(argv[1]);
    print_result();
    printf("Process is completed. Result is writed into file sourcestats.txt\n");
  }
  else printf("Nhap sai! Phai truyen vao 2 doi so\n");
  return 0;
}
