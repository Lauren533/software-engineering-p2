#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SLOT_NUMBER 20
#define MAX_SLOT_NAME 15
#define MAX_NAME_SIZE 15
#define MAX_PLAYER_ROLE_SIZE 10
#define MAX_CAPABILITIES 100
 
 //Creating a struct for players
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
    int slot_index; //to store the slot position that the player is in
};
 
 //creating a struct for slots
struct Slot
{
    char *location; //to store the type of slot that the user has been placed in during init_slots
    int number;
    int player_index; //to store the number of player we are currently on
    bool slot_filled;
 };
 
typedef struct
{
    bool can_move_forward; //This will hold a true or false value for if it is possible for the user to move forward
    bool can_move_backward; //This will hold a true or false value for if it is possible for the user to move backward
    bool can_attack_two_players; //This will hold a true or false value for if there are two closest players and they can attack either
    int closest_player1; 
    int closest_player2;
}Moves;
 
 //declaring functions
void initialize(int no_players, struct Players * playerstruct);
void human (struct Players *structname);
void elf (struct Players *structname);
void ogre (struct Players *structname);
void wizard (struct Players *structname);
void init_slots(struct Slot *slots, int num_of_slots);
void print_slots(struct Slot * slots, int num_of_slots);
int input_num_of_slots ();
void assign_players_to_slots (struct Players structname[], struct Slot slots[], int num_of_slots, int num_of_players);
void changing_caps(struct Players * pplayer, struct Slot * pSlot);
void attack_player(struct Players *attacker, struct Players *defender);
void deciding_moves(struct Players players[], struct Slot slots[] , Moves * moves, int no_players, int num_of_slots, int current_position);
void fmoves(struct Players players[], struct Slot slots[] , Moves * moves, int no_players, int num_of_slots, int current_player);
void current_player_capabilities(int no_players, struct Players * playerstruct);
 
int main(void)
{
 
	//srand to ensure hat it will be a different random list each time
    srand(time(NULL));
    int no_players;
    int i;
    int type;
    char name[15];
    struct Slot slots[MAX_SLOT_NUMBER];
    int num_of_slots;
    Moves moves;
     
	 
    printf("Please enter the number of players you wish to have (max 6) \n \n");
    scanf("%d",&no_players); 
	
	//calling functions in order to initialise game
    struct Players playerstruct[no_players];
    initialize(no_players, playerstruct);
    num_of_slots = input_num_of_slots ();
    init_slots(slots, num_of_slots);
    assign_players_to_slots (playerstruct, slots, num_of_slots,  no_players);
	print_slots(slots, num_of_slots);
	//will loop around for the number of players in the game
	for(i=0; i<no_players; i++){
	 printf("What move would the player %s like to make? \n",playerstruct[i].name);
    fmoves(playerstruct, slots, &moves, no_players, num_of_slots, i);
	current_player_capabilities(no_players,playerstruct);
	print_slots(slots, num_of_slots);
	
	}
    
   
    return 0;
}
 
void initialize(int no_players, struct Players * playerstruct)
{
	//This function allows users to pick a player 'type' and name for the number of players they have entered
	//Within this function, we call 4 other functoins, one for each seperate character type in order to assign capabilities
    int type;
    int i;
   
    printf("To pick your player type, please use these corresponding numbers: \n"
        "Elf=1 \n"
        "Human=2 \n"
        "Ogre=3 \n"
        "Wizard=4 \n \n");
      
		//taking in users choice of character type
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
     
	 //caling in the 4 functions depending on user choice
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
     //printing user capabilities
    for(i=0; i<no_players; i++)
    {
        printf("Name of player %d is %s.\n", i+1, playerstruct[i].name);
        printf("Smartness: %d.\n", playerstruct[i].smartness);
        printf("Dexterity: %d.\n", playerstruct[i].dexterity);
        printf("Strength: %d.\n", playerstruct[i].strength);
        printf("Magic Skills: %d.\n", playerstruct[i].magic_skills);
        printf("Luck: %d.\n\n", playerstruct[i].luck);
		printf("Lifepoints: %d.\n\n", playerstruct[i].life_points);
    }
}
 
