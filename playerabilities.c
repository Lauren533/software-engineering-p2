#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
struct Players
{
	char name[15];
	char type[10];
	int luck;
	int magic_skills;
	int smartness;
	int dexterity;
	int strength;
	int life_points;
	int slot_number;
	
};

void human (struct Players *structname);
void elf (struct Players *structname);
void ogre (struct Players *structname);
void wizard (struct Players *structname);
void slot_allocater (struct Players *structname);
int main(void)
{

srand(time(NULL));
int no_players;
int i;
int type;
char name[15];


printf("Please enter the number of players you wish to have (max 6) \n \n");
scanf("%d",&no_players);

struct Players playerstruct[no_players];

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
		elf(&playerstruct[i]);
	}
	else if(strcmp(playerstruct[i].type,"Human")==0)
	{
		human(&playerstruct[i]);
	}
	else if(strcmp(playerstruct[i].type,"Ogre")==0)
	{
		ogre(&playerstruct[i]);
	}
	else if (strcmp(playerstruct[i].type,"Wizard")==0)
	{
		wizard(&playerstruct[i]);
	}
	
}

for(i=0; i<no_players; i++){
	
	printf("Name of player %d is %s.\n", i+1, playerstruct[i].name);
	printf("Smartness: %d.\n", playerstruct[i].smartness);
	printf("Dexterity: %d.\n", playerstruct[i].dexterity);
	printf("Strength: %d.\n", playerstruct[i].strength);
	printf("Magic Skills: %d.\n", playerstruct[i].magic_skills);
	printf("Luck: %d.\n\n", playerstruct[i].luck);
}
return 0;
}

void human (struct Players *structname)
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
void elf (struct Players *structname)
{
		(*structname).smartness= rand() %32 +69;
		(*structname).luck=  rand() %42 +59;
		(*structname).dexterity=  rand() %100 +1;
		(*structname).strength=  rand() %50 +1;
		(*structname).magic_skills= rand() %30 +50;
		
		(*structname).life_points=100;
}
void wizard (struct Players *structname)
{
		(*structname).smartness= rand() %12 +89;
		(*structname).luck=  rand() %52 + 49;
		(*structname).dexterity=  rand() %100 +1;
		(*structname).strength=  rand() %20 +1;
		(*structname).magic_skills= rand() %22+79;
		
		(*structname).life_points=100;
}
void ogre (struct Players *structname)
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
void slot_allocater (struct Players *structname)
{
	int i, tmp, j;
	int player_num[no_players];
	//to avoid confucion, player_num is the name of the array containing an integer value for each player.
	//no_players is the number of players that are in the game.
	int slot_num[num_of_slots];
	//slot_num is the name of the array storing an int value for each slot in the game.
	//num_of_slots is the number of slots in the game.
	//num_of_slots = 
	
	//assigning a slot for each player
	for (i = 0; i < num_of_slots; i++)
	{
		if (i < no_players)
		{
			slot_num[i] = i + 1;
		}
		else
		{
			slot_num[i]= 0;
		}
	}
	//shuffling the slots to make it 'random'
	
	for (i = 0; i < num_of_slots; i++)
	{
		if (slot_num[i] > 0)
		{
			structname[slot_num[i]].slot_number = i;
		}
		//j = rand ()% ;
	}
	
	
}
	
