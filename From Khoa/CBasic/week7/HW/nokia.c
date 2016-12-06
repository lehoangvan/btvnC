#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#define BLOCK 10

void readListFromBin_After(char *input){
	FILE *fpin = fopen(input,"rb");
	
	
	if(fpin == NULL) {
		printf("Can't open file %s\n",input);
	}
	else {
		int count = 0;
		elementtype *phone;
		phone = (elementtype*)malloc(BLOCK*sizeof(elementtype));
		int num;

		while(!feof(fpin)){
			num = fread(phone,sizeof(elementtype),BLOCK,fpin);
			for(int i=0; i < num; i++){
				insertAfterCurrent(phone[i]);
			}
			count+=num;
		}
		printf("Da nap %d ban ghi vao danh sach\n", count);
	}
	
	fclose(fpin);
}

void readListFromBin_Before(char *input){
	FILE *fpin = fopen(input,"rb");
	int count =0;

	if(fpin == NULL) printf("Can't open file %s\n",input);
	else {
		elementtype *phone;
		phone = (elementtype*)malloc(BLOCK*sizeof(elementtype));
		int num;

		while(!feof(fpin)){
			num = fread(phone,sizeof(elementtype),BLOCK,fpin);
			for(int i=0; i < num; i++){
				insertBeforeCurrent(phone[i]);
			}
			count+=num;
		}
		printf("Da nap %d ban ghi vao danh sach\n", count);
	}
	fclose(fpin);
}

node* searchByModel(char *model){
    node * p;
    for (p = root; p!= NULL; p = p->next) {
        if(strcmp(p->inf.model, model)== 0) return p;
    }
}


void menu(){
  printf("\n\nChuong trinh Quan ly danh ba\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Import from elementtypeDB.dat\n");
  printf("2. Display\n");
  printf("3. Add new phone\n");
  printf("4. Insert at position\n");
  printf("5. Delete at position\n");
  printf("6. Delete current\n");
  printf("7. Delete first\n");
  printf("8. Search and update\n");
  printf("9. Divide and Extract\n");
  printf("10. Reverse list\n");
  printf("11. Save to file\n");
  printf("12. Free list and quit\n");
}

int choose(){
  int n;
  do {
    printf("Nhap lua chon: ");
    if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(){
	

	int c, cc, p;
	elementtype phone;
	char model[100];
	do{
	    menu();
	    c = choose();
	    switch(c){
	    case 1:
	    	readListFromBin_After("NokiaDB.dat");
	      	break;
	    case 2:
	    	printf("\n\nSTT\t%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
	    	traversingList();
	      	break;
	    case 3:
	    	printf("1. Insert before current\n");
          	printf("2. Insert after current\n");
          	printf("Nhap lua chon: ");
          	scanf("%d%*c",&cc);

          	if(cc==1) {
            	printf("Model: "); gets(phone.model);
            	printf("Memory: "); gets(phone.memory);
            	printf("Screen: "); gets(phone.screen);
            	printf("Price: "); gets(phone.price);
            	insertBeforeCurrent(phone);
	        }
	        else if(cc==2){
            	printf("Model: "); gets(phone.model);
            	printf("Memory: "); gets(phone.memory);
            	printf("Screen: "); gets(phone.screen);
            	printf("Price: "); gets(phone.price);
            	insertAfterCurrent(phone);
	        }
	        else printf("Wrong choise\n");
	     	break;
	    case 4:	 
	       	
            printf("Model: "); gets(phone.model);
            printf("Memory: "); gets(phone.memory);
            printf("Screen: "); gets(phone.screen);
            printf("Price: "); gets(phone.price);
            printf("Position: "); scanf("%d%*c",&p);
        
	    	insertAtPosition(phone, p);
	     	break;
	    case 5:
	    	printf("Position: "); scanf("%d%*c",&p);
	    	deleteAtPosition(p);
	     	break;

	    case 6:
	    	deleteCurrent();
	     	break;
	    case 7:
	    	deleteHead();
	     	break;
	    case 8:
	    	printf("Model: "); gets(model);
	    	node *p = searchByModel(model);
	    	displayNode(p);
	    	printf("Nhap 1 de sua nut va phim khac de thoat\n-->");
          	scanf("%d%*c",&cc);

          	if(cc==1) {
            	printf("Model: "); gets(phone.model);
            	printf("Memory: "); gets(phone.memory);
            	printf("Screen: "); gets(phone.screen);
            	printf("Price: "); gets(phone.price);
            	p->inf = phone;
	      	}
	     	break;
	    case 9:
	    	
	     	break;
	    case 10:
	    	reverseList();
	     	break;
	    case 11:
	    	saveToFile();
	     	break;
	    case 12:

	     	break;
	    
	    default:
	      printf("Lua chon sai!\n\n");
	      	break;
	    }
	} while(c!= 12);
	
	return 0;
}