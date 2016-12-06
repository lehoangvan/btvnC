struct node_str {
    char *data;
    struct node_str *link;
};

typedef struct node_str node_str;

typedef struct stack_str
{
    node_str *top;
} STACK_STR;

STACK_STR* newStackStr(){
    STACK_STR *stack = malloc(sizeof(STACK_STR));
    if(stack == NULL) {
        printf("No memory, cannot make new stack!\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

node_str* makeNewNodeStr(char *data){
    node_str* new = (node_str*) malloc(sizeof(node_str));
    if(new == NULL) {
        printf("No memory, cannot make new node_str!\n");
        return NULL;
    }
    new->data = data;
    new->link = NULL;
    return new;
}

void pushStr(STACK_STR *stack, char *e){
    node_str *new = makeNewNodeStr(e);
    if(stack->top == NULL) stack->top = new;
    else {
        new->link = stack->top;
        stack->top = new;
    }
}

char *popStr(STACK_STR *stack){
    if(stack->top == NULL) {
        printf("Error! The stack is empty cannot pop \n");
        exit(0);
    }
    char * e = stack->top->data;
    node_str *tmp = stack->top;
    stack->top = stack->top->link;
    free(tmp);
    return e;
}

char *topStr(STACK_STR *stack){    
    if(stack->top == NULL) {
        printf("Error! The stack is empty cannot get top \n");
        exit(0);
    }
    char * e = stack->top->data;
    node_str *tmp = stack->top;
    return e;
}

void displayNodeStr(node_str* p){
    if (p==NULL){
        printf("Loi con tro NULL\n");
        return;
    }
    char *tmp = p->data;
    printf("%s ", tmp);
}

void traversingStackStr(STACK_STR *stack){
    node_str *p;
    for (p = stack->top; p!= NULL; p = p->link) {
        displayNodeStr(p);
    }
}

void destroyStackStr(STACK_STR *stack){
    while(stack->top != NULL) popStr(stack);
    free(stack);
    printf("Danh sach da duoc giai phong\n");
}
