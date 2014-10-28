%{
	#include <stdio.h>
	#include <string.h>
	#include "structure.h"
	#include "scope_structure.h"
	#include "attribute.h"
	#include "code_generator.h"
	
	FILE* asm_file;
	
	extern int yylex( void );
	
	int yyerror( char *s){
		printf("bison-- error %s\n",s);
		return 0;
	}
	
%}
%union {
	int integer;
	int boolean;
	char character;
	struct identificador *id;
	char *string;
	int sToken;
	int label;
}


%left T_EQ
%left T_NEQ
%left T_LT
%left T_GT
%left T_LE
%left T_GE
%left T_EQEQ
%left T_AND
%left T_OR
%right T_TIMES T_DIVIDE
%right T_PLUS T_MINUS
%token T_COLON
%token T_SEMICOLON
%token T_COMMA
%token T_LEFTBRACES
%token T_RIGHTBRACES
%token T_NOT
%token <character> T_CHAR
%token <string> T_STRING
%token <id> T_ID
%token <integer> T_NUMBER

%token R_INTEGER
%token R_CHAR
%token R_BOOLEAN
%token R_STRING
%token R_VAR
%token R_THEN
%token R_IF
%token R_ELSE
%token R_WHILE 
%token R_DO
%token R_BREAK
%token <id> R_TRUE
%token <id> R_FALSE

%type <id> IDU IDD TP LI TRUE FALSE CHR NUM STR E F
%type <label> MT ME MW
%right R_THEN R_ELSE

%%

P: NBI LDE {endBlock();
			fprintf(asm_file, "%s", "\n-- end");

			fclose(asm_file);

			printf("Codigo gerado com sucesso! [code.asm]\n");
		   }
;

LDE:	LDE DE
|		DE		
;

DE:		DV
|		B
;

DV:		R_VAR LI T_COLON TP T_SEMICOLON{
			identificador *idt = $2;
			while(idt != 0 && idt->obj->eKind == NO_KIND_DEF_){
				idt->obj->eKind = VAR_;
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->type = $4->obj->attribute->type;
				idt = idt->pNext;
			}
		}
;

LI:		LI T_COMMA IDD {addIdentificador($$,$1,$3);}
|		IDD {
		//printf("LI\n");
		addIdentificador($$,0,$1);
		}
;

TP:		R_INTEGER { 
					identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
					idt->obj = createType(INTEGER); 
					$$ = idt;
					}	
|		R_CHAR { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
					idt->obj = createType(CHARACTER); 
					$$ = idt;
					}	
|		R_BOOLEAN { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
					idt->obj = createType(BOOLEAN); 
					$$ = idt;
					}	
|		R_STRING { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
					idt->obj = createType(STRING); 
					$$ = idt;
					}	
;

B:		NB T_LEFTBRACES LS T_RIGHTBRACES { endBlock();}
;

LS:		S LS1 
;
LS1:	S LS1
|		
;
MT: {
		int l = newLabel();
		$$ = l;
		fprintf(asm_file,"\tTJMP_FW L%d\n",l);
		}
;

ME: {
		int l = newLabel();
		$$ = l;
		fprintf(asm_file,"\tTJMP_FW L%d\nL%d\n",l,l-1);
		}
;

MW: {
	int l = newLabel();
	$$ = l;
	fprintf(asm_file,"L%d\n",l);
}
;
S:		R_IF E R_THEN MT S {
			if(!CheckType($2->obj,BOOLEAN)) {yyerror("Erro if\n");YYERROR;}
			printf("entrou no if\n");
			fprintf(asm_file,"L%d:\n",$4);
			
		}
|		R_IF E R_THEN MT S R_ELSE ME S {
			if(CheckType($2->obj,BOOLEAN) != 1) {yyerror("Erro if\n");YYERROR;}
			printf("entrou no if then else tipo do 2 %d %d  <- BOOLEAN \n",$2->obj->attribute->type,BOOLEAN);
			fprintf(asm_file,"L%d:\n",$7);
		}
|		R_WHILE MW E R_DO MT S {
			if(!CheckType($3->obj,BOOLEAN)) {yyerror("Erro while\n");YYERROR;}
			
			fprintf(asm_file,"\tJMP_BW L%d\nL%d\n",$2,$5);
		}
|		B
|		F MA T_EQ E T_SEMICOLON {
			printf("Testando igual \n");
			if(!CheckTypes($1->obj,$4->obj)) {
				yyerror("Erro atibuicao\n");
				YYERROR;
			}
			fprintf(asm_file,"\tSTORE_VAR %d\n",$1->sToken);
		}
|		E T_SEMICOLON
|		R_BREAK T_SEMICOLON
|		DV
;

