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

void getSDT(char *line, char *sdt){
  int j=0, i;
  for(i=strlen(line);i>=0;i--) if(line[i]==' ') break;
  i++;
  for(i;i<strlen(line)-1;i++) sdt[j++]=line[i];
  sdt[j]='\0';
}

void getTen(char *line, char *ten){
  int i, j, k, count=0, n=0;
  for(i=0;i<strlen(line);i++){
    if(line[i]==' ') count++;
    if(count==2) break;
  }
  for(j=strlen(line)-1;j>=0;j--) if(line[j]==' ') break;
  for(k=i+1;k<j;k++) ten[n++]=line[k];
  ten[n]='\0';
}

int doc_ds_sv(char *file, SINHVIEN *sv){
  FILE *fptr = fopen(file,"r");
  if(fptr==NULL) {
    printf("Can't open file %s\n",file);
    return -1;
  }
  else {
    char l[100];
    int n=0;
    char *stt, *mssv, ten[100], sdt[15];
    while(fgets(l,100,fptr)!=NULL){
      getSDT(l,sdt);
      getTen(l,ten);
      stt = strtok(l," ");
      mssv = strtok(NULL," ");


      sv[n].stt = atoi(stt);
      strcpy(sv[n].mssv,mssv);
      strcpy(sv[n].ten,ten);
      strcpy(sv[n].sdt,sdt);
      n++;
    }
    fclose(fptr);
    return n;
  }
}

void nhap_diem_sv(SINHVIEN *sv, int n){
  FILE *fptr = fopen("bangdiem.txt","w");
  float d;
  printf("DANH SACH SINH VIEN\n");
  printf("%-5s%-10s%-20s%-15s\n","STT","MSSV","TEN","SDT");
  for(int i=0;i<n;i++){
    printf("%-5d%-10s%-20s%-15s\n",sv[i].stt,sv[i].mssv,sv[i].ten,sv[i].sdt);
  }
  printf("\nNhap diem: \n");
  for(int i=0;i<n;i++){
    printf("Sv thu %d mssv %s: ",sv[i].stt,sv[i].mssv);
    scanf("%f",&sv[i].diem);
  }
  for(int i=0;i<n;i++){
    fprintf(fptr,"%-5d%-10s%-20s%-15s%-4.2f\n",sv[i].stt,sv[i].mssv,sv[i].ten,sv[i].sdt,sv[i].diem);
  }
  fclose(fptr);
}

int main(int argc, char *argv[]) {
  int n;
  SINHVIEN sv[100];
  if(argc == 2) {
    n = doc_ds_sv(argv[1],sv);
    if(n>0) {
      nhap_diem_sv(sv,n);
      printf("Process is completed. Result is writed into file bangdiem.txt\n");
    }
    else if(n==0) printf("Readed 0 student\n");
  }
  else printf("Nhap sai! Phai truyen vao 2 doi so\n");
  return 0;
}
