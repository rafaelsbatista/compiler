%{
	#include <stdio.h>
	#include <string.h>
	#include "scope_structure.h"
	#include "attribute.h"
	#include "code_generator.h"
	
	FILE* asm_file;
	
	extern int yylex( void );
	
	int yyerror( char *s){
		printf("bison-- error %s\n",s);
		return 0;
	}
	
	object int_ = { -1, NULL, SCALAR_TYPE_};
	pobject pInt = &int_;
	
	object char_ = { -1, NULL, SCALAR_TYPE_};
	pobject pChar = &char_;
	
	object bool_ = { -1, NULL, SCALAR_TYPE_};
	pobject pBool = &bool_;
	
	object string_ = { -1, NULL, SCALAR_TYPE_};
	pobject pString = &string_;
	
	object universal_ = { -1, NULL, SCALAR_TYPE_};
	pobject pUniversal = &universal_;
%}
%union {
	int integer;
	int boolean;
	char character;
	struct identificador *id;
	char *string;
	int sToken;
	struct object *obj;
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
%token <sToken> T_CHAR
%token <sToken> T_STRING
%token <sToken> T_ID
%token <sToken> T_NUMBER

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
%token <sToken> R_TRUE
%token <sToken> R_FALSE

%type <obj> IDU IDD TP LI TRUE FALSE CHR NUM STR E F
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
			pobject ob = $2;
			while(ob != 0 && ob->eKind == NO_KIND_DEF_){
				ob->eKind = VAR_;
				ob->_.Var.pType = $4;
				ob = ob->pNext;
			}
			
		}
;

LI:		LI T_COMMA IDD {addIdentificador($$,$1,$3);}
|		IDD {
		addIdentificador($$,0,$1);
		}
;

TP:		R_INTEGER { 
					$$ = pInt;
					}	
|		R_CHAR { 
					$$ = pChar;
					}	
|		R_BOOLEAN { 
					$$ = pBool;
					}	
|		R_STRING { 
					$$ = pString;
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
			if(!CheckTypes($2,pBool)) {yyerror("Erro if\n");YYERROR;}
			fprintf(asm_file,"L%d:\n",$4);
			
		}
|		R_IF E R_THEN MT S R_ELSE ME S {
			if(CheckTypes($2,pBool) != 1) {yyerror("Erro if\n");YYERROR;}
			fprintf(asm_file,"L%d:\n",$7);
		}
|		R_WHILE MW E R_DO MT S {
			if(!CheckTypes($3,pBool)) {yyerror("Erro while\n");YYERROR;}
			
			fprintf(asm_file,"\tJMP_BW L%d\nL%d\n",$2,$5);
		}
|		B
|		F MA T_EQ E T_SEMICOLON {
			if(!CheckTypes($1->_.Var.pType,$4)) {
				yyerror("Erro atibuicao\n");
				YYERROR;
			}
			fprintf(asm_file,"\tSTORE_VAR %d\n",$1->name);
		}
|		E T_SEMICOLON
|		R_BREAK T_SEMICOLON
|		DV
;

MA:	{
		fprintf(asm_file,"\tDUP\n");}
;
E:		E T_AND F { if(!CheckTypes($1,$3)) {yyerror("Erro and\n");YYERROR;}
					if(!CheckTypes($1,pBool)) {yyerror("Erro and 2\n");YYERROR;}
					$$ = pBool;
					
					fprintf(asm_file,"\tAND\n");
				  }
|		E T_OR F { if(!CheckTypes($1,$3)) {yyerror("Erro or\n");YYERROR;}
				   if(!CheckTypes($1,pBool)) {yyerror ("Erro or 2\n");YYERROR;}
					$$ = pBool;
					fprintf(asm_file,"\tOR\n");
				  }
|		E T_LT F { if(!CheckTypes($1,$3)) {yyerror("Erro less than\n");YYERROR;}
				    $$ = pBool;
					fprintf(asm_file,"\tLT\n");
				  }
