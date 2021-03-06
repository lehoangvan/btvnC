#include<stdio.h>
#include<string.h>

int sosv=0;

typedef struct{
  char MSSV[6];
  char ten[30];
  float hd;
  float PB;
  float HD[3];
  float giuaky;
  float cuoiky;
} sinhvien;

float lamtron(float n){
  int i;
  n*=100;
  i=(int)n%10;
  n=n-i;
  if(i<5) i=0;
  else i=10;
  return (n+i)/100;
}

int sodiem(){
  int n;
  do {
    printf(" -> Diem: ");
    if(scanf("%d",&n)==0) n=-1;
  } while((getchar()!='\n')||(n<0)||(n>10));
  return n;
}

int testmssv(sinhvien sv[], char mssv[]){
  int i;
  if(strlen(mssv)>5) return -1;
  for(i=0;i<sosv;i++){
    if(strcmp(sv[i].MSSV,mssv)==0) return 0;
  }
  return 1;
}

int testten(sinhvien sv[], char ten[]){
  int i;
  if(strlen(ten)>30) return -1;
  for(i=0;i<strlen(ten);i++){
    if(ten[i]==' ') return 1;
  }
  return 0;
}

void tinhdiem(sinhvien sv[]){
  int i;
  for(i=0;i<sosv;i++){
    if((sv[i].hd>5.5)&&(sv[i].PB>5.5))
    sv[i].giuaky=lamtron((sv[i].hd+sv[i].PB)/2);
    else sv[i].giuaky=0;
    if((sv[i].HD[0]>5.5)&&(sv[i].HD[1]>5.5)&&(sv[i].HD[2]>5.5))
    sv[i].cuoiky=lamtron((sv[i].HD[0]+sv[i].HD[1]+sv[i].HD[2])/3);
    else sv[i].cuoiky=0;
  }
}

void in(sinhvien sv[]){
  int i;
  printf("%-6s%-30s%-5s%-5s%-6s%-6s%-6s%-9s%-9s\n","MSSV","Ho ten","HD","PB","HD1","HD2","HD3","Giua ky","Cuoi ky");
  for(i=0;i<sosv;i++){
    printf("%-6s%-30s%-5.1f%-5.1f%-6.1f%-6.1f%-6.1f%-9.1f%-9.1f\n",sv[i].MSSV,sv[i].ten,sv[i].hd,sv[i].PB,sv[i].HD[0],sv[i].HD[1],sv[i].HD[2],sv[i].giuaky,sv[i].cuoiky);
  }
}
  
void bosungsv(sinhvien sv[],int n){
  int i;
  if((sosv+n)<=20){
    for(i=0;i<n;i++){
      printf("\n\nNhap thong tin sv thu %d\n",i+1);
      
      while(1){
	printf("MSSV: "); gets(sv[i].MSSV);
	if(testmssv(sv,sv[i].MSSV)==-1) {
	  printf("Ma so khong qua 5 ky tu\n");
	  continue;
	}
	if(testmssv(sv,sv[i].MSSV)==0) {
	  printf("Ma so da ton tai\n");
	  continue;
	}
	break;
      }
      
      while(1){
	printf("Ten: "); gets(sv[i].ten);
	if(testten(sv,sv[i].ten)==-1) {
	  printf("Ten khong qua 30 ky tu\n");
	  continue;
	}
	if(testten(sv,sv[i].ten)==0) {
	  printf("Ten phai co khoang trang\n");
	  continue;
	}
	break;
      }
      
      printf("Huong dan \n"); sv[i].hd = sodiem();
      printf("Phan bien \n"); sv[i].PB = sodiem();
      printf("Hoi dong 1 \n"); sv[i].HD[0] = sodiem();
      printf("Hoi dong 2 \n"); sv[i].HD[1] = sodiem();
      printf("Hoi dong 3 \n"); sv[i].HD[2] = sodiem();

      sosv++;
    }
    tinhdiem(sv);
    in(sv);
  }
  else printf("Khong the thuc hien vi so sinh vien toi da la 20!\n\n");

  
}

void dsbvthanhcong(sinhvien sv[]){
  int i;
  printf("Danh sach sinh vien bao ve thanh cong\n");
  for(i=0;i<sosv;i++){
    if((sv[i].giuaky*0.3+sv[i].cuoiky*0.7)>8)
    printf("%-5s%-30s%-3.1f%-3.1f%-4.1f%-4.1f%-4.1f%-8.1f%-8.1f\n",sv[i].MSSV,sv[i].ten,sv[i].hd,sv[i].PB,sv[i].HD[0],sv[i].HD[1],sv[i].HD[2],sv[i].giuaky,sv[i].cuoiky);
  }
}

void catten(char ten[], char t[]){
  int i,j=0;
  for(i=strlen(ten)-1;i>=0;i--)
    if(ten[i]==' ') break;
  i++;
  for(i;i<strlen(ten);i++) t[j++]=ten[i];
  t[j]='\0';
  printf("%s\n",t);
}

void sorttheoten(sinhvien sv[]){
  char t[100][100];
  int i,j;
  for(i=0;i<sosv;i++){
    catten(sv[i].ten,t[i]);
  }
  sinhvien temp;
  for(i=0;i<sosv;i++)
    for(j=i+1;j<sosv;j++){
      if(strcmp(t[i],t[j])>0){
	printf("%s  %s\n",t[i],t[j]);
	temp=sv[j];
	sv[j]=sv[i];
	sv[i]=temp;
      }
    }
}

void menu(){
  printf("Chuong trinh \n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Bo sung sinh vien \n");
  printf("2.Danh sach sinh vien bao ve thanh cong \n");
  printf("3.Sap xep theo ten sv \n");
  printf("4.Thoat \n");
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
  int c,n;
  sinhvien sv[20];
  
  do{
    menu();
    c = choose();
    switch(c){
    case 1:
      printf("Nhap so sinh vien muon bo sung: "); scanf("%d%*c",&n);
      bosungsv(sv,n);
      break;
    case 2:
      dsbvthanhcong(sv);
      break;
    case 3:
      sorttheoten(sv);
      in(sv);
      break;
    case 4:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 4);
}
