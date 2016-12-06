#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//a co phai la chuoi con bat dau tu i cua s ko
int check_include(char *s, char *a, int i){
  int temp=i;
  for(i;i<temp+strlen(a);i++)
    if(a[i-temp]!=s[i]) {
      return 0;
    }
  return 1;
}

void print_replace(char *s, char *a, char *b){
  
  int count=0;
  for(int i=0;i<strlen(s);i++){
    //neu ky tu trong s trung voi ky tu dau tien cua a
    if(s[i]==a[0]){
      if(check_include(s,a,i)){
	for(int j=0;j<strlen(b);j++) printf("%c",b[j]);
	count++;
	i=i+strlen(a)-1;
      }
      else printf("%c",s[i]);
    }
    else printf("%c",s[i]);
  }
  printf("\n");
  if(count==0) printf("Khong ton tai chuoi con a trong s\n");
  
}

int main(int argc, char *argv[]){
  if(argc == 4) {
    char s[100], a[10], b[10];
    strcpy(s,argv[1]);
    strcpy(a,argv[2]);
    strcpy(b,argv[3]);
    printf("--> ");
    print_replace(s,a,b);
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
