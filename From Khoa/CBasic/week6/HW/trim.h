#include <string.h>

void trimLeft(char s[]){
  int i=0, j;
  while(s[0]==' '){
    for(j=0;j<strlen(s)-1;j++){
      s[j]=s[j+1];
    }
    s[strlen(s)-1]='\0';
  }
}

void trimRight(char s[]){
  int i=strlen(s)-1;
  while(s[i]==' '){
    s[i--]='\0';
  }
}

void trimMiddle(char s[]){
  int i=0,j;
  while(s[i]==' ') i++;
  for(i;i<strlen(s);i++){
    if((s[i]==' ')&&(s[i+1]==' ')){
  for(j=i;j<strlen(s)-1;j++){
    s[j]=s[j+1];
  }
  s[strlen(s)-1]='\0';
  i--;
      }
  }
}

void trim(char s[]){
  trimLeft(s);
  trimRight(s);
  trimMiddle(s);
}