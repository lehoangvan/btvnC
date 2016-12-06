typedef struct infess_t elementtype;

struct node {
    elementtype inf;
    struct node *next;
};

typedef struct node node;

node *root, *cur;

node* makeNewNode(elementtype inf){
    node* new = (node*) malloc(sizeof(node));
    new->inf=inf;
    new->next =NULL;
    return new;
}

void insertAtHead(elementtype inf){
    node* new = makeNewNode(inf);
    new->next = root;
    root = new;
    cur = root;
}

void insertAfterCurrent(elementtype inf){
    node *new = makeNewNode(inf);
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

void insertBeforeCurrent(elementtype e) {
    node * new = makeNewNode(e);
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
        node *tmp = root;
        while (tmp->next != cur && cur != NULL) tmp=tmp->next;

        new->next=cur;
        if (cur==root) {
            root = new; 
        }
        else tmp->next = new;
        cur = new;
    }
}

void traversingList(){
    node * p;
    for (p = root; p!= NULL; p = p->next) 
        displayNode(p);
}

void deleteHead(){
    if(root!=NULL) {
        node *tmp = root->next;
        free(root);
        root = tmp;
    }
}

void destroyList(){
    while(root!=NULL) deleteHead();
    printf("Danh sach da duoc giai phong\n");
}