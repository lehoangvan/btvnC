#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"
#include "stack_string.h"

int numLen(int n){
  int len = 0;
  while(n!=0){
    n/=10;
    len++;
  }
  return len;
}

char *my_itoa(int num){ 
  int len = numLen(num);
  char *str = malloc(len+1);
  for(int i = len-1;i>=0;i--){
    str[i] = '0' + num%10;
    num/=10;
  }
  str[len]='\0';
  return str;
}

void makeUndoMacro(STACK_STR *stack_undo_macro, int c, int data){
  char *macro = (char*)malloc(30);
  char *i;
  i = my_itoa(data);
  if(c==1){
    strcpy(macro,"PUSH ");
    strcat(macro,i);
    pushStr(stack_undo_macro,macro);
  }
  else if(c==3){
    strcpy(macro,"POP ");
    strcat(macro,i);
    pushStr(stack_undo_macro,macro);
  }
}

void Undo(STACK_STR *stack_undo_macro, STACK_INT *stack_int){
  char *macro, *i, *cmd;
  macro = popStr(stack_undo_macro);

  cmd = strtok(macro," ");
  if(strcmp(cmd,"POP") == 0){
    printf("UNDO POP\n");
    i = strtok(NULL,"\0");
    pushInt(stack_int,atoi(i));
  }
  else {
    printf("UNDO PUSH\n");
    popInt(stack_int);
  }
  printf("Stack so nguyen: ");
  traversingStackInt(stack_int);
}


void menu(){
  printf("\n\nChuong trinh mo phong chuc nang UNDO\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Them 1 so nguyen vao ngan xep\n");
  printf("2. Xem dinh\n");
  printf("3. Lay khoi ngan xep nguyen 1 phan tu\n");
  printf("4. Undo\n");
  printf("5. Thoat\n");
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
  int c, n;
  STACK_STR *stack_undo_macro;
  STACK_INT *stack_int;

  stack_undo_macro = newStackStr();
  stack_int = newStackInt();

  do{
    menu();
    c = choose();
    switch(c){
    case 1:
      printf("Nhap so nguyen: ");
      scanf("%d%*c",&n);
      printf("Push vao stack gia tri %d\n",n);
      pushInt(stack_int,n);
      makeUndoMacro(stack_undo_macro, c,n);
      break;
    case 2:
      printf("Gia tri o dau stack la ");
      printf("%d\n", topInt(stack_int));
      break;
    case 3:
      printf("Pop khoi stack gia tri ");
      n = popInt(stack_int);
      printf("%d\n", n);
      makeUndoMacro(stack_undo_macro, c, n);
      break;
    case 4:
      Undo(stack_undo_macro, stack_int);
      break;
    case 5:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 5);
}
