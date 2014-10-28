#ifndef SCOPE_STRUCTURE_H
#define SCOPE_STRUCTURE_H

#include <stdlib.h>
#include "attribute.h"

#define MAX_NEST_LEVEL 20

typedef enum { NO_KIND_DEF_ = -1, VAR_, SCALAR_TYPE_, UNIVERSAL_} t_kind;

typedef struct object
{
	int nName;
	struct object *pNext;
	t_kind eKind;
	struct attr *attribute;
	union{
		struct{
			struct object *pType;
		}Var;
	}_;
} object, *pobject;

static pobject SymbolTable[MAX_NEST_LEVEL];
static pobject SymbolTableLast[MAX_NEST_LEVEL];
static int nCurrentLevel = -1;

int newBlock();

int endBlock();

pobject Define (int aName);

pobject Search(int aName);

pobject Find (int aName);

pobject createType(int vType);

int CheckTypes(pobject t1, pobject t2);
int CheckType(pobject t1, int t2);
#endif