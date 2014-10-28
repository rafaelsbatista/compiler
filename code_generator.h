#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <stdio.h>
#include "structure.h"
	FILE* asm_file;
	
void initCodeFile();

void finalizeCodeFile();

void ifStatement(identificador *idt1,identificador *idt2);
#endif