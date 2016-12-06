#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BST.h"

int import(FILE *fpin, TREE *tree){
	int n;
	char tu[30];
	int id;
	word w;
	fscanf(fpin, "%d\n", &n);
	if(n < 0) {
		return -1;
	}

	for(int i=0; i<n; i++){
		if(feof(fpin)) {
			return -1;
		}
		fscanf(fpin, "%s %d\n", tu, &id);
		strcpy(w.tu,tu);
		w.id = id;
		insertToTree(tree,w);
	}
	fseek(fpin,0,SEEK_SET);
	return n;
}

void status(TREE *tree){
	TREENODE *p = tree->root;
	printData(p->left);
	printData(p->right);
	printf("\n");

	while(p != NULL){
		printData(p);
		p = p->left;
	}
	printf("\n");

	p = tree->root;

	while(p->right != NULL){
		p = p->right;
	}
	printData(p);
	printf("\n");
}

int getNum(char *s){
	int num = 0;
	for(int i=0; i < strlen(s); i++){
		num = num*10 + s[i] - '0';
	}
	return num;
}

TREENODE* searchAllNode(TREE *tree, TreeElementType e){
	if(isEmpty(tree)) {
		printf("Cay rong, khong the thuc hien tim kiem\n");
		return NULL;
	}
	else{
		TREENODE* p = tree->root;
		while(p != NULL){
			if(compare(e, p->data) > 0) 
				p=p->right;
			else if(compare(e, p->data) < 0) 
				p=p->left;
			else {
				printData(p);
				printData(p->left);
				printData(p->right);
				printf("\n");
				p=p->right;
			}
		}
	}
	return NULL;
}

void searchAllNodeById(TREENODE* n, int id) {
  if(n == NULL)
  	return;
  else {
    searchAllNodeById(n->left,id);
    if((n->data).id == id) {
  		printData(n);
		printf("\n");
  	}
    searchAllNodeById(n->right,id);
  }
}

void searchAllNodeByTu(TREENODE* n, char *tu) {
  if(n == NULL)
  	return;
  else {
    searchAllNodeByTu(n->left,tu);
    if(strcmp((n->data).tu,tu) == 0) {
  		printData(n);
		printf("\n");
  	}
    searchAllNodeByTu(n->right,tu);
  }
}

TREENODE* searchByTu(TREE *tree, char *tu){
	if(isEmpty(tree)) {
		printf("Cay rong, khong the thuc hien tim kiem\n");
		return NULL;
	}
	else{
		TREENODE* p = tree->root;
		while(p != NULL){
			if(strcmp(tu, (p->data).tu) > 0) 
				p=p->right;
			else if(strcmp(tu, (p->data).tu) < 0) 
				p=p->left;
			else 
				return p;
		}
	}
	return NULL;
}

void deleteNodeByTu(TREE *tree, char *tu){
	while(1) {
		TREENODE *delnode = searchByTu(tree,tu);

		if(delnode == NULL){
			return;
		}

		if(isLeaf(delnode)){
			TREENODE *parent = getParent(tree, delnode);
			if(parent->left == delnode) 
				parent->left = NULL;
			else 
				parent->right = NULL;
			free(delnode);
		}
		else if(delnode->right == NULL){
			if(delnode == tree->root){
				tree->root = delnode->left;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				if(parent->left == delnode) 
					parent->left = delnode->left;
				else 
					parent->right = delnode->left;
				free(delnode);
			}
		}
		else if(delnode->left == NULL ){
			if(delnode == tree->root){
				tree->root = delnode->right;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				if(parent->left == delnode) 
					parent->left = delnode->right;
				else 
					parent->right = delnode->right;
				free(delnode);
			}
		}
		else {
			if(delnode == tree->root){
				TREENODE *minchild = getMinChild(delnode);
				TREENODE *minchildparent = getParent(tree, minchild);

				minchildparent->left = minchild->right;

				tree->root = minchild;
				minchild->right = delnode->right;
				minchild->left = delnode->left;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				TREENODE *minchild = getMinChild(delnode);
				TREENODE *minchildparent = getParent(tree, minchild);

				minchildparent->left = minchild->right;

				if(parent->left == delnode) {
					parent->left = minchild;
					minchild->right = delnode->right;
					minchild->left = delnode->left;
				}
				else {
					parent->right = minchild;
					minchild->right = delnode->right;
					minchild->left = delnode->left;
				}
				free(delnode);
			}
		}
		printf("Xoa thanh cong!\n");
	}
}

void searchById(TREENODE* n, int id, TREENODE** p) {
  if(n == NULL)
  	return;
  else {
  	if((n->data).id == id) *p = n;
    searchById(n->left,id,p);
    searchById(n->right,id,p);
  }
}

