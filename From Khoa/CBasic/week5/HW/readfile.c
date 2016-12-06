#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 2

typedef struct CONTACT
{
	char ten[15];
	char sdt[15];
} CONTACT;

void read(char *file){
	
	FILE *fpin = fopen(file,"rb");
	if(fpin==NULL) {
    printf("Can't open file %s\n",file);
	}
	else {
		int num;
		CONTACT *db;
		db = malloc(BLOCK*sizeof(CONTACT));
		printf("%-15s%-15s\n", "TEN", "SDT");
		while(!feof(fpin)){
			num = fread(db,sizeof(CONTACT),BLOCK,fpin);
			for(int i=0; i < num; i++){
				printf("%-15s%-15s\n", db[i].ten, db[i].sdt);
			}
		}
		
		free(db);
		fclose(fpin);
	}
}

int main(int argc, char **argv){
	if(argc==2){
		read(argv[1]);
	} 
	else printf("Nhap sai! Phai truyen vao 2 doi so\n");
	return 0;
}