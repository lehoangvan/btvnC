struct node_int {
    int data;
    struct node_int *link;
};

typedef struct node_int node_int;

typedef struct STACK
{
    node_int *top;
} STACK;

STACK* newStack() {
    STACK *stack = malloc(sizeof(STACK));
    if(stack == NULL) {
        printf("No memory, cannot make new stack!\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

node_int* makeNewNode(int data){
    node_int* new = (node_int*) malloc(sizeof(node_int));
    if(new == NULL) {
        printf("No memory, cannot make new node_int!\n");
        return NULL;
    }
    new->data=data;
    new->link = NULL;
    return new;
}

int isEmpty(STACK *stack){
    return stack->top == NULL;
}

void push(STACK *stack, int e){
    node_int *new = makeNewNode(e);
    if(stack->top == NULL) stack->top = new;
    else {
        new->link = stack->top;
        stack->top = new;
    }
}

int pop(STACK *stack){
    if(stack->top == NULL) {
        return 0;
    }

    int e = stack->top->data;
    node_int *tmp = stack->top;
    stack->top = stack->top->link;
    free(tmp);
    return e;
}

int top(STACK *stack){    
    if(stack->top == NULL) {
        return 0;
    }
    int e = stack->top->data;
    node_int *tmp = stack->top;
    return e;
}

void displayNode(node_int* p){
    if (p==NULL){
        printf("Loi con tro NULL\n");
        return;
    }
    int tmp = p->data;
    printf("%d ", tmp);
}

void traversingStack(STACK *stack){
    node_int * p;
    for (p = stack->top; p!= NULL; p = p->link) {
        displayNode(p);
    }
}

void destroyStack(STACK *stack){
    while(stack->top != NULL) pop(stack);
    free(stack);
    printf("Danh sach da duoc giai phong\n");
}
