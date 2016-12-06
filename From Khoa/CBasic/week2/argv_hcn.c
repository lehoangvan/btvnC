#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_reverse(char *s){
  for(int i=strlen(s)-1;i>=0;i--){
    printf("%c",s[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]){
  if(argc == 2) {
    printf("Chuoi dao nguoc: ");
    print_reverse(argv[1]);
  }
  else printf("Nhap sai! Phai truyen vao 1 doi so\n");
  return 0;
}