MA:	{fprintf(asm_file,"\tDUP\n");}
;
E:		E T_AND F { if(!CheckType($1->obj,BOOLEAN)) {yyerror("Erro and\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					
					fprintf(asm_file,"\tAND\n");
				  }
|		E T_OR F { if(!CheckType($1->obj,BOOLEAN)) {yyerror("Erro or\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tOR\n");
				  }
|		E T_LT F { if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro less than\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tLT\n");
				  }
|		E T_GT F { if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro greater than\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tGT\n");
				  }
|		E T_LE F { if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro less equal\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tLE\n");
				  }
|		E T_GE F { if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro greater equal\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tGE\n");
				  }
|		E T_EQEQ F { if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro equal equal\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tEQ\n");
				  }
|		E T_NEQ F {
					if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro not equal\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(BOOLEAN);
					fprintf(asm_file,"\tNE\n");
				  }
|		E T_PLUS F{ if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro plus\n");YYERROR;}
					if(!CheckType($1->obj,INTEGER) && !CheckType($1->obj,STRING)) yyerror("Erro tipo plus\n");
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					if(CheckType($1->obj,INTEGER)) $$->obj = createType(INTEGER);
					else $$->obj = createType(STRING);
					fprintf(asm_file,"\tADD\n");
				  }
|		E T_MINUS F{ if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro minus\n");YYERROR;}
					if(!CheckType($1->obj,INTEGER)) {yyerror("Erro tipo minus\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					if(CheckType($1->obj,INTEGER)) $$->obj = createType(INTEGER);
					else $$->obj = createType(STRING);
					fprintf(asm_file,"\tSUB\n");
				  }
|		E T_TIMES F{ if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro times\n");YYERROR;}
					if(!CheckType($1->obj,INTEGER)) {yyerror("Erro tipo Times\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(INTEGER);
					fprintf(asm_file,"\tMUL\n");
				  }
|		E T_DIVIDE F{ if(!CheckTypes($1->obj,$3->obj)) {yyerror("Erro divide\n");YYERROR;}
					if(!CheckType($1->obj,INTEGER)) {yyerror("Erro divide plus\n");YYERROR;}
				    $$ = (struct identificador*)malloc(sizeof(struct identificador));
					$$->obj = createType(INTEGER);
					fprintf(asm_file,"\tDIV\n");
				  }
|		F {$$ = $1;}
;

F:		T_NOT F {$$ = $2;}
|		TRUE {$$ = $1;}
|		FALSE {$$ = $1;}
|		CHR {$$ = $1;}
|		STR { $$ = $1;}
|		NUM {$$ = $1;}
|		IDU { $$ = $1;
				fprintf(asm_file,"\tLOAD_VAR %d\n",$1->sToken);
			}
;

NB: {newBlock();}
;
NBI: {
		asm_file = fopen("code.asm","w");

		fprintf(asm_file, "%s", "-- Pascalmm Ver. 1.0\n\n");
		newBlock();
	}
;

IDU: T_ID { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
			//printf("utilizacao da variavel %s token %d*\n",$1->id,$1->sToken);
			pobject p = (pobject)malloc(sizeof(object));
			if((p=Find($1->sToken)) == 0){
				yyerror("Erro variavel nao declarada\n");
				YYERROR;
				p = Define($1->sToken);
			}
			p->eKind = NO_KIND_DEF_;
			$$ = idt;
			strcpy($$->id,$1->id);
			$$->sToken = $1->sToken;
			$$->obj = p;
			}
;

IDD: T_ID { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
			//printf("Definindo varivael name %s token %d\n", $1->id,$1->sToken);
			pobject p = (pobject)malloc(sizeof(object));
			printf("Segunda parte\n");
			if( (p=Search($1->sToken)) != 0){
				yyerror("Erro declaração de variavel repetida\n");
				YYERROR;
			} else {
				p = Define( $1->sToken );
			}
			$$ = idt;
			p->eKind = NO_KIND_DEF_;
			strcpy($$->id,$1->id);
			$$->sToken = $1->sToken;
			$$->obj = p;
}
;

TRUE:	R_TRUE { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
				idt->obj = (pobject)malloc(sizeof(object));
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->booleanVal = 1;
				int tokenSecundario = addBooleanConst(1);
				fprintf(asm_file,"\tLOAD_CONST %d\n", tokenSecundario);
				idt->obj->attribute->type = BOOLEAN;
				$$ = idt;
				}
;

FALSE:	R_FALSE { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
				idt->obj = (pobject)malloc(sizeof(object));
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->booleanVal = 0;
				int tokenSecundario = addBooleanConst(0);
				fprintf(asm_file,"\tLOAD_CONST %d\n", tokenSecundario);
				idt->obj->attribute->type = BOOLEAN;
				$$ = idt;
				}
;

CHR:	T_CHAR { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
				idt->obj = (pobject)malloc(sizeof(object));
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->charVal = $1;
				int tokenSecundario = addCharConst($1);
				fprintf(asm_file,"\tLOAD_CONST %d\n", tokenSecundario);
				idt->obj->attribute->type = CHARACTER;
				$$ = idt;
				}
;

STR:	T_STRING { 
				identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
				idt->obj = (pobject)malloc(sizeof(object));
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->stringVal = $1;
				int tokenSecundario = addStringConst($1);
				fprintf(asm_file,"\tLOAD_CONST %d\n", tokenSecundario);
				idt->obj->attribute->type = STRING;
				$$ = idt;
				}
;

NUM:	T_NUMBER { identificador *idt = (struct identificador*)malloc(sizeof(struct identificador));
				idt->obj = (pobject)malloc(sizeof(object));
				idt->obj->attribute = (pattr)malloc(sizeof(attr));
				idt->obj->attribute->intVal = $1;
				int tokenSecundario = addIntConst($1);
				fprintf(asm_file,"\tLOAD_CONST %d\n", tokenSecundario);
				idt->obj->attribute->type = INTEGER;
				$$ = idt;
				}
;

%%
int main( void )
{
	return yyparse();
}