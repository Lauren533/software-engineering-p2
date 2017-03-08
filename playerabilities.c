#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SLOT_NUMBER 20
#define MAX_PLAYER_NUM 6
#define MAX_PLAYER_NAME_SIZE 15
void move_backwards (struct Player * players.slot_index);
void init_slots(int num_of_slots, int slotlocation);
void print_slots(struct slot * slots.number, struct slot * slots.location);
int input_num_of_slots (void);
void init_human (struct Player *structname);
void init_elf (struct Player *structname);
void init_wizard (struct Player *structname);
void init_ogre (struct Player *structname);
void changing_caps (struct Player * pplayer, struct Slot* pSlot);
void move_players (struct Player *playerstruct);
void attack_other_player (struct Player * pAttacker, struct Player* pDefender);
void move_forward (struct Player * players->slot_index);
void move_backwards (struct Player * players->slot_index);
void move_options(struct Player *players, struct Slot *slots, int  no_players, int num_of_slots, moves *moves, struct Slot slots.player_index);
void player_move(int no_players, int slot_index, moves *moves, char *slots.location, struct Player *players);





struct Slot
{
	char *location;
	int number;
	int player_index;
	bool filled;//shows if a slot contains a player or not.
};
struct Slot *slots is now a global variable so it doesn't need to be in the function definitions.
struct 
{
	Slot slots [MAX_SLOT_NUMBER];
}

	typedef struct
	{
		bool can_move_forward;
		bool can_move_backward;
		bool can_attack_two_players;
		int closest_player1;
		int closest_player2;
	}moves;
	
	
//num_of_slots is now a global variable saying how many slots are in use of the game.
int num_of_slots = 0;

// Initialize slot array to random places.
void init_slots(Slot slots.location)
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
		
		for (i = 0; i < num_of_slots; i++)
		{
			slots[i].player_index == -1;
			slots[i].filled == false;
		}
	}
}

void print_slots(struct slot * slots.number, struct slot * slots.location)
{
	int i = 0;
	printf("The slots entered are:\n");
	for (i = 0; i < num_of_slots; i++)
	{
		printf("%2d: %s\n", slots[i].number, slots[i].location);
	}
}

int input_num_of_slots (void)
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


//initiating player struct
struct Player
{
	char name[15];
	char type[10];
	int luck;
	int magic_skills;
	int smartness;
	int dexterity;
	int strength;
	int life_points;
	int slot_index;
	
};
struct Player players[MAX_PLAYER_NUM];
{
//initiating a struct for the different player types
void init_human (struct Player *structname);
void init_elf (struct Player *structname);
void init_ogre (struct Player *structname);
void init_wizard (struct Player *structname);
void slot_allocater (struct Player *structname);
};
int main(void)
{

	srand(time(NULL));
	num_of_slots = input_num_of_slots ();
	init_slots();
	print_slots();
	const char *pl
	int no_players;
	int i;
	int type;
	//char name[15];


	printf("Please enter the number of players you wish to have (max 6) \n \n");
	scanf("%d",&no_players);

	struct Player playerstruct[no_players];

	printf("To pick your player type, please use these corresponding numbers: \n"
			"Elf=1 \n"
			"Human=2 \n"
			"Ogre=3 \n"
			"Wizard=4 \n \n");
			
	for (i=0;i<no_players;i++)
	{

		printf(" \n Please enter corresponding number of player type: \n ");
		scanf("%d",&type);
	
		if (type==1)
		{
			strcpy(playerstruct[i].type,"Elf");
		}
		else if(type==2)
		{
			strcpy(playerstruct[i].type,"Human");
		}
		else if(type==3)
		{
			strcpy(playerstruct[i].type,"Ogre");
		}
		else if (type == 4)
		{
			strcpy(playerstruct[i].type,"Wizard");
		}
			
		printf("\n Please enter player name: \n");
		scanf("%s", playerstruct[i].name);
	}

	for (i=0;i<no_players;i++)
	{
		if (strcmp(playerstruct[i].type,"Elf")==0)
		{
			init_elf(&playerstruct[i]);
		}
		else if(strcmp(playerstruct[i].type,"Human")==0)
		{
			init_human(&playerstruct[i]);
		}
		else if(strcmp(playerstruct[i].type,"Ogre")==0)
		{
			init_ogre(&playerstruct[i]);
		}
		else if (strcmp(playerstruct[i].type,"Wizard")==0)
		{
			init_wizard(&playerstruct[i]);
		}
	}

	for(i=0; i<no_players; i++)
	{
		
		printf("Name of player %d is %s.\n", i+1, playerstruct[i].name);
		printf("Smartness: %d.\n", playerstruct[i].smartness);
		printf("Dexterity: %d.\n", playerstruct[i].dexterity);
		printf("Strength: %d.\n", playerstruct[i].strength);
		printf("Magic Skills: %d.\n", playerstruct[i].magic_skills);
		printf("Luck: %d.\n", playerstruct[i].luck);
		printf("slot_index: %d.\n\n", playerstruct[i].slot_index);
	}
	return 0;
}

