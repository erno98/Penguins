//
//  map.h
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#ifndef map_h
#define map_h

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

extern int playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
extern int maxNumberOfPlayers;
extern int playerPoints[6];
extern char phase[10];
extern char map[100][100];

extern void readMap(const char *nameOfFile);
extern void printMap(char map[100][100]);
extern void outputMap(char *fileName);

#endif /* map_h */
