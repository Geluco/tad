#include "list.hpp"
#include <iostream>

int main (){
	list lista;
	createEmptyList (&lista);

	addItem (&lista, 11, MAX_N + 1);
	addItem (&lista, 2, 10);
	addItem (&lista, 3, 11);
	addItem (&lista, 4, -1);
	addItem (&lista, 5, 2);
	addItem (&lista, 6, 99999999);
	addItem (&lista, 7, -1);
	addItem (&lista, 67, -1);
	addItem (&lista, 99, 12);
	addItem (&lista, 100, 5);
	addItem (&lista, 110, MAX_N + 1);
	addItem (&lista, 230, MAX_N + 1);
	addItem (&lista, 17, 6);
	std::cout << firstElement (lista) << "\n";
	for(int i = 0; i < 22; i++){	
	std::cout << returnItem (lista, i) <<"--- posicion --> " << i << " \n";
	}
	
}
