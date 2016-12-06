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

typedef struct list
{
    node *root;
    node *cur;
} LIST;

LIST* newList(){
    LIST *list = malloc(sizeof(LIST));
    list->root = NULL;
    list->cur = list->root;
    return list;
}

node* makeNewNode(elementtype inf){
    node* new = (node*) malloc(sizeof(node));
    new->inf=inf;
    new->next =NULL;
    return new;
}

void insertAtHead(LIST *list, elementtype e){
    node* new = makeNewNode(e);
    new->next = list->root;
    list->root = new;
    list->cur = list->root;
}

void insertAfterCurrent(LIST *list, elementtype e){
    node *new = makeNewNode(e);
    if ( list->root == NULL ) {
        list->root = new;
        list->cur = list->root;
    } 
    else {
        new->next = list->cur->next;
        list->cur->next = new;
        list->cur = new;
    }
}

void insertBeforeCurrent(LIST *list, elementtype e) {
    node *new = makeNewNode(e);
    if (list->root == NULL) {
        list->root = new;
        list->cur = list->root;
    } 
    else if(list->cur == list->root){
        new->next = list->root;
        list->root = new;
        list->cur = list->root;
    }
    else {
        node *tmp = list->root;
        while (tmp->next != list->cur && list->cur != NULL) tmp=tmp->next;

        new->next=list->cur;

        if (list->cur==list->root) {
            list->root = new; 
        }
        else tmp->next = new;
        list->cur = new;
    }
}

void insertAtPosition(LIST *list, elementtype e, int p){

    if(p < 0) {
        printf("Vi tri khong hop le!\n");
    }
    else if (p == 0) {
        node* new = makeNewNode(e);
        new->next = list->root;
        list->root = new;
        printf("Them thanh cong!\n");
    }
    else {
        int i;
        node* new = makeNewNode(e);
        node *tmp = list->root;
        node *prev = NULL;
        for(i = 0; i < p; i++) {
            if(tmp == NULL) break;
            prev = tmp;
            tmp = tmp->next;
        }
        if(i == p){
            prev->next = new;
            new->next = tmp;
            list->cur = new;
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

void traversingList(LIST *list){
    node * p;
    int i=0;
    printf("\n\nSTT\t%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
    for (p = list->root; p!= NULL; p = p->next) {
        printf("%d\t", i++);
        displayNode(p);
    }
}

void deleteHead(LIST *list){
    if(list->root!=NULL) {
        node *tmp = list->root->next;
        free(list->root);
        if(list->cur == list->root) list->cur = tmp;
        list->root = tmp;
    }
}

void deleteCurrent(LIST *list){
    if(list->cur == list->root) {
        deleteHead(list);
    }
    else {
        node *tmp = list->root;
        while(tmp->next != list->cur){
            tmp = tmp->next;
        }
        tmp->next = list->cur->next;
        free(list->cur);
        list->cur = tmp;
    }
    printf("Xoa thanh cong\n");
}

void deleteAtPosition(LIST *list, int p){
    node *tmp = list->root;
    node *prev = NULL;
    if(p < 0) {
        printf("Vi tri khong hop le!\n");
    }
    else if (p == 0) {
        deleteHead(list);
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
            list->cur = list->root;
            printf("Xoa thanh cong\n"); 
        }
        else printf("Het danh sach! Xoa khong thanh cong\n");   
    }
}

void destroyList(LIST *list){
    while(list->root!=NULL) deleteHead(list);
    printf("Danh sach da duoc giai phong\n");
}

void reverseList(LIST *list){    
    if(list->root == NULL || list->root->next == NULL) return;
    node  *prev = NULL, *tmp;
    while(tmp != NULL){
        tmp = list->root->next;
        list->root->next = prev;
        prev = list->root;
        list->root = tmp;
    }
    list->root = prev;
    printf("List da duoc dao nguoc\n");
}

void devideList(LIST *list, LIST *list1, LIST *list2, int n1, int n2){
    node *p = list->root;
    for(int i=0;i<n1;i++){
        insertAfterCurrent(list2,p->inf);
        p = p->next;
    }
    for(int i=n1;i<n2;i++){
        insertAfterCurrent(list1,p->inf);
        p = p->next;
    }
    while(p!=NULL){
        insertAfterCurrent(list2,p->inf);
        p = p->next;
    }
}

void saveToFile(LIST *list){
    FILE *fpin = fopen("List_NokiaDB.dat","wb");
    node * p;
    for (p = list->root; p!= NULL; p = p->next) 
        fwrite(&p->inf,sizeof(elementtype),1,fpin);
    printf("Da luu danh sach vao file List_NokiaDB.dat\n");
    fclose(fpin);
}