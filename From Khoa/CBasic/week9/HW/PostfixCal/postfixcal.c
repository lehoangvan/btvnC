#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int getNum(char *s, int *i){
	int num = 0;
	while(s[*i] != ' '){
		num *= 10;
		num += s[*i] - '0';
		*i += 1;
	}
	return num;
}

int cal(char *postfix){
	STACK *stack = newStack();
	int a, b, num;
	for(int i=0; i<strlen(postfix); i++){
		if(postfix[i] >= '0' && postfix[i] <= '9') {
			num = getNum(postfix, &i);
			push(stack, num);
		}
		else {
			switch(postfix[i]){
				case '+':
					b = pop(stack);
					a = pop(stack);
					push(stack, a+b);
				break;
				case '-':
					b = pop(stack);
					a = pop(stack);
					push(stack, a-b);
				break;
				case '*':
					b = pop(stack);
					a = pop(stack);
					push(stack, a*b);
				break;
				case '/':
					b = pop(stack);
					a = pop(stack);
					push(stack, a/b);
				break;
			}
		}
	}
	return pop(stack);
}

int main(){
	char postfix[100];
	printf("Postfix: "); gets(postfix);
	printf("Result: %d\n", cal(postfix));
	return 0;
}