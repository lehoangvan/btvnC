#include<stdio.h>
#include<math.h>

double canh(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int gocvuong(int x1, int y1, int x2, int y2, int x3, int y3){
  double d1, d2, d3;
  d1=canh(x1,y1,x2,y2);
  d2=canh(x2,y2,x3,y3);
  d3=canh(x1,y1,x3,y3);
  if((d1==sqrt(d2*d2+d3*d3))||(d2==sqrt(d1*d1+d3*d3))||(d3==sqrt(d1*d1+d2*d2))) return 1;
  return 0;
}

int kiemtrahcn(int x[], int y[]){
  int i, count=0;
  for(i=0;i<4;i++){
    if(gocvuong(x[i],y[i],x[(i+1)%4],y[(i+1)%4],x[(i+2)%4],y[(i+2)%4])) count +=1;
  }
  if(count==4)  return 1;
  else return 0;
}

float dientich(int x1, int y1, int x2, int y2, int x3, int y3){
  float AB,BC,CA,p,S;
  AB = canh(x1,y1,x2,y2);
  BC = canh(x2,y2,x3,y3);
  CA = canh(x3,y3,x1,y1);
  p= (AB +BC +CA)/2;
  S= sqrt( (p - AB)*(p - BC)*(p - CA)*p);
  return S;
}

int kiemtra(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
 /* kiem tra tu giac loi voi D(x4,y4) */
  int test;
  float S_ABC,S_BCD,S_ABD,S_ACD,sum;
  S_ABC = dientich(x1,y1,x2,y2,x3,y3);
  S_BCD = dientich(x2,y2,x3,y3,x4,y4);
  S_ABD = dientich(x1,y1,x2,y2,x4,y4);
  S_ACD = dientich(x1,y1,x3,y3,x4,y4);
  sum = S_ACD + S_ABD + S_BCD;
  test = sum>S_ABC?1:0;
  return test;
}

int kiemtradiem(int a[], int b[]){
  int test1, test2, test3, test4;
  test1 = kiemtra(a[0],b[0],a[1],b[1],a[2],b[2],a[4],b[4]);/* E nam trong ABC ?*/
  test2 = kiemtra(a[0],b[0],a[1],b[1],a[3],b[3],a[4],b[4]);/* E nam trong ABD ?*/
  test3 = kiemtra(a[0],b[0],a[2],b[2],a[3],b[3],a[4],b[4]);/* E nam trong ACD ?*/
  test4 = kiemtra(a[1],b[1],a[2],b[3],a[3],b[3],a[4],b[4]);/* E nam trong BCD ?*/
  printf("%d %d %d %d\n",test1, test2, test3, test4);
  if( (test1==1)&&(test2==1)&&(test3==1)&&(test4==1) ) return 0;
  else return 1;
}



int main(){
  int x[5], y[5];
  int choose=0;
  int i;
  do{
  printf("Chuong trinh kiem tra hinh chu nhat!\n");
  printf("Author: Anh Khoa\n\n\n");
  printf("1.Nhap toa do dinh.\n");
  printf("2.Kiem tra hinh chu nhat.\n");
  printf("3.Kiem tra diem thu 5 co thuoc hinh chu nhat khong.\n");
  printf("4.Thoat.\n\n");
  printf("Nhap lua chon: "); scanf("%d",&choose);
  switch(choose){
  case 1:
    for(i=0;i<4;i++){
      printf("Nhap toa do diem thu %d: ",i+1); scanf("%d %d",&x[i],&y[i]);
    }
    break;
  case 2:
    if(kiemtrahcn(x,y)) printf("Tu 4 diem tren tao duoc 1 hinh chu nhat!\n\n\n");
    else printf("Tu 4 diem tren khong the tao duoc hinh chu nhat!\n\n\n");
    break;
  case 3:
    if(!kiemtrahcn(x,y)) printf("Tu 4 diem tren khong the tao duoc hinh chu nhat!\n\n\n");
    else {
      printf("Nhap diem thu 5: "); scanf("%d %d",&x[4],&y[4]);
      if(kiemtradiem(x,y)) printf("Diem da cho nam trong hcn!\n\n\n");
      else printf("Diem da cho khong nam trong hinh chu nhat!\n\n\n");
    }
    break;
  case 4:
    break;
  default:
    printf("Lua chon sai!\n\n\n");
    break;
  }
  } while(choose!=4);
  
  return 0;  
}
