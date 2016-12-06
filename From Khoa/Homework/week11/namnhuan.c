#include<stdio.h>

int namnhuan(int n){
  if((n%4==0)&((n%100!=0)|(n%400==0))) return 1;
  return 0;
}

int main(){
  int n;
  while(1){
  printf("Nhap nam: "); scanf("%d",&n);
  if(n>0) break;
  else printf("Nhap sai\n");
  }
  if(namnhuan(n)) printf("Nam %d la nam nhuan\n",n);
  else printf("Nam %d khong phai la nam nhuan\n",n);
  return 0;
}
