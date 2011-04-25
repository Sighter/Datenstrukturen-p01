
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
	printf("\n");
	
	char* r = NULL;
	int i;
	for (i = 0; i < NUMHOB; i++)
	{
		printf("Give Hobby %2i: ", i);
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
