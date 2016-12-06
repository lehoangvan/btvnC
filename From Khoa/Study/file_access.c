#include<stdio.h>

int main(){
  FILE *fp;
  char buff[255];
  fp = fopen("vidu.txt","r+");
  fprintf(fp,"Vi du kiem tra fprintf ...\n");
  fputs("Vi du kiem tra fputs...\n",fp);
  fscanf(fp,"%s",buff);
  printf("1. %s\n",buff);
  fgets(buff,255,(FILE*)fp);
  printf("2. %s\n",buff);
  fgets(buff,255,(FILE*)fp);
  printf("3. %s\n",buff);
  fclose(fp);

  
  return 0;
}
