#include "main.h"
/**
 * main - entry point
 */

int main()
{
	int choice;

	printf("Insert your choice\n");
	scanf("%d", choice);

	printf("1: INPUT\n");
	printf("2:SCAN\n");

	switch(choice)
	{
		case 1: input();
			break;
		case 2: scan();
			break;
		default: printf("Invalid input");
	}
	return 0;
}
