#include<stdio.h>
#include<string.h>

void firstname(char name[]){
  int i=0;
  while(name[i]!=' ') i++;
  name[i]='\0';
}

int main(){
  char name[20];
  printf("Enter your name: ");
  gets(name);
  firstname(name);
  printf("Hello %s\n",name);
  return 0;  
}
