//
//  placement.c
//  Penguins
//  created by Ernest Pokropek 10/12/2017
//
//

#include "map.h"
#include "placement.h"
#include <string.h>


int placement(){
    //printf("String %s", string);
    printf("\n");
    printMap(map);
    
    *string position;
    int i,j;
    int playerID=1;
    for(i=0; i < numberOfPlayers; i++){
        for(j=0; j < maxNumberOfPenguinsPerPlayer; j++){
               printf("Player : %c\n", playerID);
               scanf("%s", &position);
               placePenguin(playerID, position);
               playerID++;
        }playerID=1;
    }
    
    
    
    return 0;
}

void placePenguin(int playerID, *string position){
    int X=atoi(position[0]);
    int Y=atoi(position[1]);
    if(map[X][Y][2]==' ') printf("Choose block with 1 fish! \n");
    else{
        
        map[X][Y][1]=(playerID+96); //ASCII 97='a' for player 1, 98='b' for player 2 etc.    
    }
    
}
