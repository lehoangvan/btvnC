#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack1.h"

void congsolon(char *a, char *b){
	int i, cs, nho=0, tong, cs1, cs2;
	elementtype e;
	STACK *s1 = newStack();
	STACK *s2 = newStack();
	STACK *sum = newStack();
	for(i=0;i<strlen(a);i++){
		cs = a[i] - '0';
		e.data = cs;
		push(s1, e);
	}
	for(i=0;i<strlen(b);i++){
		cs = b[i] - '0';
		e.data = cs;
		push(s2, e);
	}

	while(!isEmpty(s1) && !isEmpty(s2)){

		tong = pop(s1).data + pop(s2).data;
		e.data = tong%10 + nho;
		push(sum, e);
		nho = tong/10;
	}

	while(!isEmpty(s1)){
		tong = pop(s1).data;
		e.data = tong%10 + nho;
		push(sum, e);
		nho = 0;
	}
	while(!isEmpty(s2)){
		tong = pop(s2).data;
		e.data = tong%10 + nho;
		push(sum, e);
		nho = 0;
	}
	traversingStack(sum);
}

int main(){
  char a[100], b[100];
  printf("Nhap a: "); gets(a);
  printf("Nhap b: "); gets(b);
  printf("a + b = ");
  congsolon(a,b);
  return 0;
}
