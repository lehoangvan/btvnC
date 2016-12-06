#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sub_string(char* s1, int offset, int number){
	char *s = malloc(number);
	int j=0;
	int len = strlen(s1);

	if(offset>len) {
		printf("Offset qua lon\n");
	}

	for(int i=offset;i<offset+number;i++){
		if(i>=len) break;
		s[j++] = s1[i];
	}
	s[j]='\0';
	return s;
}

int main(){
	char s[100];
	int offset, number;
	printf("Nhap chuoi:");
	gets(s);
	printf("Offset: ");
	scanf("%d%*c",&offset);
	printf("Number: ");
	scanf("%d%*c",&number);
	char *ss = sub_string(s,offset,number);
	printf("Substring: %s\n", ss);
	return 0;
}
