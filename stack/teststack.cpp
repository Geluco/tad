#include "stack.hpp"
#include <iostream>

int main (){
	stack queue;
	createEmptyStack(&queue);

	push(&queue, 1);
	push(&queue, 2);
	push(&queue, 3);
	std::cout <<  pop(&queue) << "\n";

	push(&queue, 4);
	push(&queue, 5);
	push(&queue, 6);
	std::cout << pop(&queue) << "\n";

	push(&queue, 7);
	push(&queue, 8);
	push(&queue, 9);
	std::cout << pop(&queue) << "\n";
}
