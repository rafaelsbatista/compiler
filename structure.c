#include "structure.h"

void addIdentificador(identificador *final, identificador *lista, identificador *novo){
	printf("ROPE\n");
	if(lista == 0){
		printf("ROPE2\n");
		final = novo;
		printf("ROPE3\n");
	}else{
		novo->pNext = lista;
		final = novo;
	}
}