int change_turn(int turn)  // initial value in main turn= 0
	{
 turn=(turn+1);
 return turn;
	}

int player_turn(int number, int i) //initial value in main i=0
{
	if(i<number)
	{
  	i=(i+1);
	}
   else i=1;
   return i;

}
