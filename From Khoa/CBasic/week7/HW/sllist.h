struct NOKIA {
  char model[100];
  char memory[100];
  char screen[15];
  char price[15];
};

typedef struct NOKIA elementtype;

struct node {
    elementtype inf;
    struct node *next;
};

typedef struct node node;

node *root = NULL, *cur = NULL;

node* makeNewNode(elementtype inf){
    node* new = (node*) malloc(sizeof(node));
    new->inf=inf;
    new->next =NULL;
    return new;
}

void insertAtHead(elementtype e){
    node* new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
}

void insertAfterCurrent(elementtype e){
    node *new = makeNewNode(e);
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
    node *new = makeNewNode(e);
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

void insertAtPosition(elementtype e, int p){
    node *tmp = root;
    node *prev = NULL;
    node* new = makeNewNode(e);

    if(p < 0) {
        printf("Vi tri khong hop le!\n");
    }
    else if (p == 0) {
        new->next = root;
        root = new;
        printf("Them thanh cong!\n");
    }
    else {
        int i;
        for(i = 0; i < p; i++) {
            if(tmp == NULL) break;
            prev = tmp;
            tmp = tmp->next;
        }
        if(i == p){
            prev->next = new;
            new->next = tmp;
            cur = new;
            printf("Them thanh cong\n"); 
        }
        else printf("Het danh sach! Them khong thanh cong\n");
    }
}

void displayType(elementtype phone){

    printf("%-20s%-10s%-10s%-15s\n",phone.model,phone.memory,phone.screen,phone.price);
};

void displayNode(node* p){
    if (p==NULL){printf("Loi con tro NULL\n"); return; }
    elementtype tmp = p->inf;
    displayType(tmp);
}

void traversingList(){
    node * p;
    int i=0;
    for (p = root; p!= NULL; p = p->next) {
        printf("%d\t", i++);
        displayNode(p);
    }
}

void deleteHead(){
    if(root!=NULL) {
        node *tmp = root->next;
        free(root);
        if(cur == root) cur = tmp;
        root = tmp;
    }
}

void deleteCurrent(){
    if(cur == root) {
        deleteHead();
    }
    else {
        node *tmp = root;
        while(tmp->next != cur){
            tmp = tmp->next;
        }
        tmp->next = cur->next;
        free(cur);
        cur = tmp;
    }
    printf("Xoa thanh cong\n");
}

void deleteAtPosition(int p){
    node *tmp = root;
    node *prev = NULL;
    if(p < 0) {
        printf("Vi tri khong hop le!\n");
    }
    else if (p == 0) {
        deleteHead();
        printf("Xoa thanh cong!\n");
    }
    else {
        int i;
        for(i = 0; i < p; i++) {
            if(tmp->next == NULL) break;
            prev = tmp;
            tmp = tmp->next;
        }
        if(i == p){
            prev->next = tmp->next;
            free(tmp);
            cur = root;
            printf("Xoa thanh cong\n"); 
        }
        else printf("Het danh sach! Xoa khong thanh cong\n");   
    }
}

void destroyList(){
    while(root!=NULL) deleteHead();
    printf("Danh sach da duoc giai phong\n");
}

void reverseList(){    
    if(root == NULL || root->next == NULL) return;
    node  *prev = NULL, *tmp;
    while(tmp != NULL){
        tmp = root->next;
        root->next = prev;
        prev = root;
        root = tmp;
    }
    root = prev;
    printf("List da duoc dao nguoc\n");
}

void saveToFile(){
    FILE *fpin = fopen("List_NokiaDB.dat","wb");
    node * p;
    for (p = root; p!= NULL; p = p->next) 
        fwrite(&p->inf,sizeof(elementtype),1,fpin);
    printf("Da luu danh sach vao file List_NokiaDB.dat\n");
    fclose(fpin);
}