#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


ElementType newProgram(Queue *queue){
	ElementType NullProgram;
	NullProgram.id = 0;
	NullProgram.memory = 0;
	strcpy(NullProgram.name,"\0");

	int id, memory;
	char name[30];
	printf("Nhap id: ");
	scanf("%d%*c", &id);

	Position p = queue->Front;
	while(p != NULL) {
		if(p->data.id == id) {
			printf("Id trung!\n" );
			return NullProgram;
		}
		p = p->next;
	}

	printf("Nhap ten chuong trinh: ");
	gets(name);
	printf("Nhap bo nho can su dung: ");
	scanf("%d%*c",&memory);
	ElementType e;
	e.id = id;
	strcpy(e.name, name);
	e.memory = memory;
	return e;
}

void displayType(ElementType program){

    printf("%-10d%-20s%-10d\n",program.id, program.name, program.memory);
};

void displayNode(Position p){
    if(p == NULL) {printf("Loi con tro NULL\n"); return; }
    ElementType tmp = p->data;
    displayType(tmp);
}


void traversingQueue(Queue *Q, int parallelprocess){
    Position p = Q->Front;
    int i=0;
    printf("Running\n\n");
    printf("STT\t%-10s%-20s%-10s\n","ID","NAME","MEMORY");
    for (int j=0;j<parallelprocess;j++) {
    	if(p == NULL) break;
        printf("%d\t", i++);
        displayNode(p);
        p = p->next;
    }

    printf("\n\nWaiting\n\n");
    printf("STT\t%-10s%-20s%-10s\n","ID","NAME","MEMORY");
    for (p; p!= NULL; p = p->next) {
        printf("%d\t", i++);
        displayNode(p);
    }
}

void menu(){
  printf("\n\nChuong trinh mo phong may tinh\n");
  printf("Author: Anh Khoa\n\n");
  printf("1. Them tien trinh\n");
  printf("2. Huy tien trinh\n");
  printf("3. Hien thi cac tien trinh\n");
  printf("4. Thoat\n");
}

int choose(){
  int n;
  do {
    printf("Nhap lua chon: ");
    if(scanf("%d",&n)==0) n=-1;
  } while(getchar()!='\n');
  return n;
}

int main(){
	int c, n, p, memory, parallelprocess;

	printf("Nhap dung luong ram: ");
	scanf("%d%*c", &memory);
	printf("Nhap so tien trinh toi da co the chay dong thoi: " );
	scanf("%d%*c", &parallelprocess);
	p = parallelprocess;
	Queue *queue  = newQueue();

	ElementType program;
	  do{
	    menu();
	    c = choose();
	    switch(c){
	    case 1:
	      	program = newProgram(queue);
	      	if(program.id != 0){
		      	if(parallelprocess > 0){
		      		enQueue(program,queue);
		      		parallelprocess--;
		      		memory -= program.memory;
		      	}
				else if(memory >= program.memory){
			    	enQueue(program,queue);
			    	memory -= program.memory;
			    }
		      	else printf("Bo nho khong du, khong the chay chuong trinh!\n");
	        }
	        else printf("Error!\n");
	    break;
	    case 2:
	    	parallelprocess++;
	      	memory += queue->Front->data.memory;
	      	deQueue(queue);	
      	break;
	    case 3:
	    	traversingQueue(queue, p);
	    	printf("\nBo nho con lai: %d\n", memory);
      	break;
	    case 4:
	      break;
	    default:
	      printf("Lua chon sai!\n\n");
	      break;
	    }
	  } while(c!= 4);
	return 0;
}