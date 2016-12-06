#include<stdio.h>
#include<time.h>
#include<string.h>

int matranmau[5][3];

typedef struct{
  char ten[30];
  int buoc[5];
  int diem;
} nguoichoi;

void tao_o_mau(){
  int i,j;
  srand(time(NULL));
  for(i=0;i<5;i++){
    do{
      matranmau[i][0]=rand()%3;
      matranmau[i][1]=rand()%3;
      matranmau[i][2]=rand()%3;
    } while((matranmau[i][0]==matranmau[i][1])||(matranmau[i][0]==matranmau[i][2])||(matranmau[i][1]==matranmau[i][2]));
  }
}

void in_ma_tran(){
  int i,j;
  printf("\n\n");
  for(i=0;i<5;i++){
    for(j=0;j<3;j++) {
      if(matranmau[i][j]==0) printf("%-7s","Xanh");
      else if(matranmau[i][j]==1) printf("%-7s","Vang");
      else if(matranmau[i][j]==2) printf("%-7s","Do");
      else printf("ERROR!");
    }
    printf("\n");
  }
}

void thay_doi_o(){
  int x,y,j,mau;
  while(1){
    printf("Nhap toa do o can doi: "); scanf("%d%*c%d%*c",&x,&y);
    if((x>5)||(x<1)||(y>3)||(y<1)) printf("So vua nhap khong hop le\n\n");
    else break;
  }
  while(1){
    printf("Nhap mau can doi (0-Xanh 1-Vang 2-Do): "); scanf("%d%*c",&mau);
    if((mau>2)||(mau<0)) printf("So vua nhap khong hop le\n\n");
    else if(mau==matranmau[x-1][y-1]) printf("Mau moi trung voi mau cu\n\n");
    else {
      for(j=0;j<3;j++) if(matranmau[x-1][j]==mau) matranmau[x-1][j]=matranmau[x-1][y-1];
      matranmau[x-1][y-1]=mau;
      break;
    }
  }
}

void chuan_hoa_ten(char *ten){
  int i;
  if((ten[0]>='a')&&(ten[0]<='z')) ten[0]-=32; 
  for(i=1;i<strlen(ten);i++){
    if((ten[i]==' ')&&(ten[i+1]>='a')&&(ten[i+1]<='z')) ten[i+1]-=32; 
  }
}

void choi(nguoichoi nc[]){
  int i,j,k;

  for(i=0;i<3;i++){
    nc[i].buoc[0]=-1;
  }
  
  for(i=0;i<3;i++){
    printf("Nhap ten nguoi choi thu %d: ",i+1); gets(nc[i].ten);
    chuan_hoa_ten(nc[i].ten);
    
    while(1){
      printf("Chon mau (0-Xanh 1-Vang 2-Do):"); scanf("%d%*c",&nc[i].buoc[0]);
      if((nc[i].buoc[0]>2)||(nc[i].buoc[0]<0)) printf("Mau vua nhap khong hop le\n");
      else if((nc[i].buoc[0]==nc[(i+1)%3].buoc[0])||(nc[i].buoc[0]==nc[(i+2)%3].buoc[0])) printf("Nguoi khac da chon mau nay\n");
      else break;
    }
    
    for(j=1;j<5;j++){
      for(k=0;k<3;k++) if(matranmau[j][k]==nc[i].buoc[0]) nc[i].buoc[j]=k;
    }
    
    for(j=0;j<5;j++){
      if((nc[i].buoc[j]-nc[i].buoc[j+1]==2)||(nc[i].buoc[j]-nc[i].buoc[j+1]==-2)) {
	nc[i].diem=j;
	break;
      }
      if(j==4) nc[i].diem=5;
    }
  }
}

void inkq(nguoichoi nc[]){
  int i;
  printf("\n\n%-10s%-30s%-7s\n","Luot choi","Nguoi choi","Diem");
  for(i=0;i<3;i++){
    printf("%-10d%-30s%-7d\n",i+1,nc[i].ten,nc[i].diem);
  }
  printf("\n");
}

void menu(){
  printf("\n\nChuong trinh ghi nho buoc chan\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Tao o mau\n");
  printf("2. Thay doi ma tran\n");
  printf("3. Choi\n");
  printf("4. Hien thi ket qua\n");
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
  int c;
  nguoichoi nc[3];
  do{
    menu();
    c = choose();
    switch(c){
    case 1:
      tao_o_mau();
      in_ma_tran();
      break;
    case 2:
      thay_doi_o();
      in_ma_tran();
      break;
    case 3:
      choi(nc);
      break;
    case 4:
      inkq(nc);
      break;
    case 5:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 5);
}
