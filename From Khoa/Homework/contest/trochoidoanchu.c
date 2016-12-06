#include<stdio.h>
#include<string.h>

typedef struct{
  char name[25];
  int old;
  int score[5];
} player_t;

void nhapchuoi(char s[]){
  int i;
  do {
    printf("Nhap chuoi (20-40 ky tu, khong co khoang trang): ");
    gets(s);
    for(i=0;i<strlen(s);i++) if(s[i]==' ') s[0]='\0';
  } while((strlen(s)<20)||(strlen(s)>40));
}

void taochuoisao(char s[], char s1[]){
  int i;
  strcpy(s1,s);
  for(i=0;i<strlen(s);i++) s1[i]='*';
}

char chuanhoachu(char a){
  if((a>='A')&&(a<='Z')) a+=32;
  return a;
}

int doanchu(char s[], char s1[]){
  char a, c;
  int i, result=0;
  printf("Moi ban doan chu: ");scanf("%c%*c",&c);
  a=chuanhoachu(c);
  for(i=0;i<strlen(s);i++){
    if(a==s[i]) {
      result++;
      s1[i]=a;
    }
  }
  return result;
}

void nhapnguoichoi(player_t p[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("Nhap thong tin nguoi choi thu %d\n",i+1);
    printf("Ten: "); gets(p[i].name);
    printf("Tuoi: "); scanf("%d%*c",&p[i].old);
  }
}


void choi(player_t p[], int n, char s[], char s1[]){
  int i, score, j;
  char s2[100];
  for(i=0;i<n;i++){
    printf("Nguoi choi thu %d\n",i+1);
    taochuoisao(s,s1);
    p[i].score[4]=0;
    for(j=0;j<4;j++){
      (p[i].score)[j]=doanchu(s,s1);
      printf("\t%s\n",s1);
      (p[i].score)[4]+= (p[i].score)[j];
    }
    printf("Doan chuoi: "); gets(s2);
    //scanf("%*c");
    if(strcmp(s,s2)==0) {
      printf("Chuc mung ban da doan dung xau!\n");
      (p[i].score)[4]+=strlen(s);
    }
    else printf("Rat tiec ban da doan sai chuoi!\n");
  }
}

void sort(player_t p[], int n){
  int i,j;
  player_t temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(p[i].score[4]<p[j].score[4]){
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
      }
    }
}

void ketqua(player_t p[],int n){
  int i;
  printf("%-30s%-5s%-10s\n","Ten","Tuoi","Diem");
  for(i=0;i<n;i++){
    printf("%-30s%-5d%-10d\n",p[i].name,p[i].old,(p[i].score)[4]);
  }
}

void menu(){
  printf("Tro choi doan chu\n");
  printf("Author: Anh Khoa\n\n");
  printf("1.Khoi dong tro choi \n");
  printf("2.Choi doan chu \n");
  printf("3.Tong hop ket qua \n");
  printf("4.Thoat \n");
}

int choose(){
  int n;
  do{
  printf("Nhap lua chon: ");
  if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(){
  player_t p[100];
  char s[100], s1[100];
  int n;

  int c;
  do{
    menu();
    
    c = choose();
    switch(c){
    case 1:
      nhapchuoi(s);
      printf("Nhap so nguoi choi: "); scanf("%d%*c",&n);
      nhapnguoichoi(p,n);
      break;
    case 2:
      choi(p,n,s,s1);
      break;
    case 3:
      sort(p,n);
      ketqua(p,n);
      break;
    case 4:
      break;
    default:
      printf("Lua chon sai!\n\n");
      break;
    }
  } while(c!= 4);
  return 0;
}
