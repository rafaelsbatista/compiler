#include "attribute.h"
#include <stdio.h>

int newLabel(){
	return labelNo++;
}

int addCharConst(char c){
	pt_const obj = (pt_const)malloc(sizeof(t_const));
	
	obj->type = CHARACTER;
	obj->charVal = c;
	obj->pNext = NULL;
	
	if(constTable == NULL){
		obj->sToken = 0;
		constTable = obj;
	}
	else{
		constTable->pNext = obj;
		obj->sToken = constTable->sToken + 1;
		constTable = obj;
	}
	return constTable->sToken;
}


int addIntConst(int n){
	pt_const obj = (pt_const)malloc(sizeof(t_const));
	
	obj->type = INTEGER;
	obj->intVal = n;
	obj->pNext = NULL;
	
	if(constTable == NULL){
		obj->sToken = 0;
		constTable = obj;
	}
	else{
		constTable->pNext = obj;
		obj->sToken = constTable->sToken + 1;
		constTable = obj;
	}
	return constTable->sToken;
}

int addStringConst(char *s){
	pt_const obj = (pt_const)malloc(sizeof(t_const));
	
	obj->type = STRING;
	obj->stringVal = s;
	obj->pNext = NULL;
	
	if(constTable == NULL){
		obj->sToken = 0;
		constTable = obj;
	}
	else{
		constTable->pNext = obj;
		obj->sToken = constTable->sToken + 1;
		constTable = obj;
	}
	return constTable->sToken;
}

int addBooleanConst(int b){
	pt_const obj = (pt_const)malloc(sizeof(t_const));
	
	obj->type = STRING;
	obj->booleanVal = b;
	obj->pNext = NULL;
	
	if(constTable == NULL){
		obj->sToken = 0;
		constTable = obj;
	}
	else{
		constTable->pNext = obj;
		obj->sToken = constTable->sToken + 1;
		constTable = obj;
	}
	return constTable->sToken;
}