%option noyywrap
	#include <stdlib.h>
	#include <string.h>
	#include "trabalho.tab.h"
	#include "sToken.h"
	#include "structure.h"
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
"true"		return R_TRUE;
"false" 	return R_FALSE;

'[a-zA-Z]' {
			yylval.character = (yytext + 1)[0];
			return T_CHAR;
		}
["][^"]*["] {
			yylval.string = (char*) malloc(sizeof(char)*(strlen(yytext-2)));
			strncpy(yylval.string,(yytext+1),strlen(yytext-2));
			yylval.string[ strlen(yylval.string)-1 ] = '\0';
			return T_STRING;
		}
[a-zA-Z][a-zA-Z0-9]* {
			yylval.id = (struct identificador*)malloc(sizeof(identificador));
			strncpy(yylval.id->id,yytext,200);
			//printf("ID = %s\n",yylval.id->id);
			yylval.id->sToken = searchName(yylval.id->id);
			//printf("token secundario %d id %s\n",yylval.id->sToken,yylval.id->id);
			return T_ID;
		}
[0-9]+ 	{
			yylval.integer = atoi( yytext );
			return T_NUMBER;
		}
[ \t]+
[\r\n]
%%
