#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include "scope_structure.h"
typedef struct identificador
{
	char id[200];
	int sToken;
	struct object *obj;
	struct identificador *pNext;
}identificador;


void addIdentificador(object *final, object *lista, object *novo);

#endif