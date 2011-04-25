
#define MAXFRIENDS 500


#include <stdio.h>
#include "interface.h"


int main()
{
	int i;
	bool r;

	/* create a friendarray and init it*/
	fellow* aFriends[MAXFRIENDS];
	
	for (i = 0; i < MAXFRIENDS; i++)
		aFriends[i] = NULL;

	r = iface_mainLoop(aFriends, MAXFRIENDS);


}