void init_human (struct Player *structname)
{
	int sum;

	
	while (sum > 300)
	{
		int j=rand() %100 +1;
		(*structname).smartness= j;
		(*structname).luck=  rand() %100 +1;
		(*structname).dexterity=  rand() %100 +1;
		(*structname).strength=  rand() %100 +1;
		(*structname).magic_skills= rand() %100 +1;
		sum=0;
		sum=((*structname).luck+(*structname).dexterity+(*structname).smartness+(*structname).magic_skills+(*structname).strength);
	}
	(*structname).life_points=100;
}
void init_elf (struct Player *structname)
{
		(*structname).smartness= rand() %32 +69;
		(*structname).luck=  rand() %42 +59;
		(*structname).dexterity=  rand() %100 +1;
		(*structname).strength=  rand() %50 +1;
		(*structname).magic_skills= rand() %30 +50;
		
		(*structname).life_points=100;
}
void init_wizard (struct Player *structname)
{
		(*structname).smartness= rand() %12 +89;
		(*structname).luck=  rand() %52 + 49;
		(*structname).dexterity=  rand() %100 +1;
		(*structname).strength=  rand() %20 +1;
		(*structname).magic_skills= rand() %22+79;
		
		(*structname).life_points=100;
}
void init_ogre (struct Player *structname)
{
	int o_sum=51;
	
	while (o_sum >=50)
	{
		(*structname).smartness= rand() %20+1;
		(*structname).luck=  rand() %49 + 1;
		o_sum=(*structname).luck + (*structname).smartness;
	}
		
		(*structname).dexterity=  rand() %22 +79;
		(*structname).strength=  rand() %22 +79;
		(*structname).magic_skills= 0;
		
		(*structname).life_points=100;
}


void changing_caps (struct Player * pplayer, struct Slot* pSlot)
{//function changes the capabilities of the players depending on which slot they
//move to, if they choose to move at all.
	if (strcmp (struct pSlot->location, "Hill") == 0)
	{
		if (pplayer->dexterity < 50)
		{
			pplayer->strength -= 10;
		}
		else if (pplayer->dexterity >= 60)
		{
			pplayer->strength += 10;
		}
	}
	else if (strcmp(pSlot->location, "City") == 0)
	{
		if (pplayer->smartness > 60)
		{
			pplayer->magic_skills += 10;
		}
		else if (pplayer->smartness <= 50)
		{
			pplayer->magic_skills -= 10;
		}
	}
}//Level Ground isn't mentioned as moving to this type of slot doesn't affect player abilities.

/*void move_players (struct Player *playerstruct)
{
	int direction;// temp;
	
	if (slots.player_index == -1)
	{
		
	}
	
}*/

