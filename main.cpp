
#define MAXFRIENDS 500


#include <stdio.h>
#include "friendlist.h"


int main()
{
	int i;

	/* create a friendarray and init it*/
	fellow* aFriends[MAXFRIENDS];
	
	for (i = 0; i < MAXFRIENDS; i++)
		aFriends[i] = NULL;


	fellow* pF;
	
	pF = fw_get();

	fw_print(pF);


	fw_delete(pF);
}

