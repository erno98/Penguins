//
//  endGame.c
//  Penguins
//
//  Created by Borys Bondos on 10/12/2017.
//

#include "endGame.h"

/*function returns 1 = end of the game, 0=can continue
 variables:
 int game_type - 20 turns, 40 turns or game till the end of fishes
 int fishes_on_board - how many fishes left
 int possible_move -   0=at least one player can’t move
 int numb_of_penguins_team - number of penguins in one team
 int x- number of players*/



int game_end(int game_type, int fishes_on_board,int turn_number, int possible_move, int numb_of_penguins_team, int number_of_players)
{
    if(turn_number > (numb_of_penguins_team)*number_of_players)
    {
        
        if(game_type == 1)  // 20 turns mode
        {
            if(fishes_on_board>0 && turn_number<=20 && possible_move!=0)
                return 0;
        }
        else if(game_type == 2)  //40 turns mode
        {
            if(fishes_on_board>0 && turn_number<=40 && possible_move!=0)
                return 0;
        }
        else if(game_type == 3)   // if fishes mode
        {
            if(fishes_on_board>0 && turn_number>=0 && possible_move!=0)
                return 0;
        }
        else return 1;
    }
    
    
    // while placement do not check possible move
    if(turn_number <= (numb_of_penguins_team)*2)
    {
        if(game_type == 1)  // 20 turns mode
        {
            if(fishes_on_board>0 && turn_number<=20)
                return 0;
        }
        else if(game_type == 2)  //40 turns mode
        {
            if(fishes_on_board>0 && turn_number<=40)
                return 0;
        }
        else if(game_type == 3)   // if fishes mode
        {
            if(fishes_on_board>0 && turn_number>=0)
                return 0;
        }
        else return 1;
    }
    
    else return 1;
    
    return 0;
}


/*while function int game_end will return one, then progam will use function int who_win()
 this function returns number of player who won the game*/
int who_win(int point1, int point2, int point3, int point4, int point5, int point6)        //1player points, 2 player points ...
{
    int pl[6];
    int i;
    pl[0]= point1;
    pl[1]= point2;
    pl[2]= point3;
    pl[3]= point4;
    pl[4]= point5;
    pl[5]= point6;
    int max=pl[0];
    int imax=0;
    
    for(i=0; i<6; i++)
    {
        if(pl[i]>=max)
        {
            max=pl[i];
            imax=(i+1);
        }
    }
    return imax;
}


