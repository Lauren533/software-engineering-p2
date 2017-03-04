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
	char *location;
	int number;

};

// Initialize slot array to random places.
void init_slots(struct Slot *slots, int num_of_slots)
{
	int i = 0;
	for (i = 0; i < num_of_slots; i++)
	{
		int slotlocation = rand() % 3;

		slots[i].number = i + 1;
		if (slotlocation == 0)
		{
			slots[i].location = "Hill";
		}
		else if (slotlocation == 1)
		{
			slots[i].location = "City";
		}
		else if (slotlocation == 2)
		{
			slots[i].location = "Level Ground";
		}
	}
}

void print_slots(struct Slot * slots, int num_of_slots)
{
	printf("The slots entered are:\n");
	for (i = 0; i < num_of_slots; i++)
	{
		printf("%2d: %s\n", slots[i].number, slots[i].location);
	}
}

int input_num_of_slots ()
{
	int num_of_slots;
	printf("Please input the number of slots you would like to create (max 20) : ");
	scanf("%d", &num_of_slots);
	while (num_of_slots > MAX_SLOT_NUMBER)
	{
		printf("Number of slots chosen is too many. It must be less than %d\n", MAX_SLOT_NUMBER);
		printf("Please enter a number less than or equal to 20\n");
		scanf("%d", &num_of_slots);
	}
	return num_of_slots;
}
int main(void)
{
	srand(time(NULL));
	int num_of_slots = input_num_of_slots ();
	struct Slot slots[MAX_SLOT_NUMBER];
	init_slots(slots, num_of_slots);
	print_slots(slots, num_of_slots);
}
