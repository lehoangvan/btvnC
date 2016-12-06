#include<stdio.h>

void taomangtrong(int a[], int n){
  int i;
  for(i=0;i<n;i++) a[i]=0;
}

void batmay(int may[], int dn[]){
  int n;
  do{
  printf("Nhap may can bat (0-39): ");
  scanf("%d",&n);
  } while((n>=40)||(n<0));
  if(may[n]==1) printf("May %d dang bat!\n\n",n);
  else {
    may[n]=1;
    dn[n]+=400;
    printf("May %d da bat!\n\n",n);
  }
}

void tatmay(int may[]){
  int n;
  do{
  printf("Nhap may can tat (0-39): ");
  scanf("%d",&n);
  } while((n>=40)||(n<0));
  if(may[n]==0) printf("May %d dang tat!\n\n",n);
  else {
    may[n]=0;
    printf("May %d da tat\n\n",n);
  }
}

void intrangthai(int may[]){
  int i;
  printf("%-5s%-20s\n","may","trang thai");
  for(i=0;i<40;i++){
    if(may[i]==0) printf("%-5d%-20s\n",i,"tat");
    else printf("%-5d%-20s\n",i,"BAT");
  }
}

void indn(int dn[]){
  int i,sum=0;
  printf("%-5s%-20s\n","may","dien nang tieu thu");
  for(i=0;i<40;i++){
    printf("%-5d%-20d\n",i,dn[i]);
    sum+=dn[i];
  }
  printf("\nTong: %-20d\n\n",sum);
}

void inhoadon(int dn[]){
  int i,sum=0;
  for(i=0;i<40;i++){
    sum+=dn[i];
  }
  printf("Tong dien nang: %-20d\n",sum);
  printf("Thanh tien: %.2f dong\n\n",0.75*sum);
}

int nhieunhat(int dn[]){
  int i, max=0, imax;
  for(i=0;i<40;i++){
    if(dn[i]>max) {max=dn[i];imax=i;}
  }
  return imax;
}

int itnhat(int dn[]){
  int i, min =100000, imin;
  for(i=0;i<40;i++){
    if(dn[i]<min) {min=dn[i];imin=i;}
  }
  return imin;
}

void menu(){
  printf("Chuong trinh quan ly phong lab\n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Bat may \n");
  printf("2.Tat may \n");
  printf("3.In trang thai may \n");
  printf("4.In dien nang tieu thu tren cac may\n");
  printf("5.In hoa don \n");
  printf("6.May dung nhieu nhat va it nhat \n");
  printf("7.Thoat \n");
}

int choose(){
  printf("Nhap lua chon: ");
  int n;
  scanf("%d",&n);
  return n;
}

int main(){
  int may[40];
  int dn[40];

  taomangtrong(may,40);
  taomangtrong(dn,40);
  
  int c;
  do{
  menu();
  c = choose();
  
  switch(c){
  case 1:
    batmay(may,dn);
    break;
  case 2:
    tatmay(may);
    break;
  case 3:
    intrangthai(may);
    break;
  case 4:
    indn(dn);
    break;
  case 5:
    inhoadon(dn);
    break;
  case 6:
    printf("May %d dung nhieu nhat\nMay %d dung it nhat\n\n",nhieunhat(dn),itnhat(dn));
    break;
  case 7:
    break;
  default:
    printf("Lua chon sai!\n\n");
    break;
    }
  } while(c!=7);
}
