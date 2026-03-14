#ifndef list_hpp
#define list_hpp
#include <stdbool.h>

#define MAX_N 64000

typedef struct list{
	int n;
	int vectorTF [MAX_N];//vector para comprobar si ha sido creada cierta posicion.
	int vector [MAX_N];
} list;

void createEmptyList (list *list);
bool isEmptyList (list list);
bool isFullList (list list);
int firstElement (list list);
int lastElement (list list);
bool addItem (list *list, int item, int position);
int deleteItem (list *list, int item);
int update (list *list);
int returnItem (list list, int position);
int searchItem(list list, int item);




#endif
