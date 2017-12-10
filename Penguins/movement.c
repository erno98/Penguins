 //
 //  movement.c
 //  Penguins
 //
 //  created by Ernest Pokropek 10/12/2017
 //
 //
 
#include "map.h"
#include "placement.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>

int movement(){
    
  int Xp=atoi(position[0]);
  int Yp=atoi(position[1]);
  int Xd=atoi(destination[0]);
  int Yd=atoi(destination[1]);
  
  if(movementPossible==true && pathCorrect==true){
      int i;
      for (i=0;i<3;i++){
         map[Xp][Yp][i]=' ';
      }
      map[Xd][Yd][1]=playerId+96;
   }
   else printf("Wrong destination! \n);
   

  return 0;
  
}

bool movementPossible(string position, string destination){
  //map[x][y]
  
  if(abs(Xd-Xp)==abs(Yd-Yp) return true;
  
  else return false;
  
}

bool pathCorrect(string position, string destination){

  int pathLength=sqrt(((abs(Xd-Xp)*abs(Xd-Xp))+((abs(Yd-Yp)*(abs(Yd-Yp)));
  int i;
  
  if(Xd>Xp){
    if(Yd>Yp){
      for(i=0; i< pathLength; i++){
        if(map[Xp+i][Yp+i][2]!=' ' &&  map[Xp+i][Yp+i][1]<=3) return true;
        
      }
    }
    else{
      for(i=0; i< pathLength; i++){
        if(map[Xp+i][Yp-i][2]!=' ' &&  map[Xp+i][Yp-i][1]<=3) return true;
          
      } 
  }
  else{
    if(Yd>Yp){
      for(i=0; i< pathLength; i++){
        if(map[Xp-i][Yp+i][2]!=' ' &&  map[Xp-i][Yp+i][1]<=3) return true;
          else return false;
    }
    else{
      for(i=0; i< pathLength; i++){
        if(map[Xp-i][Yp-i][2]!=' ' &&  map[Xp-i][Yp-i][1]<=3) return true;
          else return false;
    }
  
  }
  
  
}
