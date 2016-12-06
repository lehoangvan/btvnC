typedef struct {
	char tu[30];
	int id;
} word;

typedef word TreeElementType;

struct treenode {
  TreeElementType data;
  int rank;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode TREENODE;

int compare(TreeElementType e1, TreeElementType e2){
	if(strcmp(e1.tu,e2.tu) > 0 || (strcmp(e1.tu,e2.tu) == 0 && e1.id > e2.id)) return 1;
	else if(strcmp(e1.tu,e2.tu) == 0 && e1.id == e2.id) return 0;
	else return -1;
}

typedef struct {
	TREENODE *root;
} TREE;

//cac thao tac tren cay
TREE* makeNewTree(); //khoi tao cay moi
int isEmpty(TREE*); //kiem tra cay co rong khong ( rong return 1)
int getTreeHeight(TREE*); //lay chieu cao cua cay
int insertToTree(TREE*, TreeElementType); //them phan tu
TREENODE* searchInTree(TREE*, TreeElementType); //tim kiem
void deleteNode(TREE*, TreeElementType); //xoa nut
void destroyTree(TREE*); //giai phong cay
void travesalTreePreorder(TREE*); //duyet cay theo chieu sau thu tu truoc
void travesalTreeInorder(TREE*); //duyet cay theo chieu sau thu tu giua
void travesalTreePostorder(TREE*); //duyet cay theo chieu sau thu tu sau
void reverseTree(TREE*); //dao nguoc cay

//sua ham in o day
void printData(TREENODE *n){
  if(n==NULL) printf("[NULL] ");
  else printf("[%s,%d] ", (n->data).tu, (n->data).id);
}

TREENODE* makeNewTreeNode(TreeElementType e){
	TREENODE* new = malloc(sizeof(TREENODE));
	new->data = e;
	new->left = NULL;
	new->right = NULL;
	return new;
}

TREE* makeNewTree(){
	TREE* new = malloc(sizeof(TREE));
	new->root = NULL;
	return new;
}

int isEmpty(TREE *tree){
	return tree->root == NULL;
}

int isLeaf(TREENODE* n){
	if(n!=NULL)
		return (n->left == NULL) && (n->right == NULL);
	else return -1;
}

int height(TREENODE *root){
	if(root == NULL) {
		return 0;
	}
	else {
		int l = height(root->left);
		int r = height(root->right);
		if(l > r) {
			return l+1;
		}
		else { 
			return r+1;
		}
	}
}

int getTreeHeight(TREE *tree){
	return height(tree->root);
}

int insertToTree(TREE *tree, TreeElementType e){
	TREENODE *new = makeNewTreeNode(e);

	if(new == NULL) 
		return 0;

	if(isEmpty(tree)) {
		tree->root = new;
	}
	else{
		TREENODE* p = tree->root;
		while(1){
			if(compare(e, p->data) >= 0) {
				if(p->right == NULL){
					p->right = new;
					break;
				}
				else p=p->right;
			}
			else if(compare(e, p->data) < 0) {
				if(p->left == NULL){
					p->left = new;
					break;
				}
				else p=p->left;
			}
		}
		return 1;
	}
}

TREENODE* searchInTree(TREE *tree, TreeElementType e){
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
			else 
				return p;
			}
		}
	return NULL;
}

TREENODE* getParent(TREE *tree, TREENODE *n){	
	if(isEmpty(tree)) {
		printf("Cay rong, khong the thuc hien tim kiem\n");
		return NULL;
	}
	else if(n == tree->root){
		printf("Khong the lay cha cua nut goc!\n");
		return NULL;
	}
	else{
		TREENODE *parent, *p = tree->root;
		while(p != NULL){
			parent = p;
			if(compare(n->data, p->data) > 0) 
				p=p->right;
			
			else if(compare(n->data, p->data) < 0) 
				p=p->left;

			if(compare(n->data, p->data) == 0)
				return parent;
		}	
	}
}


TREENODE* getMinChild(TREENODE *root){
	if(root == NULL)
		return NULL;
	else {
		TREENODE *min = root;
		while(1){
			if(min->left == NULL) return min;
			min = min->left;
		}
	}
}

void deleteNode(TREE *tree, TreeElementType e){
	while(1) {
		TREENODE *delnode = searchInTree(tree,e);

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

void destroyNode(TREENODE* root){
  if(root == NULL)
    return;
  else {
    destroyNode(root->left);
    destroyNode(root->right);
    free(root);
  }
}

void destroyTree(TREE *tree){
  destroyNode(tree->root);
  free(tree);
  printf("Tree is destroyed\n");
}
void travesalNodePreorder(TREENODE* n) {
  if(n == NULL)
    return;
  else {      
  	printData(n); 
    travesalNodePreorder(n->left);
    travesalNodePreorder(n->right);
  }
}

void travesalTreePreorder(TREE *tree){
  travesalNodePreorder(tree->root);
  printf("\n");
}

void travesalNodeInorder(TREENODE* n) {
  if(n == NULL)
    return;
  else {       
    travesalNodeInorder(n->left);
    printData(n);
    travesalNodeInorder(n->right);
  }
}

void travesalTreeInorder(TREE *tree){
  travesalNodeInorder(tree->root);
  printf("\n");
}

void travesalNodePostorder(TREENODE* n) {
  if(n == NULL)
    return;
  else {       
    travesalNodePostorder(n->left);
    travesalNodePostorder(n->right);
    printData(n);
  }
}

void travesalTreePostorder(TREE *tree){
  travesalNodePostorder(tree->root);
  printf("\n");
}

void reverse(TREENODE* root){
	if(root==NULL)
		return;
	else {
		reverse(root->left);
		reverse(root->right);
		TREENODE *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

void reverseTree(TREE* tree){
	reverse(tree->root);
}