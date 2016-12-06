#include<stdio.h>



void nhap(float diem[][5], int soao[]){
  int i,j;
  for(i=0;i<11;i++){
    printf("Cau thu thu %d :\n",i+1);
    while(1){
    printf("So ao: "); scanf("%d",&soao[i]);
    for(j=0;j<=i;j++){
      if(soao[i]==soao[j]) break;
    }
    if(j==i) break;
    else printf("So ao trung\n\n");
    }
    for(j=0;j<5;j++)
      {
	printf("Danh gia cua chuyen gia thu %d: ",j+1);
	scanf("%f",&diem[i][j]);
      }
    printf("\n");
  }
}

void xuat(float diem[][5], int soao[]){
  int i,j;
  float sum;
  printf("%7s%10s\n","So ao","Diem");
  for(i=0;i<11;i++){
    sum=0;
    printf("%5d",soao[i]);
    for(j=0;j<5;j++)
      {
	sum+=diem[i][j];
      }
    printf("%4s%7.1f (","-",sum);
    for(j=0;j<5;j++)
      {
	printf("%.1f ",diem[i][j]);
      }
    printf(")\n\n\n");
  }
}

int khatkhe(float diem[][5]){
  int i,j,jmin;
  float sum, min;
  min =100000;
  for(j=0;j<5;j++){
    sum=0;
    for(i=0;i<11;i++)
      {
	sum+=diem[i][j];
      }
    if(sum<min) {jmin=j; min=sum;}
  }
  return jmin;
}

int thoang(float diem[][5]){
  int i,j,jmax;
  float sum, max=0;
  for(j=0;j<5;j++){
    sum=0;
    for(i=0;i<11;i++)
      {
	sum+=diem[i][j];
      }
    if(sum>max) {jmax=j; max=sum;}
  }
  return jmax;
}


int main(){
  float d[11][5];
  int s[11];
  nhap(d,s);
  xuat(d,s);
  printf("Chuyen gia so %d cham khat khe nhat! \n",khatkhe(d)+1);
  printf("Chuyen gia so %d cham thoang nhat! \n",thoang(d)+1);
  return 0;
}
