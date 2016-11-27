#include<stdio.h>
#include<time.h>
#include"check.h"

struct treeNode{
  int x;
  struct treeNode *left;
  struct treeNode *right;
};

typedef struct treeNode treeNode;
treeNode *ROOT;

int depth(treeNode *root)//function computes the depth of a tree
{
  if(root==NULL) return 0;
  int ld = depth(root->left);
  int rd = depth(root->right);
  return 1+(ld>rd?ld:rd);
}

treeNode *makeNewNode(treeNode *root) 
{
  treeNode *newnode=(treeNode*)malloc(sizeof(treeNode));
  int a;
  a=rand();
  newnode->x=a;
  newnode->left=NULL;
  newnode->right=NULL;
  treeNode *q; q=root;
  if(root==NULL)root=newnode;
  else 
    {
      while(q!=NULL){
	if(a<q->x){if(q->left==NULL){q->left=newnode; break;} q=q->left;}
	if(a>q->x){if(q->right==NULL){q->right=newnode; break;} q=q->right;}
	if(a==q->x)break;
	};
    }
  return root;  
}

void freeTree( treeNode *root)
{
  if(root==NULL) return;
  freeTree(root->left);
  freeTree(root->right);
  free((void*)root);
  return;
}

void seek(treeNode *root)
{
  int a; a=scanInt("Ban muon tim kiem so ");
  int count=0;
  treeNode*q; q=root;
  do{
    if(a<q->x){q=q->left; count++;}
    if(a>q->x){q=q->right;count++;}
    if(a==q->x){printf("Tim thanh cong so can tim\n"); count++; break;} //pointer dang tro vao node chua x=a <=> khac NULL
  }while(q!=NULL); //neu ko tim dc, vong lap chay het den khi q=NULL
  if(q==NULL) printf("Khong co so can tim trong cay.\n");
  printf("So lan so sanh la %d\n",count+1);
}

void printmenu()
{
  printf("=============menu=============\n");
  printf("1, In ra chieu cao cua cay\n2, Giai phong bo nho va tao lai bo so lieu\n3, Tim kiem va in ra so phep so sanh\n4, Giai phong cay va thoat\n\n");
}

void createTree(treeNode *root)
{
  int i=0;
  while(1000000-i) //for(i=0;i<1000000;i++)
    {
      root=makeNewNode(root);
      i++;
    }
  printf("Chuong trinh vua tu dong tao 1000000 so ngau nhien va sap xep vao cay nhi phan tim kiem.\n");
}
int main(){
  createTree(ROOT);
  int option;
  do{
    printmenu();
    option=scanInt("Option");
    switch(option){
    case 1: printf("Chieu cao cua cay la %d\n",depth(ROOT));
      break;
    case 2: printf("Giai phong bo nho...\n"); freeTree(ROOT);
      printf("Tao cay moi cung bo so moi\n"); createTree(ROOT);
      break;
    case 3: seek(ROOT);
      break;
    case 4: freeTree(ROOT); printf("Giai phong cay va thoat\n");
      break;
    }
  }while(option!=4);

  return 0;
}
