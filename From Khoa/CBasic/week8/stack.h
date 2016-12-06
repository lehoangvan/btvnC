struct data {
    int n;
};

typedef struct data elementtype;

struct node {
    elementtype inf;
    struct node *link;
};

typedef struct node node;

typedef struct stack
{
    node *top;
} STACK;

STACK* newStack(){
    STACK *stack = malloc(sizeof(STACK));
    if(stack == NULL) {
        printf("No memory, cannot make new stack!\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

node* makeNewNode(elementtype inf){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL) {
        printf("No memory, cannot make new node!\n");
        return NULL;
    }
    new->inf=inf;
    new->link = NULL;
    return new;
}

void push(STACK *stack, elementtype e){
    node *new = makeNewNode(e);
    if(stack->top == NULL) stack->top = new;
    else {
        new->link = stack->top;
        stack->top = new;
    }
}

elementtype pop(STACK *stack){
    elementtype e = stack->top->inf;
    if(stack->top == NULL) {
        printf("Error! The stack is empty cannot pop \n");
        exit(0);
    }
    node *tmp = stack->top;
    stack->top = stack->top->link;
    free(tmp);
    return e;
}

void displayType(elementtype e){

    printf("%d\n",e.n);
};

void displayNode(node* p){
    if (p==NULL){
        printf("Loi con tro NULL\n");
        return;
    }
    elementtype tmp = p->inf;
    displayType(tmp);
}

void traversingStack(STACK *stack){
    node * p;
    int i=0;
    printf("\n\nSTT\t%-20s%-10s%-10s%-15s\n","MODEL","MEMORY","SCREEN","PRICE");
    for (p = stack->top; p!= NULL; p = p->link) {
        printf("%d\t", i++);
        displayNode(p);
    }
}

void destroyStack(STACK *stack){
    while(stack->top != NULL) pop(stack);
    free(stack);
    printf("Danh sach da duoc giai phong\n");
}
