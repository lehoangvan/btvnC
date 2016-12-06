#include<stdio.h>
#include<string.h>

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

void menu(){
  printf("Chuong trinh \n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Trim left \n");
  printf("2.Trim right \n");
  printf("3 Trim middle\n");
  printf("4.Exit \n");
}

int choose(){
  printf("Your choise: ");
  int n;
  scanf("%d",&n);
  return n;
}


int main(){
  char s[20];
  int c;
  printf("Enter string: "); gets(s);

 do{
  menu();
  c = choose();
  switch(c) {
  case 1:
    trimLeft(s);
    printf("Result: %s\n\n\n",s);
    break;
  case 2:
    trimRight(s);
    printf("Result: %s\n\n\n",s);
    break;
  case 3:
    trimMiddle(s);
    printf("Result: %s\n\n\n",s);
    break;
  case 4:
    break;
  default:
    printf("Wrong choise!\n\n\n");
    break;
    }
 } while(c!=4);
}
