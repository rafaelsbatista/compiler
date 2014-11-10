#include "code_generator.h"


void initCodeFile()
{
	asm_file = fopen("code.asm","w");

	fprintf(asm_file, "%s", "-- Pascalmm Ver. 1.0\n\n");
}

void finalizeCodeFile(void)
{
	fprintf(asm_file, "%s", "\n-- end");

	fclose(asm_file);

	printf("Codigo gerado com sucesso! [code.asm]\n");
}
