#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double copy_by_char(char *filename){
  clock_t begin = clock();
  FILE *fptr = fopen(filename, "r");
  FILE *fptrc = fopen("copy.txt","w");
  char c=fgetc(fptr);
  while(c != EOF){
    fputc(c,fptrc);
    c=fgetc(fptr);
  }
  fclose(fptrc);
  fclose(fptr);
  clock_t end = clock();
  return (double)(end - begin)/CLOCKS_PER_SEC;
}

double copy_by_line(char *filename){
  clock_t begin = clock();
  FILE *fptr = fopen(filename, "r");
  FILE *fptrc = fopen("copy.txt","w");

  char s[100];
  while(fgets(s,100,fptr) != NULL){
    fprintf(fptrc, "%s", s);
  }

  fclose(fptrc);
  fclose(fptr);
  clock_t end = clock();
  return (double)(end - begin)/CLOCKS_PER_SEC;
}

double copy_by_block(char *filename, int n){
  clock_t begin = clock();
  FILE *fptr = fopen(filename, "r");
  FILE *fptrc = fopen("copy.txt","w");
  int num;
  char *buff;
  
  buff = malloc(n+1);
  
  while (!feof(fptr)){
    num = fread(buff, sizeof(char), n, fptr);
    buff[num]= '\0';  
    fwrite(buff, sizeof(char),num, fptrc);
  }
  fclose(fptrc);
  fclose(fptr);
  clock_t end = clock();
  return (double)(end - begin)/CLOCKS_PER_SEC;
}

void menu(){
  printf("\n\nChuong trinh \n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Copy by char\n");
  printf("2. Copy by line\n");
  printf("3. Copy by block\n");
  printf("4. Exit\n");
}

int choose(){
  int n;
  do {
    printf("Nhap lua chon: ");
    if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(int argc, char **argv) {	
  if(argc!=2) printf("Phai truyen vao 1 tham so\n");
  else{
    char filename[100];
    strcpy(filename,argv[1]);
    FILE *fptr;
    if ((fptr = fopen(filename, "r")) == NULL){
    printf("Cannot open %s.\n", filename);
    }
    else {
      int n, c;
      do{
        menu();
        c = choose();
        switch(c){
        case 1:
          printf("Process is completed in %.5lfs.\nResult is writed into file copy.txt\n",copy_by_char(filename));
          break;
        case 2:
          printf("Process is completed in %.5lfs.\nResult is writed into file copy.txt\n",copy_by_line(filename));
          break;
        case 3:          
          printf("Block: "); scanf("%d",&n);
          printf("Process is completed in %.5lfs.\nResult is writed into file copy.txt\n",copy_by_block(filename,n));
          break;
        case 4:
          break;
        default:
          printf("Lua chon sai!\n\n");
          break;
        }
      } while(c!= 4);
    }
  }
  return 0;
}
