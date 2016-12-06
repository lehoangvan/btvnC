#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 2

typedef struct CONTACT
{
	char ten[15];
	char sdt[15];
} CONTACT;

void create(){
	CONTACT *db;	
	FILE *fpout = fopen("phone.dat","wb");

	int n;
	printf("So lien he: ");
	scanf("%d%*c",&n);
	db = malloc(n*sizeof(CONTACT));
	for(int i=0; i<n; i++) {
		printf("Ten (< 15 ky tu) "); gets(db[i].ten);
		printf("SDT (< 15 ky tu) "); gets(db[i].sdt);
	}
	fwrite(db,sizeof(CONTACT),n,fpout);
	free(db);
	fclose(fpout);
}

int main(int argc, char **argv){
	if(argc==1){
		create();
	} 
	else printf("Nhap sai! Phai truyen vao 1 doi so\n");
	return 0;
}