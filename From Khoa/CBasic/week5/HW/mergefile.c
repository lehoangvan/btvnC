#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 2

typedef struct CONTACT
{
	char ten[15];
	char sdt[15];
} CONTACT;

void merge(char *split1, char *split2, char *file){
	
	FILE *fpin1 = fopen(split1,"rb");
	FILE *fpin2 = fopen(split2,"rb");
	if(fpin1==NULL) {
    	printf("Can't open file %s\n",split1);
	}
	else if(fpin1==NULL){
		printf("Can't open file %s\n",split2);
	}
	else {
		FILE *fpout = fopen(file,"wb");
		int num;
		CONTACT *db;
		db = malloc(BLOCK*sizeof(CONTACT));
		while(!feof(fpin1)){
			num = fread(db,sizeof(CONTACT),BLOCK,fpin1);
			fwrite(db,sizeof(CONTACT),num,fpout);
		}
		
		while(!feof(fpin2)){
			num = fread(db,sizeof(CONTACT),BLOCK,fpin2);
			fwrite(db,sizeof(CONTACT),num,fpout);
		}

		printf("%s\n", "Process is completed");
		free(db);
		fclose(fpin1);
		fclose(fpin2);
		fclose(fpout);
	}
}

int main(int argc, char **argv){
	if(argc==4){
		merge(argv[1], argv[2], argv[3]);
	} 
	else printf("Nhap sai! Phai truyen vao 4 doi so\n");
	return 0;
}