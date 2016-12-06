#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CONTACT
{
	char ten[15];
	char sdt[15];
} CONTACT;

void split(char *file, int n, char *split1, char *split2){
	
	
	FILE *fpin = fopen(file,"rb");
	if(fpin==NULL) {
    printf("Can't open file %s\n",file);
	}
	else {
		FILE *fpout1 = fopen(split1,"wb");
		FILE *fpout2 = fopen(split2,"wb");
		CONTACT *db;
		db = malloc(n*sizeof(CONTACT));
		int num = fread(db,sizeof(CONTACT),n,fpin);
		fwrite(db,sizeof(CONTACT),n,fpout1);

		while(!feof(fpin)){
			num = fread(db,sizeof(CONTACT),n,fpin);
			fwrite(db,sizeof(CONTACT),num,fpout2);
		}
		
		printf("%s\n", "Process is completed");

		free(db);
		fclose(fpin);
		fclose(fpout1);
		fclose(fpout2);
	}
}

int main(int argc, char **argv){
	if(argc==5){
		split(argv[1], atoi(argv[2]), argv[3], argv[4]);
	} 
	else printf("Nhap sai! Phai truyen vao 5 doi so\n");
	return 0;
}