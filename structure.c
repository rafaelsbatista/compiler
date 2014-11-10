#include "structure.h"

void addIdentificador(object *final, object *lista, object *novo){
	if(lista == 0){
		final = novo;
	}else{
		novo->pNext = lista;
		final = novo;
	}
}