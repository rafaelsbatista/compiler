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
		obj->pNext = constTable;
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
		obj->pNext = constTable;
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
		obj->pNext = constTable;
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
		obj->pNext = constTable;
		obj->sToken = constTable->sToken + 1;
		constTable = obj;
	}
	return constTable->sToken;
}

void printHeader(FILE *asm_file2, int varCount){
	fprintf(asm_file2, "%s", "\nEND FUNC");	
	fseek(asm_file2,0,SEEK_SET);
	pt_const consta = constTable;
	while(consta != 0){
		switch(consta->type){
			case INTEGER:
				fprintf(asm_file2, "%s %d\n", "CONST INT",consta->intVal);
				break;
			case CHARACTER:
				fprintf(asm_file2, "%s %c\n", "CONST CHR",consta->charVal);
				break;
			case STRING:
				fprintf(asm_file2, "%s %s\n", "CONST STR",consta->stringVal);
				break;
			case BOOLEAN:
				fprintf(asm_file2, "%s %d\n", "CONST INT",consta->booleanVal);
				break;
		}
		consta = consta->pNext;
	}
	fprintf(asm_file2, "%s %d\n", "functionMain 0 1",varCount);
}