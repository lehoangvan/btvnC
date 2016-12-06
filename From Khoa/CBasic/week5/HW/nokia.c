#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 2

typedef struct NOKIA{
  char model[100];
  char memory[100];
  char screen[15];
  char price[15];
} NOKIA;

int file_line(){
  FILE *fptr;
  int n=0;
  char c;
  fptr = fopen("NokiaDB.txt", "r");
  if(fptr==NULL) {
    printf("Can't open file %s\n","NokiaDB.txt");
    return -1;
  }
  else {
    c = fgetc(fptr);
    while(c != EOF){
      if(c=='\n') n++;
      c = fgetc(fptr);
    }
  }
  return n;
}

void trimLeft(char s[]){
  int i=0, j;
  while(s[0]==' '){
    for(j=0;j<strlen(s)-1;j++){
      s[j]=s[j+1];
    }
    s[strlen(s)-1]='\0';
  }
}

void trimRight(char s[]){
  int i=strlen(s)-1;
  while(s[i]==' '){
    s[i--]='\0';
  }
}

void trimMiddle(char s[]){
  int i=0,j;
  while(s[i]==' ') i++;
  for(i;i<strlen(s);i++){
    if((s[i]==' ')&&(s[i+1]==' ')){
  for(j=i;j<strlen(s)-1;j++){
    s[j]=s[j+1];
  }
  s[strlen(s)-1]='\0';
  i--;
      }
  }
}

void trim(char s[]){
  trimLeft(s);
  trimRight(s);
  trimMiddle(s);
}

void doc_ds_dt(NOKIA *dt, int n){
  FILE *fptr = fopen("NokiaDB.txt","r");
  char l[100];
  trim(l);
  int i;
  char *model, *memory, *screen, *price;
  
  for(i=0;i<n;i++) {
    fgets(l,100,fptr);
    trim(l);
    model = strtok(l," ");
    memory = strtok(NULL," ");
    screen = strtok(NULL," ");
    price = strtok(NULL,"\n");
    strcpy(dt[i].model,model);
    strcpy(dt[i].memory,memory);
    strcpy(dt[i].screen,screen);
    strcpy(dt[i].price,price);
  }
  fclose(fptr);
}

void write_bin(NOKIA *dt, int n){
  FILE *fptr = fopen("NokiaDB.dat","wb");
  if(dt == NULL) printf("Error\n");
  else fwrite(dt,sizeof(NOKIA),n,fptr);
  fclose(fptr);
}

/*
printf("\n\n%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
for(int i=0;i<n;i++) printf("%-20s%-10s%-10s%-15s\n",dt[i].model,dt[i].memory,dt[i].screen,dt[i].price);
*/

int read_bin_from_begin(int num){
  FILE *fptr = fopen("NokiaDB.dat","rb");
  int c=0;
  NOKIA *dt = malloc(num*sizeof(NOKIA));
  int n = fread(dt,sizeof(NOKIA),num,fptr);
  if(n==num){
    printf("\n\n%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
    for(int j=0;j<n;j++) printf("%-20s%-10s%-10s%-15s\n",dt[j].model,dt[j].memory,dt[j].screen,dt[j].price);
    c=1;
  }
  free(dt);
  fclose(fptr);
  return c;
}

int read_bin_from_end(int num){
  FILE *fptr = fopen("NokiaDB.dat","rb");
  int c=0;
  fseek(fptr,-num*sizeof(NOKIA),SEEK_END);
  NOKIA *dt = malloc(num*sizeof(NOKIA));
  int n = fread(dt,sizeof(NOKIA),num,fptr);
  if(n==num){
    printf("\n\n%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
    for(int j=0;j<n;j++) printf("%-20s%-10s%-10s%-15s\n",dt[j].model,dt[j].memory,dt[j].screen,dt[j].price);
    c=1;
  }
  free(dt);
  fclose(fptr);
  return c;
}

void search_by_model(int num, char *model){
  FILE *fptr = fopen("NokiaDB.dat","rb");
  int f=0;
  NOKIA *dt = malloc(num*sizeof(NOKIA));
  int n = fread(dt,sizeof(NOKIA),num,fptr);
  if(n==num){
    printf("\n\n%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
    for(int j=0;j<n;j++) 
      if(strcmp(dt[j].model,model)==0) {
        printf("%-20s%-10s%-10s%-15s\n",dt[j].model,dt[j].memory,dt[j].screen,dt[j].price);  
        f++;
      }
    if(f==0) printf("\nCan't find %s",model);
  }
  free(dt);
  fclose(fptr);
}

void menu(){
  printf("\n\nChuong trinh quan ly dien thoai Nokia\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Import DB from text\n");
  printf("2. Read from DB\n");
  printf("3. Print All Nokia Database\n");
  printf("4. Search by model\n");
  printf("5. Exit\n");
}

int choose(){
  int n;
  do {
    printf("Nhap lua chon: ");
    if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(int argc, char *argv[]) {
  if(argc == 1) {
      int c, n = file_line();
      int cc, num;
      char model[100];
      do{
        menu();
        c = choose();
        switch(c){
        case 1:
          if(n!=-1){
            NOKIA *dt;
            dt = calloc(n,sizeof(NOKIA));
            doc_ds_dt(dt, n);
            write_bin(dt, n);
            printf("Process is completed! Result is written into file NokiaDB.dat\n");
            free(dt);
          }
          break;
        case 2:
          printf("1. Doc file tu dau\n");
          printf("2. Doc file tu cuoi\n");
          printf("3. Doc toan bo file\n");
          printf("Nhap lua chon: ");
          scanf("%d%*c",&cc);
          if(cc==1) {
            printf("So ban ghi can doc: ");
            scanf("%d%*c",&num);
            if(read_bin_from_begin(num)==0) printf("Error\n");
          }
          else if(cc==2){
            printf("So ban ghi can doc: ");
            scanf("%d%*c",&num);
            if(read_bin_from_end(num)==0) printf("Error\n");
          }
          else if(read_bin_from_begin(n)==0) printf("Error\n");
          break;
        case 3:          
          if(read_bin_from_begin(n)==0) printf("Error\n");
          break;
        case 4:
          printf("Model: ");
          gets(model);
          search_by_model(n,model);
          break;
        case 5:
          
          break;
        default:
          printf("Lua chon sai!\n\n");
          break;
        }
      } while(c!= 5);
  }
  else printf("Nhap sai! Phai truyen vao 0 doi so\n");
  return 0;
}
