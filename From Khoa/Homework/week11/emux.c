#include<stdio.h>

float emux(float x, float c){
  int i=1,n=1;
  float emux=1, temp=x;
  while(x/n>=c){
    emux+=x/n;
    x*=temp;
    i++;
    n*=i;
  }
  return emux;
}

float sinx(float x, float c){
  int i=1,n=1,j=1;
  float sinx=0, temp=x;
  while(j*x/n>=c){
    sinx+=x/n;
    j*=-1;
    x=x*temp*temp*j;
    i+=2;
    n=n*i*(i-1);
  }
  return sinx;
}

float lnx(float x, float c){
  int n=1,j=1;
  float lnx=0, temp=x;
  while(j*x/n>=c){
    lnx+=x/n;
    j*=-1;
    x=x*temp*j;
    n++;
  }
  return lnx;
}

void menu(){
  printf("Chuong trinh \n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Tinh e^x \n");
  printf("2.Tinh sin(x) \n");
  printf("3.Tinh ln(1+x) \n");
  printf("4.Thoat \n");
}

int choose() {
  printf("Nhap lua chon: ");
  int n;
  scanf("%d",&n);
  return n;
}

int main(){
  int ch;
  float x,c;
do{
  menu();
  ch = choose();
  
  switch(ch){
  case 1:
    printf("Nhap x: "); scanf("%f",&x);
    printf("Nhap sai so: "); scanf("%f",&c);
    printf("e^%f = %f (sai so %f)\n\n",x,emux(x,c),c);
    break;
  case 2:
    printf("Nhap x: "); scanf("%f",&x);
    printf("Nhap sai so: "); scanf("%f",&c);
    printf("sin(%f) = %f (sai so %f)\n\n",x,sinx(x,c),c);
    break;
  case 3:
    printf("Nhap x: "); scanf("%f",&x);
    printf("Nhap sai so: "); scanf("%f",&c);
    printf("ln(1+%f) = %f (sai so %f)\n\n",x,lnx(x,c),c);
    break;
  case 4:
    break;
  default:
    printf("Lua chon sai!\n\n");
    break;
    }
 } while(ch!=4);
 return 0;
}
