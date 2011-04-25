
#include "interface.h"

/* print opener */
void iface_printOpener()
{
	printf("\nWelcome to the INTERACTIVE FRIENDSHIP MANAGEMENT PROGRAM (IFMP)\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n\n");
	printf("Press h and enter for help\n\n");
}


/* print help */
void iface_printHelp()
{
	printf("Following commands are available:\n");
	printf("  a : add a friend\n");
	printf("  d : delete a friend\n");
	printf("  s : search a friend (print it)\n");
	printf("  p : print friend list\n");
	printf("  h : print this help\n");
	printf("  q : quit\n\n");
}

/* manage mainloop */
bool iface_mainLoop(fellow** aFriends, const int ciLen)
{
	const char* prompt = "<< ifmp >> ";
	char* key = NULL;
	int i;

	iface_printOpener();

	/* handle key event */
	while (true)
	{
		printf("%s", prompt);
		key = readline_dyn(2);
		if (key == NULL)
			continue;

		if (key[0] == 'h')
			iface_printHelp();

		else if (key[0] == 'p')
			fli_print(aFriends, ciLen);

		else if (key[0] == 'a')
			fli_insert_sorted(aFriends, ciLen);

		else if (key[0] == 'q')
		{
			delete[] key;
			break;
		}

		delete[] key;
	}


	for (i = 0; i < ciLen; i++)
	{
		if (aFriends[i] != NULL)
			fw_delete(aFriends[i]);
	}

	return true;
}


