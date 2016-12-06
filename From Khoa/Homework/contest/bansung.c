#include<stdio.h>

typedef struct {
char ten[30] ;
int diem[5] ;
  int tongdiem;  
} kqthidau ;


int sovdv(){
  int n;
  do {
    printf("Nhap so van dong vien: ");
    if(scanf("%d",&n)==0) n=-1;
  } while((getchar()!='\n')||(n<0)||(n>10));
  return n;
}

int sodiem(){
  int n;
  do {
    printf("  -> Diem so: ");
    if(scanf("%d",&n)==0) n=-1;
  } while((getchar()!='\n')||(n<0)||(n>10));
  return n;
}

void dangkyvdv(kqthidau kq[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("Nhap ten van dong vien %d: ",i+1); gets(kq[i].ten);
  }
  
  printf("\n\nDanh sach van dong vien\n\n%-30s\n","Ho ten");
  for(i=0;i<n;i++){
    printf("%-30s\n",kq[i].ten);
  }
}

void thidau(kqthidau kq[], int n){
  int i,j;
    for(i=0;i<n;i++){
    printf("Nguoi thu %d\n",i+1);
    kq[i].tongdiem=0;
    for(j=0;j<5;j++){
      printf("Lan ban %d:\n ",j+1); kq[i].diem[j]=sodiem();
      kq[i].tongdiem+=kq[i].diem[j];
    }
  }
}

void inkq(kqthidau kq[], int n){
  int i;
  printf("%-30s%-7s%-7s%-7s%-7s%-7s\n","Ho ten","Luot 1","Luot 2","Luot 3","Luot 4","Luot 5");
  for(i=0;i<n;i++){
    printf("%-30s%-7d%-7d%-7d%-7d%-7d\n",kq[i].ten,kq[i].diem[0],kq[i].diem[1],kq[i].diem[2],kq[i].diem[3],kq[i].diem[4]);
  }
}

void sapxep(kqthidau kq[], int n){
  int i,j;
  kqthidau temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(kq[i].tongdiem<kq[j].tongdiem){
	temp=kq[i];
	kq[i]=kq[j];
	kq[j]=temp;
      }
    }
}

void xephang(kqthidau kq[], int n){
  int i;
  sapxep(kq,n);
  printf("%-30s%-20s%-3d\n",kq[0].ten,"Gold",kq[0].tongdiem);
  printf("%-30s%-20s%-3d\n",kq[1].ten,"Silver",kq[1].tongdiem);
  printf("%-30s%-20s%-3d\n",kq[2].ten,"Bronze",kq[2].tongdiem);
}

void sieuxathu(kqthidau kq[], int n){
  int i,j,m=0;
  kqthidau xathu[10];
  for(i=0;i<n;i++)
    for(j=0;j<3;j++){
      if((kq[i].diem[j]==10)&&(kq[i].diem[j+1]==10)&&(kq[i].diem[j+2]==10))
	xathu[m++]=kq[i];
    }
  inkq(xathu,m);
}

void menu(){
  printf("Chuong trinh quan ly ket qua thi dau ban sung \n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Dang ky van dong vien \n");
  printf("2.Thi dau \n");
  printf("3.Xep hang \n");
  printf("4.Sieu xa thu \n");
  printf("5.Thoat \n");
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
  kqthidau kq[10];
  do{
    menu();
    c = choose();
    switch(c){
    case 1:
      n=sovdv();
      dangkyvdv(kq,n);
      break;
    case 2:
      thidau(kq,n);
      inkq(kq,n);
      break;
    case 3:
      xephang(kq,n);
      break;
    case 4:
      printf("Danh sach cac sieu xa thu\n");
      sieuxathu(kq,n);
      break;
    case 5:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
    printf("\n\n");
  } while(c!= 5);
}
