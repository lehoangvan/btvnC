#include<stdio.h>
#include<stdlib.h>

int n;
int k;
int *x;

void PrintResult() {
  for(int i=1;i<=k;i++) printf("%d",x[i]);
  printf("\n");
}

void Generate(int i){
  for(int j=x[i-1]+1;j<=n-k+i;j++){
    x[i]=j;
    if(i==k) PrintResult();
    else(Generate(i+1));
  }
}

int main(){
  n=4;
  k=2;
  x= malloc(n*sizeof(int));
  x[0]=0;
  Generate(1);
  free(x);
  return 0;
}
