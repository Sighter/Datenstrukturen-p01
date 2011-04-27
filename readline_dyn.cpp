
#include <stdio.h>
#include <string.h>
#include "readline_dyn.h"


/* Hint: Zeichenketten dürfen nur so viel Speicherplatz belegen, wie nötig ist, um alle Zeichen aufzunehmen!
 * The function readline_dyn takes about this by reading data in a great buffer, after that it dynamicly allocates
 * only the memory it needs for the string. Length + 1, because the \0 character has to be added at the end. */

/* read a line, you have to give a linebuffersize
 * @ buffersize
 * < pointer to an allocated char array or null if nothing was read */
char* readline_dyn(int buffsize)
{
	char c = 'a';
	char* line = NULL;
	char* temp = new char[buffsize];
	int i = 1;
	int k = 0;

	
	while (true)
	{
		c = fgetc(stdin);
		if (c == EOF || c == '\n' || i >= buffsize)
			break;
		
		temp[i-1] = c;

		i++;
	}

	/* flush the input buffer */
	if ((i >= buffsize) && (c != EOF && c != '\n'))
		while ((c = getchar()) != '\n' && c != EOF);

	if (i == 1)
	{
		delete[] temp;
		return NULL;
	}

	/* terminate the string */
	line = new char[i];

	for (k=0; k < i; k++)
		line[k] = temp[k];
		
	line[i-1] = '\0';
		
	delete[] temp;
		
	return line;
}