void attack_other_player (struct Player * pAttacker, struct Player* pDefender)
{
	if (pDefender->strength <= 70)
	{//if the player being attacked has less than 71 strength points they lose life points equivalent to 1/2 their strength points.
		pDefender->life_points -= pDefender->strength/2;
		printf("%s has taken damage!\n", Player* pDefender);
		printf("They're life points are not at %d\n", pDefender->life_points);
	}
	else
	{//if the player being attacked has more than 70 strength points the attacking player loses 30% of their strength in life points.
		pAttacker->life_points -= 0.3 * pDefender->strength;
		printf("Attacker's life points have been damaged! They're now at \n");
		printf("%d\n", pAttacker->life_points);
	}
}
/*
struct Slot * slot_for_player(struct Player * pplayer)
	{
		return &(slots[pplayer->slot_num -1]);
	}
	struct Player * player_in_slot(struct Slot * pslot)
	{
		for (i = 0; i < no_players; i++)
		{
			if (player->slot_number == Slot->number)
			{
				return player;
			}
			return NULL;
		}
	}*/
	void move_forward (struct Player * players->slot_index)
	{
		struct Player *player->slot_index += 1;
		void changing_caps(Player *pplayer, Slot *pslot);
	}
	
	void move_backwards (struct Player * players->slot_index)
	{
		struct Player *player->slot_index -= 1;
		void changing_caps(Player *pplayer, Slot *pslot);
	}
	void move_options(struct Player *players, struct Slot *slots, int  no_players, int num_of_slots, moves *moves, struct Slot slots.player_index)
	{
		int check_left;
		int check_right;
		if (struct Player players[i].slot_index > 0)//if the slot isn't occupied
		{
			if (struct Player players[i].slot_index < num_of_slots - 1)
			{
				if ((!struct Player ((players[i].slot_index )+ 1).filled) && (!struct Player ((players[i].slot_index)- 1).filled)
				{
					moves->can_move_forward = true;
					moves->can_move_backward = true;
				}
				else if ((!struct Player ((players[i].slot_index) + 1).filled)) && (struct Player ((players[i].slot_index) - 1).filled))
				{
					moves->can_move_forward = true;
					moves->can_move_backward = false;
				}
				else if ((struct Player ((players[i].slot_index) + 1).filled)) && (!struct Player ((players[i].slot_index) - 1).filled))
				{
					moves->can_move_forward = false;
					moves->can_move_backward = true;
				}
				else if ((struct Player ((players[i].slot_index) + 1).filled)) && (struct Player ((players[i].slot_index) - 1).filled))
				{
					moves->can_move_forward = false;
					moves->can_move_backward = false;
				}
			}
			
			//edge cases if player on first or last slot
			
			else if (players[i].slot_index==0)
			{
				if (struct Player ((players[i].slot_index) + 1).filled)
				{
					moves->can_move_forward = false;
					moves->can_move_backward = false;
				}
				else
				{
					moves->can_move_forward = true;
					moves->can_move_backward = false;
					
				}
				else if (players[i].slot_index==num_of_slots-1)
				{
					if (struct Player ((players[i].slot_index) - 1).filled)
						{
					moves->can_move_forward = false;
					moves->can_move_backward = false;
				}
				else
				{
					moves->can_move_forward = false;
					moves->can_move_backward = true;
					
				}
				
			}
			//look for closest player or players
			//if player on first slot
			if (players[i].slot_index == 0)
			{
				check_right = 1;//only need to look forward
				
				while (!struct Player ((players[i].slot_index+check_right) ).filled)
				{
					check_right ++;
				}
				moves->closest_player1 = (struct Player (players[i].slot_index+check_right).player_index).slot_index;
			}
			//if player on last slot
			else if (players[i].slot_index == num_of_slots-1)
			{
				check_left = 1;//only need to look backwards
				
				while (!struct Player (players[i].slot_index+check_left ).filled)
				{
					check_left ++;
				}
				moves->closest_player1 = (struct Player (players[i].slot_index-check_left).player_index).slot_index;
			}
			//if player in middle position
			else if ((players[i].slot_index < num_of_slots-1)&& (players[i].slot_index > 0))
			{
				//need to check in both directions for players
				check_left = 1;
				check_right=1;
				
				//while the slots on either side are not filled with a player
				while ((!struct Player ((players[i].slot_index-check_left) ).filled)) && (!struct Player ((players[i].slot_index+check_right) ).filled)
				{
					//to ensure we do not go too far left to exit array
					if((players[i].slot_index+check_left)>0)
					{
					check_left ++;
					}
					
					//to ensure we do not go too far right to exit array
					else if((players[i].slot_index+check_left)<num_of_slots-1)
					{
					check_right ++;
					}
				}
				//if there are two closest players
				if ((struct Player ((players[i].slot_index-check_left) ).filled)) && (struct Player ((players[i].slot_index+check_right) ).filled)
				{
					moves -> can_attack_two_players =true;
					moves -> closest_player1 = (struct Player (players[i].slot_index+check_right).player_index).slot_index;
					moves->closest_player2 = (struct Player (players[i].slot_index-check_left).player_index).slot_index;
				}
				//if the closest player is to the left
				else if (struct Player ((players[i].slot_index-check_left) ).filled))
				{
					moves->closest_player1 = (struct Player (players[i].slot_index-check_left).player_index).slot_index;
				}
				//if the closest player is to the right
				else if (struct Player ((players[i].slot_index+check_right) ).filled))
				{
					moves->closest_player1 = (struct Player (players[i].slot_index+check_right).player_index).slot_index;
				}
			}
		}
	}
	void player_move(int no_players, int slot_index, moves *moves, char *slots.location, struct Player *players)
	{
		int i;
		int move_number;
		int player_move;
		moves moves;
		int direction_choice;//0 to move backward, 1 to move forward, set initially to -1
		
		
		for (i = 0; i < no_players; i++)
		{
			print_slots(slot * slots.number, slot * slots.location)
			moves.can_move_forward = false;
			moves.can_move_backward = false;
			moves.can_attack_two_players = false;
			moves.closest_player1 = -1;
			moves.closest_player2 = -1;
			player_move = -1;
			move_number = 0;
			printf("%s - your move!", Player *player[i + 1].name);
			move_options(Player *players, Slot *slots, no_players, num_of_slots, moves *moves, Slot slots.player_index)
			
			if(moves.can_attack_two_players)
			{
				//telling user they have the option to attack either player
				printf("\nTo attack player %s enter %d\n", struct Player players((moves -> closest_player1).player_index).name, move_number++);
				printf("\nTo attack player %s enter %d\n",struct Player players((moves -> closest_player2).player_index).name, move_number++);
			
				if (moves -> can_move_forward)
				{
					printf("To move forward  press %d\n", move_number++);
				}
				if (moves -> can_move_backward)
				{
					printf("To move backwards press %d \n", move_number++);
				}
				do 
				{
					scanf("%d", &player_move);
					
				}
				while (player_move>-1 && player_move < move_number);
				
				if (player_move==0)
				{
					attack_other_player (&players[i],&players(slots(moves->closest_player1).player_index));
				}
				else if (player_move==1)
				{
					attack_other_player (&players[i],&players(slots(moves->closest_player2).player_index));
				}
				else if (player_move==2 && moves.can_move_forward)
				{//need to declare this function!!
					direction_choice=1; //to move left/forward
					move_forward (Player * players->slot_index);
				}
				else if (player_move==3 && moves.can_move_backward)
				{
					direction_choice=0; //to move right/backward
					move_backwards (Player * players->slot_index);
				}
				
			}
			else
			{
				printf("\nTo attack player %s enter %d\n", struct Player players((moves -> closest_player1).player_index).name, move_number++);
				if (moves.can_move_forward)
				{
					printf("To move forward press %d", move_number++);
				}
				if (moves.can_move_backward)
				{
					printf("To move backward press %d", move_number++);
				}
				scanf("%d", &player_move);
				if (player_move == 0)
				{
					attack_other_player (&players[i],&players(slots(moves->closest_player1).player_index));
				}
				else if (moves.can_move_forward && player_move == 1)
				
				{//need to declare this function!!
					direction_choice=1; //to move left/forward
					move_forward (Player * players->slot_index);
				}
				else if (moves.can_move_backward&& player_move == 1=2)
				
				{//need to declare this function!!
					direction_choice=0; //to move right/backward
					move_backwards (Player * players->slot_index);
				}
			}
		}
	}