|		E T_GT F { if(!CheckTypes($1,$3)) {yyerror("Erro greater than\n");YYERROR;}
				    $$ = pBool;
					fprintf(asm_file,"\tGT\n");
				  }
|		E T_LE F { 
					if(!CheckTypes($1,$3)) {yyerror("Erro less equal\n");YYERROR;}
				    $$ = pBool;
					fprintf(asm_file,"\tLE\n");
				  }
|		E T_GE F { 	
					if(!CheckTypes($1,$3)) {yyerror("Erro greater equal\n");YYERROR;}
				    $$ = pBool;
					fprintf(asm_file,"\tGE\n");
				  }
|		E T_EQEQ F { 
					if(!CheckTypes($1,$3)) {yyerror("Erro equal equal\n");YYERROR;}
				    $$ = pBool;
					fprintf(asm_file,"\tEQ\n");
				  }
|		E T_NEQ F {
					if(!CheckTypes($1,$3)) {yyerror("Erro not equal\n");YYERROR;}
				    $$  = pBool;
					fprintf(asm_file,"\tNE\n");
				  }
|		E T_PLUS F{ 
					if(!CheckTypes($1,$3)) {yyerror("Erro plus\n");YYERROR;}
					if(!CheckTypes($1,pInt) && !CheckTypes($1,pString)) yyerror("Erro tipo plus\n");
				    if(CheckTypes($1,pInt)) $$ = pInt;
					else $$ = pString;
					fprintf(asm_file,"\tADD\n");
				  }
|		E T_MINUS F{ 
					if(!CheckTypes($1,$3)) {yyerror("Erro minus\n");YYERROR;}
					if(!CheckTypes($1,pInt)) {yyerror("Erro tipo minus\n");YYERROR;}
				    $$ = pInt;
					fprintf(asm_file,"\tSUB\n");
				  }
|		E T_TIMES F{ 
					if(!CheckTypes($1,$3)) {yyerror("Erro times\n");YYERROR;}
					if(!CheckTypes($1,pInt)) {yyerror("Erro tipo Times\n");YYERROR;}
				    $$ = pInt;
					fprintf(asm_file,"\tMUL\n");
				  }
|		E T_DIVIDE F{ 
					if(!CheckTypes($1,$3)) {yyerror("Erro divide\n");YYERROR;}
					if(!CheckTypes($1,pInt)) {yyerror("Erro divide plus\n");YYERROR;}
				    $$ = pInt;
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
|		IDU { 
				$$ = $1;
				fprintf(asm_file,"\tLOAD_VAR %d\n",$1->name);
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

IDU: T_ID { 
			pobject p = (pobject)malloc(sizeof(object));
			if((p=Find($1)) == 0){
				yyerror("Erro variavel nao declarada\n");
				YYERROR;
				p = Define($1);
			}
			p->eKind = NO_KIND_DEF_;
			p->name = $1;
			$$ = p;
			}
;

IDD: T_ID { 
			pobject p = (pobject)malloc(sizeof(object));
			if( (p=Search($1)) !=0 ){
				yyerror("Erro declaração de variavel repetida\n");
				YYERROR;
			} else {
				p = Define( $1 );
			}
			p->eKind = NO_KIND_DEF_;
			p->name = $1;
			$$ = p;
}
;

TRUE:	R_TRUE { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", $1);
				$$ = pBool;
				}
;

FALSE:	R_FALSE { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", $1);
				$$ = pBool;
				}
;

CHR:	T_CHAR { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", $1);
				$$ = pChar;
				}
;

STR:	T_STRING {
				fprintf(asm_file,"\tLOAD_CONST %d\n", $1);
				$$ = pString;
				
				}
;

NUM:	T_NUMBER { 
				fprintf(asm_file,"\tLOAD_CONST %d\n", $1);
				$$ = pInt;
				}
;

%%
int main( void )
{
	return yyparse();
}