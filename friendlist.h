
#define LINEBUFFER 255
#define NUMHOB 10
#define MAXNUMBERS 100000

#include <stdlib.h>
#include <stdio.h>
#include "readline_dyn.h"

/* struct for managing a friend */
struct fellow
{
	unsigned long int uiNumber;
	char* pName;
	char* aHobbys[NUMHOB];

	/* init the struct */
	fellow()
	:	uiNumber(0),
		pName(NULL)
	{
		int i = 0;

		for (i=0; i < NUMHOB; i++)
			aHobbys[i] = NULL;
	}
};

/* read a fellow from the command line */
fellow* fw_get();

/* sorted insert a friend in the given list */
bool fw_insert_sorted(fellow* pF, fellow* aList);

/* search a friend in list with number */
fellow* fw_search(unsigned long int uiNum, fellow* aList);

/* print a fellow */
void fw_print(fellow* pF);
	
/* delete a fellow, if it was dynamicly allocated */
bool fw_delete(fellow* pF);
