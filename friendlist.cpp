
#include "friendlist.h"


/* read a fellow from the command line */
fellow* fw_get()
{
	fellow* pF = new fellow;
	char c;

	printf("Give a number for the friend: ");
	scanf("%lu", &(pF->uiNumber));

	/* flush the buffer */
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Give a name of the friend: ");
	pF->pName = readline_dyn(LINEBUFFER);
	
	char* r = NULL;
	int i;
	for (i = 0; i < NUMHOB; i++)
	{
		printf("Give Hobby %2i: ", i + 1);
		r = readline_dyn(LINEBUFFER);
		if (r == NULL)
			break;
		else
			pF->aHobbys[i] = r;
	}	

	return pF;
}
		

/* print a fellow */
void fw_print(fellow* pF)
{
	int i = 0;

	printf("Friend Number: %lu\n", pF->uiNumber);

	if (pF->pName == NULL)
		printf("Friend Name: unknown\n");
	else
		printf("Friend Name: %s\n", pF->pName);
	
	printf("Hobbys:\n");

	for (i = 0; i < NUMHOB; i++)
		if (pF->aHobbys[i] != NULL)
			printf("  %s\n", pF->aHobbys[i]);

	printf("\n");
}	


/* delete a fellow, if it was dynamicly allocated */
bool fw_delete(fellow* pF)
{
	int i;

	if (pF->pName != NULL)
		delete[] pF->pName;

	for (i = 0; i < NUMHOB; i++)
		if (pF->aHobbys[i] != NULL)
			delete[] pF->aHobbys[i];

	delete pF;

	return true;
}



/* print friendlist */
void fli_print(fellow** aFriends, const int ciLen)
{
	int i = 0, k = 0;
	printf("Your Friendlist is able to save %d fellows:\n\n", ciLen);
	for (i = 0; i < ciLen; i++)
	{
		if (aFriends[i] != NULL)
		{
			fw_print(aFriends[i]);
			k++;
		}
	}
	printf("You have %d friends\n\n", k);
}


/* count friendlist */
int fli_count(fellow** aFriends, const int ciLen)
{
	int i = 0;
	int c = 0;
	for (i = 0; i < ciLen; i++)
		if (aFriends[i] != NULL)
			c++;
	return c;
}


/* Exercise 2
 * **********
 * sorted insert a friend in the given list, the function creates a new fellow
 * instance and uses the function fw_get to get a fellow (friend) from the
 * command line. So it have to shift all items, if it inserts an element before
 * an other one. I would feel better if the reading process is done by an interface
 * function */
bool fli_insert_sorted(fellow** aFriends, const int ciLen)
{
	int c = 0;
	int i = 0;
	int k = 0;

	fellow* pF = NULL;

	/* check wether there is place in the list */
	c = fli_count(aFriends, ciLen);
	
	if (c >= ciLen)
	{
		printf("Friendlist is full.\n");
		return false;
	}

	/* get a fellow */
	pF = fw_get();
	
	/* check if number is valid */
	if (pF->uiNumber <= 0 || pF->uiNumber > MAXNUMBERS)
	{
		printf("Friend Number is out of range\n");
		fw_delete(pF);
		return false;
	}
	
	/* insert */
	for (i = 0; i < ciLen; i++)
	{
		if (aFriends[i] == NULL)
		{
			aFriends[i] = pF;
			return true;
		}
		else if (aFriends[i]->uiNumber == pF->uiNumber)
		{
			printf("Number already in list.\n");
			fw_delete(pF);
			return false;
		}
		else if (aFriends[i]->uiNumber > pF->uiNumber)
		{
			/* shift all entries up */
			k = i;
			for(k = ciLen - 2; k >= i; k --)
			{
				aFriends[k+1] = aFriends[k];
			}
			
			aFriends[i] = pF;
			return true;
		}
	}
}


/* search a friend in list with number */
fellow* fli_search(unsigned long int uiNum, fellow** aList, const int ciLen)
{
	int i = 0;
	for (i = 0; i < ciLen; i++)
		if (aList[i] != NULL && aList[i]->uiNumber == uiNum)
			return aList[i];

	return NULL;
}

/* Exercise 4
 * **********
 * Delete a friend in by means of the given number. This function also has to shift all
 * other items in the list. To free memory it calls the fw_delete function, wich takes
 * care about deletion of the fellow instance and all dynamicly allocated strings in there.
 * See fw_delete for details. */
bool fli_delete(unsigned long int uiNum, fellow** aList, const int ciLen)
{
	int i = 0;
	int k = 0;

	/* check if number is valid */
	if (uiNum <= 0 || uiNum > MAXNUMBERS)
		return false;
	else
	{
		/* search, delete and shift */
		for (i = 0; i < ciLen; i++)
		{
			if (aList[i] != NULL && aList[i]->uiNumber == uiNum)
			{
				fw_delete(aList[i]);
				/* shift all down */
				for (k = i; k < ciLen - 1; k++)
				{
					aList[k] = aList[k+1];
				}
				return true;
			}
		}
	}
	return false;
}

