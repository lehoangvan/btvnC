#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SINHVIEN{
  int stt;
  char mssv[100];
  char ten[100];
  char sdt[15];
  float diem;
} SINHVIEN;

int file_line(char *filename){
  FILE *fptr;
  int n=0;
  char c;
  fptr = fopen(filename, "r");
  if(fptr==NULL) {
    printf("Can't open file %s\n",filename);
    return -1;
  }
  else {
    c = fgetc(fptr);
    while(c != EOF){
      if(c=='\n') n++;
      c = fgetc(fptr);
    }
  }
  return n;
}

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

void getDiem(char *line, char *diem){
  int j=0, i, count=0;
  for(i=strlen(line);i>=0;i--) if(line[i]==' ') break;
  i++;
  for(i;i<strlen(line)-1;i++) diem[j++]=line[i];
  diem[j]='\0';
}

void getSDT(char *line, char *sdt){
  int j=0, i, count=0;
  for(i=strlen(line);i>=0;i--) {
    if(line[i]==' ') count++;
    if(count==2) break;
  }
  i++;
  for(i;i<strlen(line)-1;i++) {
    if(line[i]==' ') break;
    sdt[j++]=line[i];
  }
  sdt[j]='\0';
}

void getTen(char *line, char *ten){
  int i, j, k, count=0, n=0;
  for(i=0;i<strlen(line);i++){
    if(line[i]==' ') count++;
    if(count==2) break;
  }
  count=0;
  for(j=strlen(line)-1;j>=0;j--) {
    if(line[j]==' ') count++;
    if(count==2) break;
  }
  for(k=i+1;k<j;k++) ten[n++]=line[k];
  ten[n]='\0';
}

void doc_ds_sv(char *file, SINHVIEN *sv){
  FILE *fptr = fopen(file,"r");
  char l[100];
  int n = file_line(file);
  int i;
  char *stt, *mssv, ten[100], sdt[15], diem[10];
  
  for(i=0;i<n;i++) {
    fgets(l,100,fptr);
    trim(l);
    getSDT(l,sdt);
    getTen(l,ten);
    getDiem(l,diem);
    stt = strtok(l," ");
    mssv = strtok(NULL," ");
    sv[i].stt = atoi(stt);
    strcpy(sv[i].mssv,mssv);
    strcpy(sv[i].ten,ten);
    strcpy(sv[i].sdt,sdt);
    sv[i].diem = (float)atof(diem);
  }
  fclose(fptr);
}

/*  
  fprintf(fptr,"%-5s%-10s%-20s%-15s%-4s\n","STT","MSSV","TEN","SDT","DIEM");
  for(int i=0;i<n;i++){
    fprintf(fptr,"%-5d%-10s%-20s%-15s%-4.2f\n",sv[i].stt,sv[i].mssv,sv[i].ten,sv[i].sdt,sv[i].diem);
  }

  fclose(fptr);

  printf("\n\n%-5s%-10s%-20s%-15s%-4s\n","STT","MSSV","TEN","SDT","DIEM");
  for(int i=0;i<n;i++){
    printf("%-5d%-10s%-20s%-15s%-4.2f\n",sv[i].stt,sv[i].mssv,sv[i].ten,sv[i].sdt,sv[i].diem);
  }
*/

void write_bin(SINHVIEN *sv, int n){
  FILE *fptr = fopen("grade.dat","wb");
  if(sv == NULL) printf("Error\n");
  else fwrite(sv,sizeof(SINHVIEN),n,fptr);
  fclose(fptr);
}

void read_bin(char *datfile){
  FILE *fptr = fopen("grade.dat","rb");
  SINHVIEN *sv;
  int num=2, n;

  printf("\n\n%-5s%-10s%-20s%-15s%-4s\n","STT","MSSV","TEN","SDT","DIEM");

  while(!feof(fptr)){
    sv = malloc(num*sizeof(SINHVIEN));
    n = fread(sv,sizeof(SINHVIEN),num,fptr);
    for(int i=0;i<n;i++) printf("%-5d%-10s%-20s%-15s%-4.2f\n",sv[i].stt,sv[i].mssv,sv[i].ten,sv[i].sdt,sv[i].diem);
  }  
  
  fclose(fptr);
}

int main(int argc, char *argv[]) {
  int n;
  SINHVIEN *sv;
  if(argc == 2) {
    n = file_line(argv[1]);
    sv = calloc(n,sizeof(SINHVIEN));
    doc_ds_sv(argv[1],sv);
    if(n>0) {
      write_bin(sv,n);
      printf("Process is completed. Result is writed into file grade.dat\n");
      read_bin("grade.dat");
    }
    else if(n==0) printf("Readed 0 student\n");
    free(sv);
  }
  else printf("Nhap sai! Phai truyen vao 2 doi so\n");
  return 0;
}
