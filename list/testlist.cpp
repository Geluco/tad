#include "list.hpp"
#include <iostream>

int main (){
	list lista;
	createEmptyList (&lista);

	addItem (&lista, 11, MAX_N + 1);
	addItem (&lista, 2, 4);
	addItem (&lista, 110, MAX_N + 1);
	addItem (&lista, 40, -1);
	addItem (&lista, 40, MAX_N + 1);
	deleteItem (&lista, 5);
	deleteItem (&lista, MAX_N + 1);
	deleteItem (&lista,  1);
	std::cout << lastElement (lista) << "\n";
	for(int i = 0; i < lista.n; i++){	
	std::cout << returnItem (lista, i) <<"--- posicion --> " << i << " \n";
	}
	std::cout << lista.n; 
	
}
