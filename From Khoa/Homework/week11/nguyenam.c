#include<stdio.h>

void nguyenam(){
  char c;
  int count=0;
  printf("Nhap chuoi: ");
  do{
    c=getchar();
    if((c=='a')||(c=='i')||(c=='u')||(c=='e')||(c=='y')||(c=='o')) {count++; c=c-32;}
    putchar(c);
  } while(c!='\n');
  printf("Co %d nguyen am trong chuoi!\n",count);
}

int main(){
  nguyenam();
  return 0;
}
