/*
 * assignment_2.c
 *
 *  Created on: 23 Feb 2017
 *      Author: zachary
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_SLOT_NUMBER 20
#define MAX_SLOT_NAME 15
#define MAX_NAME_SIZE 15
#define MAX_PLAYER_ROLE_SIZE 10
#define MAX_CAPABILITIES 100

struct Slot
{
	char location[MAX_SLOT_NAME];
	int number;

};
int main(void)
{
	int i;
	srand(time(NULL));
	int num_of_slots;
	int slotlocation;
	struct Slot slots[MAX_SLOT_NUMBER];

	printf("Please input the number of slots you would like to create (max 20) : ");
			scanf("%d", &num_of_slots);

		for (i = 0; i < 20; i++)
		{
			slotlocation = rand ()% 3;

			if (slotlocation == 0)
			{
			strcpy(slots[i].location, "Hill");
			}
			else if (slotlocation == 1)
			{
				strcpy(slots[i].location, "City");
			}
			else if (slotlocation == 2)
			{
				strcpy(slots[i].location, "Level Ground");
			}
		}
		printf("The slots entered are:\n");
		for (i = 0; i < num_of_slots; i++)
		{

				printf("%s", slots[i].location);
			}
}
