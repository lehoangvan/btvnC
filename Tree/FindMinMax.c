//find min max <=> find most left most right
#include"check.h"
#include<stdio.h>

struct treeNode{
  int x;
  struct treeNode *left;
  struct treeNode *right;
};

typedef struct treeNode treeNode;
treeNode *ROOT;

treeNode *makeNewNode(treeNode *root) 
{
  treeNode *newnode=(treeNode*)malloc(sizeof(treeNode));
  int a;
  a=scanInt("Nhap so");
  newnode->x=a;
  newnode->left=NULL;
  newnode->right=NULL;
  treeNode *q; q=root;
  if(root==NULL) root=newnode;
  else 
    {
      while(q!=NULL){
	if(a<q->x){if(q->left==NULL){q->left=newnode; break;} q=q->left;}
	if(a>q->x){if(q->right==NULL){q->right=newnode; break;} q=q->right;}
	if(a==q->x){printf("Da co so vua nhap trong cay.\n"); break;}
	};
    }
  return root;  
}

int findmostleft(treeNode *root) //Min
{
  treeNode *q; q=root;
  while(q->left!=NULL) q=q->left;
  return q->x;
}
int findmostright(treeNode *root) //Max
{
  treeNode *q; q=root;
  while(q->right!=NULL) q=q->right;
  return q->x;
}

void freeTree( treeNode *root)
{
  if(root==NULL) return;
  freeTree(root->left);
  freeTree(root->right);
  free((void*)root);
  return;
}

void printmenu()
{
  printf("===========menu===========\n");
  printf("1, Nhap them so\n2, Tim so nho nhat\n3, Tim so lon nhat\n4, Thoat va giai phong cay\n");
}
int main(){
  int n;
  int i=0;
  n=scanInt("Nhap cay, ban muon cay co bao nhieu node?");
  while(n-i){ROOT=makeNewNode(ROOT); i++;};
  int option;
  do{
    printmenu();
    option=scanInt("Lua chon ");
    switch(option){
    case 1: ROOT=makeNewNode(ROOT);
      break;
    case 2: printf("So nho nhat la %d\n",findmostleft(ROOT));
      break;
    case 3: printf("So lon nhat la %d\n", findmostright(ROOT));
      break;
    case 4: printf("Thoat va giai phong cay\n");
      break;
    default: printf("Chon mot trong 3 options tren\n");
      break;
    }
  }while(option!=4); 

  return 0;
}
