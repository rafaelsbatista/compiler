#include "sToken.h"
#include <string.h>
#include <stdlib.h>

int searchName(char name[200]){
	tokenNoh* lToken;

	if ( tk2_list == 0 )
	{
		tokenNoh* new_tk = (tokenNoh*) malloc(sizeof(tokenNoh));
		strcpy(new_tk->id,name);
		new_tk->sToken = incTk2Count();
		new_tk->tk_prox = 0;
		tk2_list = new_tk;
		return new_tk->sToken;
	}
	else
	{
		for ( lToken = tk2_list ; lToken != 0 ; lToken = lToken->tk_prox )
		{
			if ( strcmp(lToken->id, name) == 0 )
			{
				return lToken->sToken;
			}
		}
		tokenNoh* new_tk = (tokenNoh*) malloc(sizeof(tokenNoh));
		strcpy(new_tk->id,name);
		new_tk->sToken = incTk2Count();
		new_tk->tk_prox = tk2_list;
		tk2_list = new_tk;
		return new_tk->sToken;
	}
}

int incTk2Count()
{
	return tk2_count++;
}