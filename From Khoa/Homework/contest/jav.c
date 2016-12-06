#include<stdio.h>
#include<string.h>

typedef struct{
  char maso[9];
  char tieude[50];
  int thoiluong;
  int giathue;
} dia_t;

int checkmaso(char maso[]){ //chi bat duoc 1 loi
  int i;
  if(strlen(maso)!=8) return 0;
  else {
    if((maso[0]!='0')&&(maso[0]!='1')) return -1;
    for(i=1;i<4;i++) if((maso[i]<'A')||(maso[i]>'Z')) return -2;
    for(i=4;i<8;i++) if((maso[i]<'0')||(maso[i]>'9')) return -3;
  }
  return 1;
}

int giaThue(char ms[]){
  if(ms[0]=='0') return 5000;
  else return 2000;
}


int nhap(dia_t dia[], int n){
  char ms[100];
  int i;
  for(i=0;i<n;i++){
    printf("Dia %d\n",i+1);
    do{
      printf("Nhap ma so dia: "); gets(ms);
      if(checkmaso(ms)==0) printf("Ma so co do dai 8 ky tu!\n\n");
      if(checkmaso(ms)==-1) printf("Ky tu dau cua ma so la 0 hoac 1!\n\n");
      if(checkmaso(ms)==-2) printf("3 ky tu 2-4 la chu hoa!\n\n");
      if(checkmaso(ms)==-3) printf("4 ky tu cuoi la chu so!\n\n");
    } while(checkmaso(ms)!=1);
    strncpy(dia[i].maso,ms,9);
    printf("Nhap tieu de: "); gets(dia[i].tieude);
    do{
      printf("Nhap thoi luong (60-180): "); scanf("%d%*c",&dia[i].thoiluong);
    } while((dia[i].thoiluong<60)||(dia[i].thoiluong>180));
    dia[i].giathue=giaThue(dia[i].maso);
  }			 
}

int xuat(dia_t dia[], int n){
  int i;
  printf("%-10s%-50s%-14s%-5s\n\n","Ma so","Tieu de","Thoi luong","Gia thue");
  for(i=0;i<n;i++){
    printf("%-10s%-50s%-14d%-5d\n",dia[i].maso,dia[i].tieude,dia[i].thoiluong,dia[i].giathue);
  }
  printf("\n");
}

void sort(dia_t dia[], int n){
  int i,j;
  dia_t temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(dia[i].thoiluong>dia[j].thoiluong){
	temp=dia[j];
	dia[j]=dia[i];
	dia[i]=temp;
      }
    }
}

int duyetms(dia_t dia[],int n,char ms[]){
  int i;
  for(i=0;i<n;i++) if(strcmp(dia[i].maso,ms)==0) return i;
  return 0;
}

void suatt(dia_t dia[],int n){
  int i;
  char ms[100], maso[9];
  while(1){
  do{
     printf("Nhap ma so dia can sua thong tin: "); gets(ms);
     if(checkmaso(ms)==0) printf("Ma so co do dai 8 ky tu!\n\n");
     if(checkmaso(ms)==-1) printf("Ky tu dau cua ma so la 0 hoac 1!\n\n");
     if(checkmaso(ms)==-2) printf("3 ky tu 2-4 la chu hoa!\n\n");
     if(checkmaso(ms)==-3) printf("4 ky tu cuoi la chu so!\n\n");
  } while(checkmaso(ms)!=1);
    strncpy(maso,ms,9);
    i=duyetms(dia,n,maso);
    if(i==0) printf("Khong ton tai bo phim nay\n");
    else break;
  }
  
    printf("Nhap tieu de: "); gets(dia[i].tieude);
    do{
      printf("Nhap thoi luong (60-180): "); scanf("%d%*c",&dia[i].thoiluong);
    } while((dia[i].thoiluong<60)||(dia[i].thoiluong>180));
    dia[i].giathue=giaThue(dia[i].maso);
}

void catten(char ten[], char t[]){
  int i,j=0;
  for(i=strlen(ten)-1;i>=0;i--)
    if(ten[i]==' ') break;
  for(i;i<strlen(ten);i++) t[j++]=ten[i];
}

void sorttheoten(dia_t dia[], int n){
  char t[100][100];
  int i,j;
  for(i=0;i<n;i++){
    catten(dia[i].tieude,t[i]);
  }
  dia_t temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(strcmp(t[i],t[j])>0){
	temp=dia[j];
	dia[j]=dia[i];
	dia[i]=temp;
      }
    }
}

void menu(){
  printf("Chuong trinh quan ly dia jav\n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Nhap so lieu \n");
  printf("2.Danh sach dia \n");
  printf("3.Sap xep theo thoi luong \n");
  printf("4.Sua doi thong tin dia \n");
  printf("5.Sap xep theo tieu de \n");
  printf("6.Thoat\n");
}

int choose(){
  printf("Nhap lua chon: ");
  int n;
  scanf("%d%*c",&n);
  return n;
}

int main(){
  int c,n;
  dia_t dia[100];
  do{
    menu();
    c = choose();
  
    switch(c){
    case 1:
      printf("Nhap so dia trong cua hang: "); scanf("%d%*c",&n);
      nhap(dia,n);
      break;
    case 2:
      xuat(dia,n);
      break;
    case 3:
      sort(dia,n);
      xuat(dia,n);
      break;
    case 4:
      suatt(dia,n);
      xuat(dia,n);
      break;
    case 5:
      sorttheoten(dia,n);
      xuat(dia,n);
      break;
    case 6:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!=6);
  return 0;
}
