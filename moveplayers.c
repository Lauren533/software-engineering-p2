void moveplayers (struct Players *structname)
{
	int direction, temp;
	
	START: printf("To move forward, press 1. \n");
	printf("To move backwards, press 2. \n");
	scanf("%d",&direction);
	
	if(direction ==1)
	{
		//if at end of slots and no slot ahead
		if(playerstruct[no_players-1].slot_num+1>=num_of_slots)
		{
			printf(" \n Can't move foreward any further, please move back \n");
			goto START;
		}
		//if another player ahead
		else if (slots[playerstruct[no_players-1].slot_num+1].player_num >=0)
	
		{
			printf("\n There is a player in front of you! \n");
		}
		//if next slot is free
		else if (slots[playerstruct[no_players-1].slot_num+1].player_num ==-1)
		{
			temp=slots[playerstruct[no_players-1].slot_num].player_num;//set number to temp
			slots[playerstruct[no_players-1].slot_num].player_num=-1;//make position empty
			slots[playerstruct[no_players-1].slot_num].player_num=temp;
			playerstruct[no_players-1].slot_num+=1; //move foreward
			
		}
		
	}
	
	else if(direction ==2)
	{
		//if at start of slots with no slot behind
		if(playerstruct[no_players-1].slot_num-1<0)
		{
			printf(" \n Can't move backwards, please move foreward \n");
			goto START;
		}
		//if another player behind
		else if (slots[playerstruct[no_players-1].slot_num-1].player_num >=0)
	
		{
			printf("\n There is a player in behind you! \n");
		}
		//if previous slot is free
		else if (slots[playerstruct[no_players-1].slot_num-1].player_num ==-1)
		{
			temp=slots[playerstruct[no_players-1].slot_num].player_num;//set number to temp
			slots[playerstruct[no_players-1].slot_num].player_num=-1;//make position empty
			slots[playerstruct[no_players-1].slot_num].player_num=temp;
			playerstruct[no_players-1].slot_num-=1;//move back
			
		}
		
	}
	
}
