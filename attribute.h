#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#define MAX_CONST 100

#include <stdlib.h>
typedef enum {CHARACTER = 0 , INTEGER, BOOLEAN, STRING} tType;

typedef struct attr
{
	tType type;
	union{
		int intVal;
		char charVal;
		char* stringVal;
		int booleanVal;
	};
} attr, *pattr;

typedef struct t_const{
	tType type;
	struct t_const *pNext;
	int sToken;
	union{
		int intVal;
		char charVal;
		char* stringVal;
		int booleanVal;
	};
}t_const,*pt_const;

static int labelNo = 0;
int newLabel();
int addCharConst(char c);
int addIntConst(int n);
int addStringConst(char *s);
int addBooleanConst(int b);

static pt_const constTable;

#endif