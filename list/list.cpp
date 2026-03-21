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
        	list->vector[i] = 0;   // Dato a cero
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

void vectorMovement(list *list, int position){//mueve las posiciones del vector a la derecha
	for(int i = list -> n; i > position; i--){	
		list -> vector[i] = list -> vector[i - 1];
		list -> vectorTF[i] = list -> vectorTF[i - 1];
	}
	list -> n = next(list -> n);
}

void vectorMovementBack(list *list, int position) {//mueve las posiciones hacia la izquierda
  	for (int i = position; i < list->n - 1; i++) {
        	list->vector[i] = list->vector[i + 1];
        	list->vectorTF[i] = list->vectorTF[i + 1];
	}
	list -> n = previous(list -> n);
}

void lastNumberCheck (list *list){//comprueba que la posicion anterior a la ultima tenga un valor valido, sino, retrcede uno
	while (true){
		if(list -> vectorTF[previous(list -> n)] == 0){
			list -> n = previous(list -> n);
		}else{break;}
	}

}

bool addItem (list *list, int item, int position){
	if(!isFullList(*list)){
		if(position > MAX_N){//añadir al final
		      	list -> vectorTF[list -> n] = 1;//cambiamos el estado de esta posicion a que esta ocupada por un valor	
			list -> vector[list -> n] = item;
			list -> n = next(list -> n);
			lastNumberCheck(list);
			std::cout << list -> n << " <-- valor de n \n";//debug
			return true;

		}else if(position < 0){//añadir al inicio
				       
			if(list -> vectorTF[0] == 1){//si esta coupado
				vectorMovement(list, 0);	
			}
			list -> vectorTF[0] = 1;//cambiamos el esta a ocupado
			list -> vector[0] = item;
			lastNumberCheck(list);
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
			lastNumberCheck(list);
			std::cout << list -> n << " <-- valor de n \n";
			return true;
		}
	}
	return false;

}

int returnItem (list list, int position){	
	return list.vector[position];
}

int deleteItem (list *list, int position) { 
	if(!isFullList(*list)){
		if(position > MAX_N){//eliminar al final
			if(list -> vectorTF[previous(list -> n)] == 1){//si esta ocupado
				list -> vectorTF[previous(list -> n)] = 0;//cambiamos el estado de esta posicion a que no esta ocupada por un valor	
				list -> vector[previous(list -> n)] = 0;//eliminamos el valor que queremos
				vectorMovementBack(list, position);
				lastNumberCheck(list);
				std::cout << list -> n << " <-- valor de n \n";//debug
				return true;
			}else{//si no esta ocupado no hace nada
				return false;
			}

		}else if(position < 0){//eliminar al principio

			if(list -> vectorTF[0] == 1){//si esta ocupado
				list -> vectorTF[0] = 0;//cambiamos el esta a ocupado
				list -> vector[0] = 0;
				vectorMovementBack(list, 0);
				lastNumberCheck(list);
				return true;	

			}else{//si no esta ocupado simplemente aumentamos la posicion del ultimo valor
				return false;

			
			std::cout << list -> n << " <-- valor de n \n";
			return true;
			}
		}else{//eliminar en una posicion especifica

			if(list -> n < position){//si la posicion esta por delante del ultimo valor añadido, este sera el nuevo ultimo valor
				return false;
			}
			if(list -> vectorTF[position] == 1){//si esta ocupado
				list -> vector[position] = 0;
				list -> vectorTF[position] = 0;
				vectorMovementBack(list, position);
				lastNumberCheck(list);
				return true;

			}else{
				return false;
			}			
			std::cout << list -> n << " <-- valor de n \n";
			return true;		
		}
			
	}
	return 0; 
}

int update (list *list, int mode, int number, int newItem, int position) {
	// mode if 0 --> change the position by new item
	// mode if 1 --> change the first number x to show
	if(mode == 1){
		for(int k = 0; k < MAX_N; k++){
			if(list -> vector[k] == number && list -> vectorTF[k] == 1){
				list -> vector[k] = newItem; 
				return true;
			}
		}
		return false;
	}else if(mode == 0 && position >= 0 && position < MAX_N){
		list -> vector[position] = newItem;
		list -> vectorTF[position] = 1;
	}

	return 0; 
}
int searchItem(list list, int item) { 
	for(int k = 0; k < MAX_N; k++){
		if(list.vector[k] == item && list.vectorTF[k] == 1){
			return k;
		}	
	}
	return 0; 
}
