#ifndef cola_hpp
#define cola_hpp
#include <stdbool.h>

#define MAX_N 64000

typedef struct cola{
	int n;
	int first;
	int vector [MAX_N];
} cola;

void createEmptyCola (cola *cola);
bool isEmptyCola (cola cola);
bool isFullCola (cola cola);
bool enqueue (cola *cola, int elemento);
int dequeueFirst (cola *cola);
int dequeueLast (cola *cola);

#endif
