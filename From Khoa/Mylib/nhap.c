//so nguyen 0-10

int songuyen(){
  int n=-1;
  while(1){
    printf("Nhap :"); scanf("%d%*c",&n);
    if((n>10)||(n<0)) printf("So vua nhap khong hop le\n\n");
    else break;
  }
  return n;
}

