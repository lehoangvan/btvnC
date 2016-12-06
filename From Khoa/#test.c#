#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS,FAIL};
 
void Code(FILE *fin, int i)
{
	int c;
	while((c=fgetc(fin))!=EOF)
	{
		fin--;
		if(c!=' ')
		c+=i;
		fputc (c ,fin);
		putchar(c);
	}
	printf("\n");
}
 
int main(int argc,char* argv[])
{
	int n;
	FILE *fptr;
	char file[10];
	strcpy(file,argv[1]);
	if(argc!=3)
	{
		printf("Wrong number of arguments.\n");
		return FAIL;
	}
	else if((fptr=fopen(file,"r+"))==NULL)
	{
		printf("Cannot open %s.\n",file);
		return FAIL;
	}
	else
	{
		n=atoi(argv[2]);
		Code(fptr,n);
		fclose(fptr);
	}
	return SUCCESS;
}
