//check mssv

int testms(struct_t st[], char ms[]){
  int i;
  if(strlen(ms)>5) return -1;  //ms it hon 5 ky tu
  for(i=0;i<n;i++){
    if(strcmp(st[i].MS,ms)==0) return 0;  //mssv da ton tai 
  }
  return 1;
}

//check name

int testten(struct_t st[], char ten[]){
  int i;
  if(strlen(ten)>30) return -1; //ten <30 ky tu
  for(i=0;i<strlen(ten);i++){
    if(ten[i]==' ') return 1;   //ten phai co khoang trang
  }
  return 0;
}
