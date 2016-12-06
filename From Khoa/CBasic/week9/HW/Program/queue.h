typedef struct program{
	int id;
	char name[30];
	int memory;
} PROGRAM;

typedef PROGRAM ElementType;

struct Node{ 
	ElementType data;
	struct Node* next;
};

typedef struct Node Node; 

typedef Node* Position; 

typedef struct{ 
	Position Front, Rear;
} Queue;

Node* makeNewNode(ElementType data){
    Node* new = (Node*) malloc(sizeof(Node));
    if(new == NULL) {
        printf("No memory, cannot make new Node!\n");
        return NULL;
    }
    new->data=data;
    new->next = NULL;
    return new;
}

Queue* newQueue(){ 
	Queue *Q = malloc(sizeof(Queue));
	Q->Front = NULL; 
	Q->Rear = Q->Front;
	return Q;
}

int emptyQueue(Queue *Q){ 
	return (Q->Front == NULL); 
}

void enQueue(ElementType X, Queue *Q){ 
	Node *new = makeNewNode(X);
	if(Q->Rear == NULL){
		Q->Front = new;
		Q->Rear = Q->Front;
	} 
	else {
		Q->Rear->next = new;
		Q->Rear = new;
	}
}

void deQueue(Queue *Q){ 
	if (!emptyQueue(Q)){ 
		Position T; 
		T=Q->Front; 
		Q->Front=Q->Front->next;
		if(Q->Front == NULL) Q->Rear = NULL; 
		free(T); 
	} 
	else printf("Error: Queue is empty."); 
} 



