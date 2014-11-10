#include "scope_structure.h"
#include <stdio.h>

int newBlock(){
	SymbolTable[++nCurrentLevel] = NULL;
	SymbolTableLast[nCurrentLevel] = NULL;
	return nCurrentLevel;
}

int endBlock(){
	return --nCurrentLevel;
}

pobject Define (int aName){
	pobject obj = (pobject)malloc(sizeof(object));
	
	obj->name = aName;
	obj->pNext = NULL;
	
	if(SymbolTable[nCurrentLevel] == NULL){
		SymbolTable[nCurrentLevel] = obj;
		SymbolTableLast[nCurrentLevel] = obj;
	}
	else{
		SymbolTableLast[nCurrentLevel]->pNext = obj;
		SymbolTableLast[nCurrentLevel] = obj;
	}
	return obj;
}

pobject Search(int aName){
	pobject obj = SymbolTable[nCurrentLevel];
	
	while(obj != 0){
		if(obj->name == aName)
		{
			break;
		}else{
			obj = obj->pNext;
		}
	}
	return obj;
}


pobject Find (int aName){
	int i;
	pobject obj = 0;
	for(i = nCurrentLevel ; i>= 0 ; i--){
		obj = SymbolTable[i];
		while(obj!=0){
			if(obj->name == aName) break;
			else obj = obj->pNext;
		}
		if(obj != 0) break;
	}
	return obj;
}

pobject createType(int vType){
	pobject p = (pobject)malloc(sizeof(object));
	pattr att = (pattr)malloc(sizeof(attr));
	att->type = vType;
	//p->attribute = att;
	return p;
}

int CheckTypes(pobject t1, pobject t2){
	if(t1 == t2) return 1;
	else if(t1 == t2->_.Var.pType) return 1;
	else if(t1->_.Var.pType == t2) return 1;
	else if(t1->_.Var.pType == t2->_.Var.pType) return 1;
	else if (t1->eKind == UNIVERSAL_ || t2->eKind == UNIVERSAL_) return 1;
	else return 0;
}


void addIdentificador(object *final, object *lista, object *novo){
	if(lista == 0){
		final = novo;
	}else{
		novo->pNext = lista;
		final = novo;
	}
}

/*int CheckType(pobject t1, int t2){
	
	if(t1 == t2){ printf("AAAAAAAA 1\n");return 1;}
	else if (t1->eKind == UNIVERSAL_){printf("AAAAAAAA 2\n"); return 1;}
	else {printf("AAAAAAAA 3\n");return 0;}
}*/