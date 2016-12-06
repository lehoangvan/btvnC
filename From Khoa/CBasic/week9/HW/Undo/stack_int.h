struct node_int {
    int data;
    struct node_int *link;
};

typedef struct node_int node_int;

typedef struct stack_int
{
    node_int *top;
} STACK_INT;

STACK_INT* newStackInt(){
    STACK_INT *stack = malloc(sizeof(STACK_INT));
    if(stack == NULL) {
        printf("No memory, cannot make new stack!\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

node_int* makeNewNodeInt(int data){
    node_int* new = (node_int*) malloc(sizeof(node_int));
    if(new == NULL) {
        printf("No memory, cannot make new node_int!\n");
        return NULL;
    }
    new->data=data;
    new->link = NULL;
    return new;
}

void pushInt(STACK_INT *stack, int e){
    node_int *new = makeNewNodeInt(e);
    if(stack->top == NULL) stack->top = new;
    else {
        new->link = stack->top;
        stack->top = new;
    }
}

int popInt(STACK_INT *stack){
    if(stack->top == NULL) {
        printf("Error! The stack is empty cannot pop \n");
        exit(0);
    }

    int e = stack->top->data;
    node_int *tmp = stack->top;
    stack->top = stack->top->link;
    free(tmp);
    return e;
}

int topInt(STACK_INT *stack){    
    if(stack->top == NULL) {
        printf("Error! The stack is empty cannot get top \n");
        exit(0);
    }
    int e = stack->top->data;
    node_int *tmp = stack->top;
    return e;
}

void displayNodeInt(node_int* p){
    if (p==NULL){
        printf("Loi con tro NULL\n");
        return;
    }
    int tmp = p->data;
    printf("%d ", tmp);
}

void traversingStackInt(STACK_INT *stack){
    node_int * p;
    for (p = stack->top; p!= NULL; p = p->link) {
        displayNodeInt(p);
    }
}

void destroyStackInt(STACK_INT *stack){
    while(stack->top != NULL) popInt(stack);
    free(stack);
    printf("Danh sach da duoc giai phong\n");
}
