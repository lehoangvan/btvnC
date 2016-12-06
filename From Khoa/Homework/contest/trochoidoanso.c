#include<stdio.h>
#include<string.h>
#include<math.h>

float m;

typedef struct {
char ten[30];
int tuoi;
float doan[6];
float dosailech;
} player;

int testten(char ten[]){
  int i;
  if(strlen(ten)>30) return -1; 
  for(i=0;i<strlen(ten);i++){
    if(ten[i]==' ') return 1;  
  }
  return 0;
}

float sothuc(){
  float n;
  do {
    printf("Nhap N: ");
    if(scanf("%f",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int songuoichoi(){
  int n;
  do {
    printf("So nguoi choi: ");
    if(scanf("%d",&n)==0) n=-1;
  } while((getchar()!='\n')||(n<0)||(n>5));
  return n;
}

void khoidong(player pl[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("Nhap thong tin nguoi choi thu %d\n",i+1);
    while(1){
       printf("Ten: "); gets(pl[i].ten);
       if(testten(pl[i].ten) == -1) printf("Ten phai <30 ky tu\n");
       else if(testten(pl[i].ten) == 0) printf("Ten phai co khoang trang\n");
       else break;
    }
    printf("Tuoi: "); scanf("%d%*c",&pl[i].tuoi);
  }

  printf("\nDanh sach cac nguoi choi: \n\n");
  printf("%-30s%-5s\n","Ho va ten","Tuoi");
  for(i=0;i<n;i++){
    printf("%-30s%-5d\n",pl[i].ten,pl[i].tuoi);
  }

}

void choi(player pl[], int n){
  int i,j;
  float g;
  for(i=0;i<n;i++){
    for(j=0;j<6;j++){
      printf("Nguoi %d doan lan thu %d: ",i+1,j+1);
      scanf("%f%*c",&g);
      pl[i].doan[j]=g;
      if(g>m) printf("So ban vua doan lon hon ket qua\n");
      else if(g<m) printf("So ban vua doan nho hon ket qua\n");
      else{
	printf("Xin chuc mung ban da doan dung\n");
	if(j!=5) {
	  pl[i].doan[j+1]=-1;
	  pl[i].doan[5]=m;
	  break;
	}
      }
      printf("\n");
      pl[i].dosailech=fabs(pl[i].doan[5]/m-1);
    }
  }
}

void inkq(player pl[], int n) {
  int i,j;
  printf("%-30s%-5s%-5s%-5s%-5s%-5s%-5s%-5s\n","Ho va ten","Tuoi","L1","L2","L3","L4","L5","L6");
  for(i=0;i<n;i++){
    printf("%-30s%-5d",pl[i].ten,pl[i].tuoi);
    for(j=0;j<6;j++) {
      if (pl[i].doan[j] == -1) break;
      else printf("%-5.1f",pl[i].doan[j]);
    }
    printf("\n");
  }
}

void sapxep(player pl[], int n){
  int i,j;
  player temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(pl[i].dosailech>pl[j].dosailech){
	temp=pl[i];
	pl[i]=pl[j];
	pl[j]=temp;
      }
    }
  printf("%-30s%-5s\n","Ho va ten","Do sai lech");
  for(i=0;i<n;i++){
    printf("%-30s%-5f\n",pl[i].ten,pl[i].dosailech);
  }
}
 

void menu(){
  printf("Chuong trinh mo phong tro choi doan so\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Khoi dong tro choi\n");
  printf("2. Choi doan so\n");
  printf("3. Tong hop ket qua\n");
  printf("4. Thoat\n");
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
  player pl[5];
  do{
    menu();
    c = choose();
    switch(c){
    case 1:
      m=sothuc();
      n=songuoichoi();
      khoidong(pl,n);
      printf("\n\n");
      break;
    case 2:
      choi(pl,n);
      inkq(pl,n);
      printf("\n\n");
      break;
    case 3:
      sapxep(pl,n);
      printf("\n\n");
      break;
    case 4:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 4);
}
