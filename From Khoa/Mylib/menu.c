#include<stdio.h>


void menu(){
  printf("\n\nChuong trinh \n");
  printf("Author: Anh Khoa\n\n");
  printf("1. \n");
  printf("2. \n");
  printf("3. \n");
  printf("4. \n");
}

int choose(){
  int n;
  do {
    printf("Nhap lua chon: ");
    if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(){
  int c;
  
  do{
    menu();
    c = choose();
    switch(c){
    case 1:
    
      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 4);
}
