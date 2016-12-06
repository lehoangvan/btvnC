#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 4

char a[MAX][10] = {"ia","dai","cut","dit"};

//a co phai la chuoi con bat dau tu i cua s ko
int check_include(char *s, char *x, int i){
  int temp=i;
  for(i;i<temp+strlen(x);i++)
    if(x[i-temp]!=s[i]) {
      return 0;
    }
  return 1;
}

void print_replace(char *s, char c){
  
  int count=0, temp;
  for(int i=0;i<strlen(s);i++){
    temp = i;
    for(int j=0;j<MAX;j++){
      char *x = malloc(strlen(a[j]));
      strcpy(x,a[j]);
      //neu ky tu trong s trung voi ky tu dau tien cua x
      if(s[i]== x[0]){
        if(check_include(s,x,i)){
        	for(int k=0;k<strlen(x);k++) printf("%c", c);
          i=i+strlen(x)-1;
          count ++;
          break;
        }
      }
    }
    if(temp == i) printf("%c", s[i]);
  }
  printf("\n");
  if(count==0) printf("Khong ton tai chuoi con a trong s\n");
  
}

int main(int argc, char *argv[]){
  if(argc == 3) {
    FILE *fptr;
    char input[100];
    char c = argv[2][1];
    strcpy(input,argv[1]);
    
    fptr = fopen(input, "r");
    if (fptr == NULL){
      printf("Cannot open %s.\n", input);
    }
    else {
      char s[100];
      printf("%s\n", "Noi dung cua file: ");
      while(fgets(s,100,fptr)!=NULL){
        print_replace(s,c);
      }
      fclose(fptr);
    }
  }
  else printf("Nhap sai! Phai truyen vao 3 tham so\n");
  return 0;
}