void human (struct Players *structname)
{
    int sum;
	//as the sum of all capabilities must be less than 300
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
   //as sum of smartness and luck must be less than 50
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
 
void init_slots(struct Slot *slots, int num_of_slots)
{
    int i = 0;
    int slotlocation;
    for (i = 0; i < num_of_slots; i++)
    {
        slotlocation = rand() % 3;
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
       
        slots[i].player_index = -1; //setting all player index for each slot to -1 as default
		//when game is run, index shows up beside slots, all empty slots will show up as -1 indicating they are not filled
    }
}
 
void print_slots(struct Slot * slots, int num_of_slots)
{
	//printing the slot number, type of slot, and whether the slot is filled or not i.e. will print -1 if it does not contain a player
	//will print player index 0 to player number inputted to show where players are in slots
    int i;
   
    printf("The slots entered are:\n");
    for (i = 0; i < num_of_slots; i++)
    {
        printf("%2d: %s %d\n", slots[i].number, slots[i].location, slots[i].player_index);
    }
}
 
int input_num_of_slots ()
{
	//to get number of slots the user wants to be in the game
    int num_of_slots;
    printf("Please input the number of slots you would like to create (max 20) : ");
    scanf("%d", &num_of_slots);
	//if it is greater than 20, user will be asked to input another number of slots
    while (num_of_slots > MAX_SLOT_NUMBER)
    {
        printf("Number of slots chosen is too many. It must be less than %d\n", MAX_SLOT_NUMBER);
        printf("Please enter a number less than or equal to 20\n");
        scanf("%d", &num_of_slots);
    }
    return num_of_slots;
}
 
void assign_players_to_slots(struct Players players[], struct Slot slots[], int num_of_slots, int num_of_players)
{  
	//function to randomly put players in slots, ensuring that no two players are in the one slot
    int i,random_slot_num;
 
    srand(time(NULL));
 
    for(i=0;i<num_of_players;i++)
    {
        do{
            random_slot_num=rand()%num_of_slots;
        }while(slots[random_slot_num].player_index>-1);//i.e repeat until the random slot is an empty slot
   
        if(slots[random_slot_num].player_index==-1)//i.e if slot is empty
        {
            slots[random_slot_num].player_index = i;
            //slots[random_slot_num].slot_filled = true; //not sure if this is necessary
            players[i].slot_index = random_slot_num;
        }
    }
 
    //telling user which user is in which slot
    for(i=0; i<num_of_players; i++){
        printf("%s is in Slot %d\n", players[i].name, players[i].slot_index+1);
    }
}
 
void deciding_moves (struct Players players[], struct Slot slots[] , Moves *moves, int no_players, int num_of_slots, int current_position)
{
	//This function determines which moves players are able to make 
	
    int i= current_position;
    int check_right; // to check forward in the slots
    int check_left; //to check backward in the slots
   
    if (players[i].slot_index>0 && players[i].slot_index<num_of_slots-1)//To ensure not on first or last slot
    {
        //check slot to the right and slot to the left are not filled with another player
        if((!slots[(players[i].slot_index)+1].slot_filled) && (!slots[(players[i].slot_index)-1].slot_filled))
        {
            moves->can_move_forward=true;
            moves->can_move_backward =true;
            //can move back or forward
        }
        //if right slot is ccupied and left slot is unoccupied
        else if ((slots[(players[i].slot_index)+1].slot_filled) && (!slots[(players[i].slot_index)-1].slot_filled))
        {
            moves->can_move_forward=true;
            moves->can_move_backward =false;
        }
        //if right slot is unoccupied and left is occupied
        else if ((!slots[(players[i].slot_index)+1].slot_filled) && (slots[(players[i].slot_index)-1].slot_filled))
        {
            moves->can_move_forward=false;
            moves->can_move_backward =true;
        }
        //if both slots are occupied to the two sides of player, cannot move
        else if ((slots[(players[i].slot_index)+1].slot_filled) && (slots[(players[i].slot_index)-1].slot_filled))
        {
            moves->can_move_forward=false;
            moves->can_move_backward =false;
        }
    }
	else if (players[i].slot_index==num_of_slots-1) //if player on last slot
	{
		if(!slots[(players[i].slot_index)-1].slot_filled)//if previous slot is empty
		{
			moves->can_move_forward=false; //this is always false as player cannot ever move foreward when on last slot
            moves->can_move_backward =true;
		}
		else if (slots[(players[i].slot_index)-1].slot_filled)//if previous slot if filled
		{
			moves->can_move_forward=false; 
            moves->can_move_backward =false;
		}
	}
	else if (players[i].slot_index==0) //if player on first slot
	{
		if(!slots[(players[i].slot_index)+1].slot_filled)//if next slot is empty
		{
			moves->can_move_forward=true;
            moves->can_move_backward =false; //this is always false as player cannot ever move back when on first slot
		}
		else if (slots[(players[i].slot_index)-1].slot_filled)//if previous slot if filled
		{
			moves->can_move_forward=false;
            moves->can_move_backward =false;
		}
	}
	
    //if player is on last slot in array
    if (players[i].slot_index==num_of_slots-1)
    {
        check_left =1; //only need to look left as nothing in front
        while (!slots[players[i].slot_index-check_left].slot_filled)
        {
            check_left++;
        }
        moves->closest_player1 = players[slots[players[i].slot_index-check_left].player_index].slot_index;
    }
    //if player is on first slot
    else if (players[i].slot_index==0)
    {
        check_right =1; //only need to look right as nothing behind
        while (!slots[players[i].slot_index+check_right].slot_filled)
        {
            check_right++;
        }
        moves->closest_player1 = players[slots[players[i].slot_index+check_right].player_index].slot_index;
    }
    //if player is neither on last or first slot there is possibility of two closest players
    else if ((players[i].slot_index<num_of_slots-1) && (players[i].slot_index>0))
    {
        check_left=1;
        check_right=1;
   
        while((!slots[players[i].slot_index+check_right].slot_filled)&&(!slots[players[i].slot_index-check_left].slot_filled))
        {
            if ((players[i].slot_index+check_right)<num_of_slots-1)
            {
				//incrementing until player is found
                check_right++;
            }
            if ((players[i].slot_index-check_left)>0)
            {
				//incrementing until player is found
                check_left++;
            }
        }
        //if it finds two slots filled wih players the same distance away from current player
        if ((slots[players[i].slot_index+check_right].slot_filled)&&(slots[players[i].slot_index-check_left].slot_filled))
        {
            moves->can_attack_two_players = true;
			//assigning the two closest players to variables
            moves->closest_player1 = players[slots[players[i].slot_index+check_right].player_index].slot_index;
            moves->closest_player2 = players[slots[players[i].slot_index-check_left].player_index].slot_index;
        }
        //if the closest player is to the left i.e. backwards
        else if ((slots[players[i].slot_index-check_left].slot_filled)&&(!slots[players[i].slot_index+check_right].slot_filled))
        {
            moves->can_attack_two_players = false;
            moves->closest_player1 = players[slots[players[i].slot_index-check_left].player_index].slot_index;
        }
        //if closest player is to the right i.e. forewards
        else if ((slots[players[i].slot_index+check_right].slot_filled)&&(!slots[players[i].slot_index-check_left].slot_filled))
        {
            moves->can_attack_two_players = false;
            moves->closest_player1 = players[slots[players[i].slot_index+check_right].player_index].slot_index;
       
		}
	}

}
void attack_player(struct Players *attacker, struct Players *defender)
{
	//function to change capabilities when attacked
   
    if (defender->strength <= 70)
    {//if the player being attacked has less than 71 strength points they lose life points equivalent to 1/2 their strength points.
        defender->life_points -= defender->strength/2;
    }
    else
    {//if the player being attacked has more than 70 strength points the attacking player loses 30% of their strength in life points.
        attacker->life_points -= 0.3 * defender->strength;
    }
}
 
 
void move_player_right(struct Players * player, struct Slot * slots)
{
	//function to move player forward/right when called i.e. increment an index
    slots[player->slot_index+1].player_index = slots[player->slot_index].player_index;
    slots[player->slot_index].player_index = -1;
    slots[player->slot_index+1].slot_filled= true; // the next slot i.e. that they have moved into is now filled
    slots[player->slot_index].slot_filled=false; //slot player was originally in is now empty
    player->slot_index +=1;
    changing_caps(player, &slots[player->slot_index]); //passes player and the slot that player is on to change capabilities function
}
 
void move_player_left(struct Players * player, struct Slot * slots)
{
	//function to move player forward/right when called i.e. decrement an idex
    slots[player->slot_index-1].player_index = slots[player->slot_index].player_index;
    slots[player->slot_index].player_index = -1;
    slots[player->slot_index-1].slot_filled= true; // the previous slot i.e. that they have moved into is now filled
    slots[player->slot_index].slot_filled=false; //slot player was originally in is now empty
    player->slot_index -=1;
   
    changing_caps(player, &slots[player->slot_index]); //passes player and the slot that player is on to change capabilities function
}
 
void changing_caps(struct Players * pplayer, struct Slot * pSlot)
{
 
//function changes the capabilities of the players depending on which slot they
//move to, if they choose to move at all.
    if (strcmp (pSlot->location, "Hill") == 0)
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
 
 
void fmoves(struct Players players[], struct Slot slots[] , Moves * moves, int no_players, int num_of_slots, int current_player)
{
	//this function gives the user the option of what moves they would like to make, based on deciding moves function
	//will only let players pick a move if they are actually able to preform this move
    int choice, i;
   
	i = current_player;
    moves->can_move_backward=false;
	moves->can_move_forward=false;
	moves->can_attack_two_players=false;
	moves->closest_player1=-1;
	moves->closest_player2=-1;
        deciding_moves (players, slots, moves, no_players, num_of_slots, i);
        // testing printf("qqqqqqq\n\n");
        if(moves->can_attack_two_players)
        {
            // testing printf("eeeeeee");
			//int temp = 0;
			//temp = moves->closest_player1;
			//Here the user should be given the option to attack, however it is currently causing the program to crash 
            printf("To Attack Player %s : press 1 \n", players[slots[moves->closest_player1].player_index].name);
            printf("To Attack Player %s :press 2 \n", players[slots[moves->closest_player2].player_index].name);
            if((moves->can_move_backward)&& !(moves->can_move_forward))
            {
                printf("To Move backwards : Press 3\n");
            }
            else if(!(moves->can_move_backward) && (moves->can_move_forward))
            {
                printf("To Move forward : Press 4\n");
            }
            else if((moves->can_move_backward) && (moves->can_move_forward))
            {
                printf("To Move backward : Press 3\n");
                printf("To Move foreward : Press 4\n");
            }
           
            scanf("%d", &choice); 
           
            if(choice==1)//ie attack closest player 1
            {
                attack_player(&players[i], &players[slots[moves->closest_player1].player_index]);
            }
            else if(choice==2) // i.e. attacl closest player 2
            {
                attack_player(&players[i], &players[slots[moves->closest_player2].player_index]);
            }
            else if(choice==4) //move forward
            {
                move_player_right(&players[i], slots);
            }
            else if(choice ==3) // move backward
            {
                move_player_left(&players[i], slots);
            }
           
        }
        else if(!(moves->can_attack_two_players))
        {
            // testing printf("YFFFFFFFFFFFF");
			//Here the user should be given the option to attack, however it is currently causing the program to crash 
			printf("To Attack Player %s :Press 1\n", players[slots[moves->closest_player1].player_index].name);
            if((moves->can_move_backward) && (!moves->can_move_forward))
            {
                printf("To Move backward : press 2\n");
            }
            else if(!(moves->can_move_backward) && (moves->can_move_forward))
            {
                printf("To Move forward : press 3\n");
            }
            else if((moves->can_move_backward) && (moves->can_move_forward))
            {
                printf("To Move backward: press 2\n");
                printf("To Move forward: press 3\n");
            }
           
            scanf("%d", &choice); 
           
            if(choice==1)//ie attack closest player 
            {
                attack_player(&players[i], &players[slots[moves->closest_player1].player_index]);
            }
            else if( choice==3)  //move forward
            {
                move_player_right(&players[i], slots);
            }
            else if( choice ==2) // move backward
            {
                move_player_left(&players[i], slots);
            }
          
        }
       
    
}
void current_player_capabilities(int no_players, struct Players * playerstruct)
{
	int i;
	 for(i=0; i<no_players; i++)
    {
        printf("Name of player %d is %s.\n", i+1, playerstruct[i].name);
        printf("Smartness: %d.\n", playerstruct[i].smartness);
        printf("Dexterity: %d.\n", playerstruct[i].dexterity);
        printf("Strength: %d.\n", playerstruct[i].strength);
        printf("Magic Skills: %d.\n", playerstruct[i].magic_skills);
        printf("Luck: %d.\n\n", playerstruct[i].luck);
		printf("Lifepoints: %d.\n\n", playerstruct[i].life_points);
    }
}
