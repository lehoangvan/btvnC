#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct treeNode{
  char word[20]; //node's data ~ shoold be DataType Item;
  Tnode *left;
  Tnode *right;
}treeNode;

treeNode *makeTreeNode(char *word);
treeNode *RandomInsert(treeNode *tree, char* word);
void freeTree(treeNode *tree); //tree=root
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInorder(treeNode *tree);
int countNodes(treeNode *tree);
int depth(treeNode *tree);

treeNode *makeTreeNode(char *word)
{
  treeNode *newNode=NULL;
  newNode = (treeNode*)malloc(sizeof(treeNode));
  if(newNode==NULL){
    printf("Out of memory\n");
    exit(1);
  }
  else{
    newNode->left=NULL;
    newNode->right=NULL;
    strcpy(newNode->word,word);
  }
  return newNode;
}

treeNode *RandomInsert(treeNode *tree, char *word)
{
  treeNode *newNode, *p;
  newNode = makeTreeNode(word);
  if(tree==NULL) return newNode;
  if(rand()%2==0)
    {
      p=tree;
      while(p->left!=NULL)
	p=p->left;
      p->left=newNode;
      printf("Node %s is left child of %s \n",word,(*p).word);
    }
  else{
    p=tree;
    while(p->right!=NULL) p=p->right;
    p->right=newNode;
    printf("Node %s is right child of %s\n"word,(*p).word);
  }
  return tree;
}

int countNodes(treeNode *tree) //function counts number of nodes /////
{
  if(tree==NULL) return 0;
  else{
    int ld=countNodes(tree->left);
    int rd=countNodes(tree->right);
    return 1+ld+rd;
  }
}

int depth(treeNode *tree)//function computes the depth of a tree
{
  if(tree==NULL) return 0;
  int ld = depth(tree->left);
  int rd = depth(tree->right);
  //while(tree->left==NULL){tree=tree->left count++;}
  return 1+(ld>rd?ld:rd);
}

void freeTree( treeNode *tree)
{
  if(tree==NULL) return;
  freeTree(tree->left);
  freeTree(tree->right);
  free((void*)tree);
  return;
}

void printPreorder(treeNode *tree)
{
  if(tree!=NULL){
    printf("%s\n",tree->word);
    printPreorder(tree->left);
    printfPreorder(tree->right);
  }
}
 
void printInorder(treeNode *tree)
{
  if(tree!=NULL)
    {
      printInorder(tree->left);
      printf("%s\n",tree->word);
      printInorder(tree->right);
    }
}

void printPostorder(treeNode *tree)
{
  if(tree!=NULL)
    {
      printfPostorder(tree->left);
      printfPostorder(tree->right);
      printf("%s\n",tree->word);
    }
}

