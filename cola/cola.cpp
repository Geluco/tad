#include "cola.hpp"
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

void createEmptyCola (cola *cola){	
	cola -> n = MAX_N - 1; 
	cola -> first = 0;
}

bool isEmptyCola (cola cola){
	return previous(cola.first) == cola.n;
}

bool isFullCola (cola cola){
	return next(next(cola.n)) == cola.first;

}

bool enqueue (cola *cola, int elemento){	
	if(!isFullCola(*cola)){
		cola -> n = next(cola -> n);
		cola -> vector[cola -> n] = elemento;
		return true;
	}
	return false;
}

int dequeueFirst (cola *cola){
	if(!isEmptyCola(*cola)){
		cola -> first = next(cola -> first);
		return (cola -> vector[previous(cola -> first)]);
	}
       return 0; 	
}

int dequeueLast (cola *cola){
	if(!isEmptyCola(*cola)){
		cola -> n = previous(cola -> n);
		return (cola -> vector[next(cola -> n)]);
	}
	return 0;
}
