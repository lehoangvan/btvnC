#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define MAX 100

int main() {
	char postfix[MAX],s[MAX],c;
	int i,j=0 ;
	STACK *stack = newStack();
	printf("Prefix: ");
	scanf("%[^\n]%*c",s);

	for(i=0;i<strlen(s);i++) {
		if(s[i]>='0' && s[i]<='9') {
			postfix[j++]=s[i];
			while(s[i+1]>='0' && s[i+1]<='9') {
				postfix[j++] = s[++i];
			}
			postfix[j++]=' ';
		}
	  
		if(s[i]=='(') push(stack,s[i]);
	  	else if(s[i]==')') {
			while((c = pop(stack)) != '(') {
				printf("%c\n",c);
				postfix[j++]=c;
				postfix[j++]=' ';
			}
	 	}
		else if(s[i]=='*') {
			while(top(stack)!='+' && top(stack) != '-' && top(stack)!='(' && !isEmpty(stack)) {
				postfix[j++]=pop(stack);
				postfix[j++]=' ';
			}
			push(stack,s[i]);
		}
	  	else if(s[i]=='/') {
			while(top(stack)!='+'&&top(stack)!='-'&&top(stack)!='('&&!isEmpty(stack)) {
				postfix[j++]=pop(stack);
				postfix[j++]=' ';
			}
			push(stack,s[i]);
		}

		else if(s[i]=='+') {
			while(top(stack)!='('&&!isEmpty(stack)) {
				postfix[j++]=pop(stack);
				postfix[j++]=' ';
			} 
			push(stack,s[i]);
		}
	 	else if(s[i]=='-') {
	  
			while(top(stack)!='('&&!isEmpty(stack)) {
				postfix[j++]=pop(stack);
				postfix[j++]=' ';
			}
			push(stack,s[i]);
		}
	}

	while(!isEmpty(stack)) {
	  	postfix[j++]=pop(stack);
	    postfix[j++]=' ';
	}
	postfix[j]='\0';
	printf("Postfix: %s\n",postfix);

	return 0;
}
