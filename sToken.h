#ifndef STOKEN_H
#define STOKEN_H


typedef struct tokenNoh
{
	char id[200];
	int sToken;
	struct tokenNoh* tk_prox;
}tokenNoh;

static tokenNoh* tk2_list = 0;

static int tk2_count = 0;

int searchName( char name[200]);
int incTk2Count();

#endif