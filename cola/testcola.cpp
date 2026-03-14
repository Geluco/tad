#include "cola.hpp"
#include <iostream>

int main (){
	cola queue;
	createEmptyCola(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	std::cout <<  dequeueFirst(&queue) << "\n";
	std::cout << dequeueLast(&queue) << "\n";

	enqueue(&queue, 4);
	enqueue(&queue, 5);
	enqueue(&queue, 6);
	std::cout << dequeueFirst(&queue) << "\n";
	std::cout << dequeueLast(&queue) << "\n";

	enqueue(&queue, 7);
	enqueue(&queue, 8);
	enqueue(&queue, 9);
	std::cout << dequeueFirst(&queue) << "\n";
	std::cout << dequeueLast(&queue) << "\n" ;
}
