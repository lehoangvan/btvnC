//http://smu.covertbay.com/course-material/c-stacks
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#define MAX 50
typedef int Eltype;
typedef struct StackRec{
  Eltype storage [MAX];
  int top;
} StackType;
//typedef struct StackRec StackType;

int is_empty(StackType *s)
{
  if(s->top==-1) return -1; // Stack is empty
  return 0; //Stack is not empty
}

int is_full(StackType *s)
{
  if(s->top == MAX-1 ) return 1; //Stack is full
  return 0;//Stack is not full
}

void push(Eltype a, StackType *s)
{
  if(is_full(s))
    {
      printf("Stack Overflow\n");
      return;
    }
  s->top++;
  s->storage[s->top]=a;
}

int pop(StackType *s)
{
  Eltype a;
  if(is_empty(s))
    {
      printf("Stack Underflow\n");
      return 0;
    }
  a=s->storage[s->top];
  s->top--;
  return a;
}

void display(StackType s)
{
  int i;
  if(is_empty(&s)) // Chu i la ky tu dac biet, nhin ky se thay
    {
      printf("Stack is empty. Hence, no content to display.\n");
      return;
    }
  printf("Display stack content:\n");
  for(i=0;i<=s.top;i++)
    {
      printf("%d",s.storage[i]);
    }
}


      
