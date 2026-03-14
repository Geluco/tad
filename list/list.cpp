#include "list.hpp"
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

void createEmptyList (list *list){//iniciamos los parametros
	list -> n = 0;
	for(int i = 0; i < MAX_N; i++){
		list -> vectorTF[i] = 0;
	}
}

bool isEmptyList (list list){
	return list.n == 0;
}

bool isFullList (list list){
 	return list.n == MAX_N;
}

int firstElement (list list){
	return list.vector[0];
}

int lastElement (list list){
	return list.vector[list.n];
}

int vectorMovement(list *list, int position){//mueve las posiciones del vector
	for(int i = list -> n; i > position; i--){	
		list -> vector[i] = list -> vector[i - 1];
		list -> vectorTF[i] = list -> vectorTF[i - 1];
	}
	list -> n = next(list -> n);
	return true;
}

bool addItem (list *list, int item, int position){
	if(!isFullList (*list)){
		if(position > MAX_N){//añadir al final

		      	list -> vectorTF[list -> n] = 1;//cambiamos el estado de esta posicion a que esta ocupada por un valor	
			list -> vector[list -> n] = item;
			list -> n = next(list -> n);
			std::cout << list -> n << " <-- valor de n \n";//debug
			return true;

		}else if(position < 0){//añadir al inicio
				       
			if(list -> vectorTF[0] == 1){//si esta coupado
				vectorMovement(list, 0);	
			}
			list -> vectorTF[0] = 1;//cambiamos el esta a ocupado
			list -> vector[0] = item;
			std::cout << list -> n << " <-- valor de n \n";
			

			return true;

		}else{//añadir en una posicion en especifico
		      
			if(list -> n < position){//si la posicion esta por delante del ultimo valor añadido, este sera el nuevo ultimo valor
				list -> n = position;
			}
			if(list -> vectorTF[position] == 1){//si esta ocupado
				vectorMovement(list, position);

			}else{//si no esta ocupado simplemente aumentamos la posicion del ultimo valor
				if (position >= list->n) {
            				list -> n = next(position);
       				 }
			
			
			}

			list -> vectorTF[position] = 1;//pasara a esta ocupado
			list -> vector[position] = item;
			std::cout << list -> n << " <-- valor de n \n";
			return true;
		}
	}
	return false;

}

int returnItem (list list, int position){	
	return list.vector[position];
}
