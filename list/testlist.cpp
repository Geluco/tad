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
	addItem (&lista, 69, 3);
	deleteItem (&lista, 5);
	deleteItem (&lista, MAX_N + 1);
	deleteItem (&lista,  1);

	//lista, modo [0 (update value of position) 1 (update first value to show)], number (to search), newItem (is the newValue), position (to update). 
	update (&lista, 0, 0, 19, 2); 
	update (&lista, 1, 110, 89, 0);
	update (&lista, 1, 89, 1, 0);
	std::cout << lastElement (lista) << "\n";
	for(int i = 0; i < lista.n; i++){	
	std::cout << returnItem (lista, i) <<"--- posicion --> " << i << " \n";
	}
	std::cout << "El valor 1 esta en la posicion: "<< searchItem(lista, 1);	
}