void deleteNodeById(TREE *tree, int id){
	while(1) {
		TREENODE *delnode = NULL;
		searchById(tree->root,id,&delnode);

		if(delnode == NULL){
			return;
		}

		if(isLeaf(delnode)){
			TREENODE *parent = getParent(tree, delnode);
			if(parent->left == delnode) 
				parent->left = NULL;
			else 
				parent->right = NULL;
			free(delnode);
		}
		else if(delnode->right == NULL){
			if(delnode == tree->root){
				tree->root = delnode->left;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				if(parent->left == delnode) 
					parent->left = delnode->left;
				else 
					parent->right = delnode->left;
				free(delnode);
			}
		}
		else if(delnode->left == NULL ){
			if(delnode == tree->root){
				tree->root = delnode->right;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				if(parent->left == delnode) 
					parent->left = delnode->right;
				else 
					parent->right = delnode->right;
				free(delnode);
			}
		}
		else {
			if(delnode == tree->root){
				TREENODE *minchild = getMinChild(delnode);
				TREENODE *minchildparent = getParent(tree, minchild);

				minchildparent->left = minchild->right;

				tree->root = minchild;
				minchild->right = delnode->right;
				minchild->left = delnode->left;
				free(delnode);
			}
			else {
				TREENODE *parent = getParent(tree, delnode);
				TREENODE *minchild = getMinChild(delnode);
				TREENODE *minchildparent = getParent(tree, minchild);

				minchildparent->left = minchild->right;

				if(parent->left == delnode) {
					parent->left = minchild;
					minchild->right = delnode->right;
					minchild->left = delnode->left;
				}
				else {
					parent->right = minchild;
					minchild->right = delnode->right;
					minchild->left = delnode->left;
				}
				free(delnode);
			}
		}
		printf("Xoa thanh cong!\n");
	}
}

int imax;

void getNodeArr(TREENODE* n, TREENODE **nodearr){
	if(n == NULL)
		return;
	else {
		getNodeArr(n->left,nodearr);
		nodearr[imax++] = n;
		getNodeArr(n->right,nodearr);
	}
}

int main(int argc, char *argv[]){
	if(argc < 3) printf("Thao tac khong dung\n");
	else {
		char input[30], action[30];
		strcpy(input, argv[1]);
		FILE *fpin = fopen(input,"r");
		if(fpin == NULL) {
			printf("Khong tim thay file %s\n", input);
		}
		else {
			int n, maxn;
			TreeElementType search;
			char tu[30];
			int id;
			TREENODE *seach_result;

			TREE *tree = makeNewTree();

			n = import(fpin,tree);

			if(n == -1) {
				printf("Loi doc file!\n");
				return 0;
			}

			strcpy(action, argv[2]);
			if(strcmp(action,"status") == 0){
				if(argc == 3){
					status(tree);
				}
				else printf("Thao tac khong dung\n");
			}
			else if(strcmp(action,"search") == 0){
				if(argc == 7){
					strcpy(search.tu, argv[4]);
					search.id = getNum(argv[6]);
					seach_result = searchInTree(tree,search);
					if(seach_result == NULL) printf("NOT FOUND\n");
					else {
						searchAllNode(tree,search);
					}
				}
				else if(argc == 5) {
					if(strcmp(argv[3],"t") == 0){
						strcpy(tu,argv[4]);
						searchAllNodeByTu(tree->root,tu);
					}
					else if(strcmp(argv[3],"i") == 0){
						id = getNum(argv[4]);
						searchAllNodeById(tree->root,id);
					}
				}
			}
			else if(strcmp(action,"max") == 0){
				TREENODE **nodearr = malloc(n*sizeof(TREENODE*));
				getNodeArr(tree->root,nodearr);
				maxn = getNum(argv[3]);
				printData(nodearr[n-maxn]);
				printData(nodearr[n-maxn]->left);
				printData(nodearr[n-maxn]->right);
				printf("\n");
			}
			else if(strcmp(action,"delete") == 0){
				if(argc == 5){
					if(strcmp(argv[3],"t") == 0){
						strcpy(tu,argv[4]);
						deleteNodeByTu(tree,tu);
					}
					else if(strcmp(argv[3],"i") == 0){
						id = getNum(argv[4]);
						deleteNodeById(tree,id);
					}
					else printf("Thao tac khong dung\n");
				}
				else if(argc == 7){
					strcpy(search.tu, argv[4]);
					search.id = getNum(argv[6]);
					deleteNode(tree,search);
				}
				else printf("Thao tac khong dung\n");
				travesalTreeInorder(tree);
			}
			else
				printf("Thao tac khong dung\n");
		}
	}
	return 0;
}