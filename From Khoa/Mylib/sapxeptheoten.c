void catten(char ten[], char t[]){
  int i,j=0;
  for(i=strlen(ten)-1;i>=0;i--)
    if(ten[i]==' ') break;
  for(i;i<strlen(ten);i++) t[j++]=ten[i];
}


void sorttheoten(struct_t st[], int n){
  char t[100][100];
  int i,j;

  //cat lay ten luu vao mang t[][]
  for(i=0;i<n;i++){
    catten(st[i].ten,t[i]);
  }
  
  struct_t temp;

  //sap xep theo ten
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(strcmp(t[i],t[j])>0){
	temp=st[j];
	st[j]=st[i];
	st[i]=temp;
      }
    }
}
