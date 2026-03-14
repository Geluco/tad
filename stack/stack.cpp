#include "stack.hpp"
#include <stdlib.h>
#include <iostream>

int next (int position){
	position++;
	return position % MAX_N;
}

int previous (int position){
	position--;
	return (position + MAX_N) % MAX_N;
}

void createEmptyStack (stack *stack){	 
	stack -> n = 0;
}

bool isEmptyStack (stack stack){
	return stack.n == 0;
}

bool isFullStack (stack stack){
	return stack.n == MAX_N;

}

bool  push (stack *stack, int elemento){	
	if(!isFullStack(*stack)){
		stack  -> vector[stack -> n] = elemento;
		stack -> n = next(stack -> n);
		return true;
	}
	return false;
}

int pop (stack *stack){
	if(!isEmptyStack(*stack)){
		return (stack -> vector[previous(stack -> n)]);
	}
       return 0; 	
}


