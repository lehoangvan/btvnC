#include<stdio.h>

int sohoanhao(int n){
  int i, s=0;
  for(i=1; i<=n/2; i++){
    if(n%i==0) s+=i;
  }
  if(s==n) return 1;
  return 0;
}

int main(){
  int n;
  while(1){
  printf("Nhap n: "); scanf("%d",&n);
  if(n>0) break;
  else printf("Nhap sai\n");
  }
  if(sohoanhao(n)) printf("%d la so hoan hao\n",n);
  else printf("%d khong phai la so hoan hao\n",n);
  return 0;
}
