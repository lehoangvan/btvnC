#include<stdio.h>
#include<string.h>

void replace(char s[], char replace_what, char replace_with){
  int i;
  for(i=0;i<strlen(s);i++)
    if(s[i]==replace_what) s[i]=replace_with;
}

int main(){
  char s[50];
  char p, q;
  printf("Nhap chuoi: "); gets(s);
  printf("Thay the : "); scanf("%c%*c",&p);
  printf("boi: "); scanf("%c%*c",&q);
  replace(s,p,q);
  printf("%s\n",s);
  return 0;
}
