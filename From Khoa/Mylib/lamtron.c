#include<stdio.h>

//lam tron 1 chu so sau dau phay
float lamtron(float n){
  int i;
  n*=100;
  i=(int)n%10;
  n=n-i;
  if(i<5) i=0;
  else i=10;
  return (n+i)/100;
}

//lam tron den 0,5
float lamtron(float n){
  int i;
  n*=100;
  i=(int)n%100;
  n=n-i;
  if(i< 25) i=0;
  else if((i>=25)&&(i<75)) i=50;
  else i=100;
  return (n+i)/100;
}

int main(){
  printf("%f\n",lamtron(2.75));
 return 0;
}
