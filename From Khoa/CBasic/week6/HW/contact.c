#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trim.h"

#define BLOCK 10

struct address_t {
    char name[20];
    char tel[11];
    char email[25];
}; 

typedef struct address_t address;

struct list_el {
	address addr;
	struct list_el *next;
};

typedef struct list_el node_addr;

node_addr *root, *cur;

node_addr* makeNewNode(address addr){
	node_addr* new = (node_addr*) malloc(sizeof(node_addr));
	new->addr=addr;
	new->next =NULL;
	return new;
}

void insertAtHead(address addr){
	node_addr* new = makeNewNode(addr);
	new->next = root;
	root = new;
	cur = root;
}

void insertAfterCurrent(address addr){
	node_addr *new = makeNewNode(addr);
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

void insertBeforeCurrent(address e) {
	node_addr * new = makeNewNode(e);
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
	address tmp = p->addr;
	printf("%-20s\t%-15s\t%-30s\n", tmp.name, tmp.tel, tmp.email);
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

int file_line(char *filename){
  FILE *fptr;
  int n=0;
  char c;
  fptr = fopen(filename, "r");
  if(fptr==NULL) {
    printf("Can't open file %s\n",filename);
    return -1;
  }
  else {
    c = fgetc(fptr);
    while(c != EOF){
      if(c=='\n') n++;
      c = fgetc(fptr);
    }
  }
  return n;
}

void getEmail(char *line, char *email){
  int j=0, i, count=0;
  for(i=strlen(line);i>=0;i--) if(line[i]==' ') break;
  i++;
  for(i;i<strlen(line)-1;i++) email[j++]=line[i];
  email[j]='\0';
}

int getSDT(char *line, char *sdt){
  int j=0, i, count=0;
  for(i=strlen(line);i>=0;i--) {
    if(line[i]==' ') count++;
    if(count==2) break;
  }
  int tmp = i;
  i++;
  for(i;i<strlen(line)-1;i++) {
    if(line[i]==' ') break;
    sdt[j++]=line[i];
  }
  sdt[j]='\0';
  return tmp;
}

void getTen(char *line, char *ten, int end){
  int j=0;
  for(int i=0;i<end;i++) {
    ten[j++]=line[i];
  }
  ten[j]='\0';
}

void readListFromText_After(char *input){
	FILE *fpin = fopen(input,"r");
	
	int n = file_line(input) - 1;
	if(n!=-1){
		char name[20], tel[11], email[25], l[100];
		int end_of_name;
		address addr;

		for(int i=0;i<n;i++) {
	    	fgets(l,100,fpin);
	    	trim(l);
	    	getEmail(l,email);
	    	end_of_name = getSDT(l,tel);
	    	getTen(l,name,end_of_name);
	    	strcpy(addr.name,name);
	    	strcpy(addr.tel,tel);
	    	strcpy(addr.email,email);
	    	insertAfterCurrent(addr);
		}

		printf("Da nap %d ban ghi vao danh sach\n", n);
	}
	fclose(fpin);
}

void readListFromText_Before(char *input){
	FILE *fpin = fopen(input,"r");
	
	int n = file_line(input) - 1;
	if(n!=-1){
		char name[20], tel[11], email[25], l[100];
		int end_of_name;
		address addr;

		for(int i=0;i<n;i++) {
	    	fgets(l,100,fpin);
	    	trim(l);
	    	getEmail(l,email);
	    	end_of_name = getSDT(l,tel);
	    	getTen(l,name,end_of_name);
	    	strcpy(addr.name,name);
	    	strcpy(addr.tel,tel);
	    	strcpy(addr.email,email);
	    	insertBeforeCurrent(addr);
		}
		printf("Da nap %d ban ghi vao danh sach\n", n);
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
	    	if(cc == 1 ) readListFromText_Before("input.txt");
	    	else readListFromText_After("input.txt");
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