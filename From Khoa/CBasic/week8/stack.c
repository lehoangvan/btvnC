#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  elementtype e;
  e.n = 2;
  STACK *s = newStack();
  push(s, e);
  printf("%d\n",pop(s).n);
  destroyStack(s);
  return 0;
}
