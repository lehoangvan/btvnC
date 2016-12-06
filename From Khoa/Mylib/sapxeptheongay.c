#include<stdio.h>
#include<string.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  Date date;
} struct_t;


int sosanhngay(Date d1, Date d2){
  if(d1.year<d2.year) return -1;
  else if(d1.year>d2.year) return 1;
  else
    {
      if(d1.month<d2.month) return -1;
      else if(d1.month>d2.month) return 1;
      else
	{
	  if(d1.day<d2.day) return -1;
	  else if(d1.day>d2.day) return 1;
	}
    }
  return 0;
}

void sapxepngay(struct_t *st,int n){
  int i,j;
  struct_t temp;
  //giam dan
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(sosanhngay(st[i].date,st[j].date)==-1){
	temp=st[i];
	st[i]=st[j];
	st[j]=temp;
      }
    }
  //tang dan
  /*
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(sosanhngay(st[i].date,st[j].date)==1){
	temp=st[i];
	st[i]=st[j];
	st[j]=temp;
      }
    }
  */
}

int main(){
  struct_t st[3];
  int i;
  for(i=0;i<3;i++){
    printf("Nhap ngay: "); scanf("%2d%*c%2d%*c%4d%*c",&st[i].date.day,&st[i].date.month,&st[i].date.year);
  }
  sapxepngay(st,3);
  for(i=0;i<3;i++){
    printf("%d/%d/%d\n",st[i].date.day,st[i].date.month,st[i].date.year);
  }
}
