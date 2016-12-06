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

void print_replace(char *s, char *a, char *b, FILE *ptr2){
  
  int count=0;
  for(int i=0;i<strlen(s);i++){
    //neu ky tu trong s trung voi ky tu dau tien cua a
    if(s[i]==a[0]){
      if(check_include(s,a,i)){
	for(int j=0;j<strlen(b);j++) fputc(b[j],ptr2);
	count++;
	i=i+strlen(a)-1;
      }
      else fputc(s[i],ptr2);
    }
    else fputc(s[i],ptr2);
  }
  printf("\n");
  if(count==0) printf("Khong ton tai chuoi con a trong s\n");
  
}

int main(int argc, char *argv[]){
  if(argc == 3) {
    FILE *fptr1, *fptr2;
    char input[100];
    char output[100];
    strcpy(input,argv[1]);
    strcpy(output,argv[2]);
    
    fptr1 = fopen(input, "r");
    fptr2 = fopen(output, "w");
    if (fptr1 == NULL){
      printf("Cannot open %s.\n", input);
    }
    else if (fptr2 == NULL){
      printf("Cannot open %s.\n", output);
    }
    else {
      char s[100], a[10], b[10];
      fscanf(fptr1,"%s %s %s",s,a,b);
      print_replace(s,a,b,fptr2);
      printf("Process is completed. Ready to close the files.\n");
      fclose(fptr1);
      fclose(fptr2);
    }
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
