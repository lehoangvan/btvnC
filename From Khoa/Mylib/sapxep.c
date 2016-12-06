void sapxep(kqthidau kq[], int n){
  int i,j;
  kqthidau temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      if(kq[i].tongdiem<kq[j].tongdiem){
	temp=kq[i];
	kq[i]=kq[j];
	kq[j]=temp;
      }
    }
}
