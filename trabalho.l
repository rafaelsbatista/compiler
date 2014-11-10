%option noyywrap
	#include <stdlib.h>
	#include <string.h>
	#include "trabalho.tab.h"
	#include "sToken.h"
	#include "structure.h"
	#include "attribute.h"
%%

"=" 		return T_EQ;
"!=" 		return T_NEQ;
"<" 		return T_LT;
">" 		return T_GT;
"<=" 		return T_LE;
">=" 		return T_GE;
"==" 		return T_EQEQ;
"&&" 		return T_AND;
"||" 		return T_OR;
"+" 		{printf("mais\n"); return T_PLUS;}
"-" 		return T_MINUS;
"*" 		{printf("vezes\n"); return T_TIMES;}
"/" 		return T_DIVIDE;
":"			return T_COLON;
";" 		return T_SEMICOLON;
"," 		return T_COMMA;
"{" 		return T_LEFTBRACES;
"}" 		return T_RIGHTBRACES;
"!" 		return T_NOT;

"integer" 	return R_INTEGER;
"char" 		return R_CHAR;
"boolean" 	return R_BOOLEAN;
"string" 	return R_STRING;
"var"		return R_VAR;
"then"		return R_THEN;
"if" 		return R_IF;
"else" 		return R_ELSE;
"while"		{printf("while\n"); return R_WHILE;} 
"do" 		return R_DO;
"break"     return R_BREAK;
"true"		{
			
				yylval.sToken = addBooleanConst(1);
				return R_TRUE;
			}
"false" 	{
			
				yylval.sToken = addBooleanConst(0);
				return R_FALSE;
			}

'[a-zA-Z]' {
			printf("adicionou char\n");
			yylval.sToken = addCharConst((yytext + 1)[0]);
			printf("saiu adicionou char\n");
			return T_CHAR;
		}
["][^"]*["] {
			printf("pegando string/n");
			char* string;
			string = (char*) malloc(sizeof(char)*(strlen(yytext-2)));
			strncpy(string,(yytext+1),strlen(yytext-2));
			string[ strlen(string)-1 ] = '\0';
			yylval.sToken = addStringConst("rafael");
			
			printf("pegando string saindo/n");
			return T_STRING;
		}
[a-zA-Z][a-zA-Z0-9]* {
			char *identificador = (char*)malloc(sizeof(char)*200);
			strncpy(identificador,yytext,200);
			yylval.sToken = searchName(identificador);
			return T_ID;
		}
[0-9]+ 	{
			int integer;
			integer = atoi( yytext );
			yylval.sToken = addIntConst(integer);
			return T_NUMBER;
		}
[ \t]+
[\r\n]
%%
