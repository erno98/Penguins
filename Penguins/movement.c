 //
 //  movement.c
 //  Penguins
 //
 //  created by Ernest Pokropek 10/12/2017
 //
 //
 
#include "movement.h"

bool movementPossible(string position, string destination);
bool pathCorrect(string position, string destination);
int getFishesFromCharacter(char character);

bool teamCorrect(string playerTurn, string playerID);
bool destinationInsideMap(string destiantion);
bool isPenguinAtDestination(string destination);


int initMovement() {
    string position, destination;
    int playerID = 0;
    int count = 0;
    while (penguinsOnBoard(map)!= 0) {
        printMap(map);
        playerID = (count%numberOfPlayers)+1;
        
        printf("Player %d move penguin\n", playerID);
        printf("From Location: ");
        scanf("%s", position);
        printf("To Destination: ");
        scanf("%s", destination);
        
        movement(position, destination, playerID);
        count++;
    }
    
    return 0;
}


int movement(string position, string destination, int playerID){

    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');
  
  if( movementPossible(position, destination) && pathCorrect(position, destination)) {
      playerPoints[playerID-1] += getFishesFromCharacter(map[Xp][Yp]);
      map[Xp][Yp]=' ';
      int fishesAtDestination = convertToInt(map[Xd][Yd], '0');
      switch (fishesAtDestination) {
          case 1:
              map[Xd][Yd]=playerID+96;
              break;
          case 2:
              map[Xd][Yd]=playerID-1+'A';
              break;
          case 3:
              map[Xd][Yd] = playerID-1+'U';
              break;
              
          default:
              printf("Good Penguin. Found bug but no fishes.\n");
              exit(1);
              break;
      }
      
   }
   else printf("Wrong destination! \n");
   

  return 0;
    
}

bool movementPossible(string position, string destination) {
    //map[x][y]
    //Is this needed?
    
    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');
    
    if(abs(Xd-Xp)==abs(Yd-Yp)) return true;
    else if (abs(Xd-Xp) == 0) return true; // diagonally
    
    else return false;
    
}

bool pathCorrect(string position, string destination){
    
    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');
    
    int pathLength=sqrt((abs(Xd-Xp)*abs(Xd-Xp))+(abs(Yd-Yp)*abs(Yd-Yp))); // nice
    int i;
    
    if (Xd == Xp){ // horizontally
        if(Yd>Yp){ // right
            for(i=1; i <= pathLength; i++){
                //if(map[Xp+i][Yp+i][2]!=' ' &&  map[Xp+i][Yp+i][1]<=3) return true;
                if('1' <= map[Xd][Yp+i]  && map[Xp][Yp+i] <= '3') return true;
                
            }
        }
        else{ // left
            for(i=1; i<=pathLength; i++){
                //if(map[Xp+i][Yp-i][2]!=' ' &&  map[Xp+i][Yp-i][1]<=3) return true;
                if('1'<=map[Xp][Yp-i] &&  map[Xp][Yp-i]<='3') return true;
            }
        }
    } else if (Xd>Xp){ // down
        if(Yd>Yp){ // right
            for(i=1; i<= pathLength; i++){
                if('1' <= map[Xp+i][Yp+i]  && map[Xp+i][Yp+i] <= '3') return true;
                
            }
        }
        else{ // left
            for(i=1; i<= pathLength; i++){
                if('1'<=map[Xp+i][Yp-i] &&  map[Xp+i][Yp-i]<='3') return true;
            }
        }
    }
    else  { // up
        if (Yd>Yp) { // right
            for(i=1; i <= pathLength; i++){
                if('1' <= map[Xp-i][Yp+i]  && map[Xp-i][Yp+i] <= '3') return true;
            }
        }
        else{ // left
            for(i=1; i <= pathLength; i++){
                if('1'<=map[Xp-i][Yp-i] &&  map[Xp-i][Yp-i]<='3') return true;
            }
            
        }
    }
    return false;
}

int getFishesFromCharacter(char character){
    if ('a' <= character && character <= 'a'+MAXPLAYERS){
        return 1;
    }
    if ('A' <= character && character <= 'A'+MAXPLAYERS){
        return 2;
    }
    if ('U' <= character && character <= 'U'+MAXPLAYERS){
        return 3;
    }
    return 0;
}

bool teamCorrect(string playerTurn, string playerID){
   if(playerID==playerTurn) return true;                        //Borys told that he'll make a function in turn system returning
   else return false;                                           // the ID of a player currently having turn
}

bool destinationInsideMap(string destiantion){
 
 if(destination[0]<mapRows && destination[1]<mapColumns &&               //assume that mapRows and mapColumns are previously defined
    destination[0] >= 0 && destination[1] >= 0) return true;
 else return false;
}

bool isPenguinAtDestination(string destination){                                  //checks whether the destination has already 
   string destinationInfo = map[destination[0]][destination[1]];                  //ID of penguin team on it, or is it empty
   if (destinationInfo[1]!='1' || destinationInfo[1]!='2' || destinationInfo[1]!='3'){
    return false }
 else return true; 
}
