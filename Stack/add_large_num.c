#include"stack_self.h"
#include<math.h>

StackType s1, s2, s;
void initialize()
{
  s.top=-1; // s la variable => phai dung dau . de lay phan tu
  s1.top=-1;
  s2.top=-1;
}

int main()
{
  initialize();
  char S1[MAX], S2[MAX];
  printf("Enter S1: ");
  scanf("%s",S1);
  getchar();
  printf("Enter S2: ");
  scanf("%s",S2);
  getchar();
  int i, a=0;
  int m=strlen(S1), n=strlen(S2);
  if(m>=MAX||n>=MAX) printf("Too large\n");

  if(m<n) a=n; else a=m; //s.top=a;
  char x;
  printf("You have enter two numbers: %s, %s\n",S1, S2);
  int j;
  for(i=0;i<a;i++)
    {
      s1.storage[i]=0; s1.top++;
      s2.storage[i]=0; s2.top++;
    }
  
  for (i=a-m;i<a;i++)
    { 
      x=S1[i-a+m];
      s1.storage[i]=x-48;
    }
  display(s1);  printf("\n\n");

  for (i=a-n;i<a;i++)
    { 
      x=S2[i-a+n];
      s2.storage[i]=x-48;
    }
  display(s2);  printf("\n\n");
  
  for(i=0;i<=a;i++)
    {
      s.storage[i]=0;
      s.top++;
    }
  //display(s); printf("\n\n");
  int b=0;
  int c;
  for(i=a;i>0;i--)
    {
      if(c=(s1.storage[i-1]+s2.storage[i-1]+b)/10 >0) s.storage[i-1]++;
      s.storage[i]=(s1.storage[i-1]+s2.storage[i-1]+b)%10;
      b=s.storage[i-1];
    }
  display(s); printf("\n");

  return 0;
}
