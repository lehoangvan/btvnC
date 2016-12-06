#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct result{
  int line;
  char s1[100];
  char s2[100];
} result;

int compare(char *f1, char *f2, result *r){
  FILE *fptr1 = fopen(f1,"r");
  FILE *fptr2 = fopen(f2,"r");
  if (fptr1 == NULL) {
    printf("Cannot open %s.\n", f1);
    return -1;
  }
  else if (fptr2 == NULL) {
    printf("Cannot open %s.\n", f2);
    return -1;
  }
  else {
    char s1[200], *s11;
    char s2[200], *s22;
    int line=1;
    int i=0;
    s11 = fgets(s1,200,fptr1);
    s22 = fgets(s2,200,fptr2);
    while(1) {
      if(strcmp(s1,s2)!=0) {
	r[i].line = line;
	s1[strlen(s1)-1]='\0';
	s2[strlen(s2)-1]='\0';
	strcpy(r[i].s1,s1);
	strcpy(r[i].s2,s2);
	i++;
      }
      if(s11!=NULL) {
	s11 =fgets(s1,200,fptr1);
      } else strcpy(s1,"NULL");
      if(s22!=NULL) {
	s22 = fgets(s2,200,fptr2);
      } else strcpy(s2,"NULL");
      line++;
      if(s11==NULL && s22==NULL) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    return i;
  }
}

void print_result(result *r, int n){
  FILE *fptr = fopen("output.txt","w+");
  fprintf(fptr,"Difference lines: ");
  for(int i=0;i<n;i++){
    fprintf(fptr,"%d ",r[i].line);
  }
  fprintf(fptr,"\n\n Line    %-30s%-30s","File 1","File 2");
  for(int i=0;i<n;i++){
  fprintf(fptr,"\n  %d      %-30s%-30s",r[i].line,r[i].s1,r[i].s2);
  }
  fclose(fptr);
}

int main(int argc, char *argv[]) {
  int n;
  result r[100];
  if(argc == 3) {
    n = compare(argv[1],argv[2],r);
    if(n>0) {
      print_result(r,n);
      printf("Process is completed. Result is writed into file output.txt\n");
    }
    else if(n==0) printf("2 files are equal\n");
  }
  else printf("Nhap sai! Phai truyen vao 3 doi so\n");
  return 0;
}
