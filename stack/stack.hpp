#ifndef stack_hpp
#define stack_hpp
#include <stdbool.h>

#define MAX_N 64000

typedef struct stack{
	int n;
	int vector [MAX_N];
} stack;

void createEmptyStack (stack *stack);
bool isEmptyStack (stack stack);
bool isFullStack (stack stack);
bool push (stack *stack, int elemento);
int pop (stack *stack);


#endif
