#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct treeNode{
  int x; //node's data ~ DataType Item;
  Tnode *left;
  Tnode *right;
}treeNode;

void freeTree( treeNode *tree);
void printPreorder(treeNode *tree);
void printInorder(treeNode *tree);
void printPostorder(treeNode *tree);

void freeTree( treeNode *tree)
{
  if(tree==NULL) return;
  freeTree(tree->left);
  freeTree(tree->right);
  free(tree);
  return;
}

void printPreorder(treeNode *tree)
{
  if(tree!=NULL){
    printf("%s\n",tree->x);
    printPreorder(tree->left);
    printfPreorder(tree->right);
  }
}
 
void printInorder(treeNode *tree)
{
  if(tree!=NULL)
    {
      printInorder(tree->left);
      printf("%s\n",tree->x);
      printInorder(tree->right);
    }
}

void printPostorder(treeNode *tree)
{
  if(tree!=NULL)
    {
      printfPostorder(tree->left);
      printfPostorder(tree->right);
      printf("%s\n",tree->x);
    }
}
