#include<stdio.h>
#include<stdlib.h>

float dientich(float a, float b){
  if(a<0 || b<0) return 0;
  return a*b;
}

int main(int argc, char *argv[]){
  if(argc == 3) {
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float dt = dientich(a,b);
    if(dt==0) printf("Nhap sai gia tri doi so!\n");
    else printf("Dien tich = %.2f\n",dt);
  }
  else printf("Nhap sai! Phai truyen vao 2 doi so\n");
  return 0;
}
