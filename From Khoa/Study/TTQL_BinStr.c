#include<stdio.h>
#include<stdlib.h>

int n;
int *x;

void PrintResult() {
  for(int i=0;i<n;i++) printf("%d",x[i]);
  printf("\n");
}

void Generate(int i){
  for(int j=0;j<=1;j++){
    x[i]=j;
    if(i==3) PrintResult();
    else(Generate(i+1));
  }
}

int main(){
  n=3;
  x= malloc(n*sizeof(int));
  Generate(0);
  free(x);
  return 0;
}
