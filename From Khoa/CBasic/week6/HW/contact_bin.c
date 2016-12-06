#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trim.h"

#define BLOCK 10

typedef struct NOKIA {
  char model[100];
  char memory[100];
  char screen[15];
  char price[15];
} NOKIA;

struct list_el {
	NOKIA phone;
	struct list_el *next;
};

typedef struct list_el node_addr;

node_addr *root, *cur;

node_addr* makeNewNode(NOKIA phone){
	node_addr* new = (node_addr*) malloc(sizeof(node_addr));
	new->phone=phone;
	new->next =NULL;
	return new;
}

void insertAtHead(NOKIA phone){
	node_addr* new = makeNewNode(phone);
	new->next = root;
	root = new;
	cur = root;
}

void insertAfterCurrent(NOKIA phone){
	node_addr *new = makeNewNode(phone);
	if ( root == NULL ) {
		root = new;
		cur = root;
	} 
	else {
   		new->next = cur->next;
		cur->next = new;
		cur = new;
	}
}

void insertBeforeCurrent(NOKIA phone) {
	node_addr * new = makeNewNode(phone);
    if (root == NULL) {
		root = new;
		cur = root;
	} 
	else if(cur == root){
		new->next = root;
		root = new;
		cur = root;
	}
	else {
		node_addr *tmp = root;
  		while (tmp->next != cur && cur != NULL) tmp=tmp->next;

		new->next=cur;
    	if (cur==root) {
			root = new; 
		}
		else tmp->next = new;
		cur = new;
	}
}

void displayNode(node_addr* p){
	if (p==NULL){printf("Loi con tro NULL\n"); return; }
	NOKIA phone = p->phone;
	printf("%-20s%-10s%-10s%-15s\n",phone.model,phone.memory,phone.screen,phone.price);
}

void traversingList(){
	node_addr * p;
	for (p = root; p!= NULL; p = p->next) 
	 	displayNode(p);
}

void deleteHead(){
	if(root!=NULL) {
		node_addr *tmp = root->next;
		free(root);
		root = tmp;
	}
}

void destroyList(){
	while(root!=NULL) deleteHead();
	printf("Danh sach da duoc giai phong\n");
}

void readListFromBin_After(char *input){
	FILE *fpin = fopen(input,"rb");
	int count = 0;
	
	if(fpin == NULL) printf("Can't open file %s\n",input);
	else {
		NOKIA *phone;
		phone = (NOKIA*)malloc(BLOCK*sizeof(NOKIA));
		int num;

		while(!feof(fpin)){
			num = fread(phone,sizeof(NOKIA),BLOCK,fpin);
			for(int i=0; i < num; i++){
				insertAfterCurrent(phone[i]);
			}
			count+=num;
		}
	}
	printf("Da nap %d ban ghi vao danh sach\n", count);
	fclose(fpin);
}

void readListFromBin_Before(char *input){
	FILE *fpin = fopen(input,"rb");
	int count =0;

	if(fpin == NULL) printf("Can't open file %s\n",input);
	else {
		NOKIA *phone;
		phone = (NOKIA*)malloc(BLOCK*sizeof(NOKIA));
		int num;

		while(!feof(fpin)){
			num = fread(phone,sizeof(NOKIA),BLOCK,fpin);
			for(int i=0; i < num; i++){
				insertBeforeCurrent(phone[i]);
			}
			count+=num;
		}
		printf("Da nap %d ban ghi vao danh sach\n", count);
	}
	fclose(fpin);
}

void menu(){
  printf("\n\nChuong trinh Quan ly danh ba\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Nap danh sach\n");
  printf("2. In noi dung danh sach\n");
  printf("3. Giai phong danh sach\n");
  printf("4. Thoat\n");
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
	int c, cc;
	do{
	    menu();
	    c = choose();
	    switch(c){
	    case 1:
	    	printf("\n-->Chon phuong thuc nap\n");
	    	printf("\t1. Nap vao dau danh sach\n");
	    	printf("\t2. Nap vao phia sau danh sach\n");
	    	cc = choose();
	    	if(cc == 1 ) readListFromBin_Before("NokiaDB.dat");
	    	else readListFromBin_After("NokiaDB.dat");
	      	break;
	    case 2:
	    	traversingList();
	      	break;
	    case 3:
	    	destroyList();
	     	break;
	    case 4:

	     	break;
	    default:
	      printf("Lua chon sai!\n\n");
	      	break;
	    }
	} while(c!= 4);
	
	return 0;
}