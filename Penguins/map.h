//
//  map.h
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#ifndef map_h
#define map_h

#include "main.h"

#endif /* map_h */

#define MAXROWS 100
#define MAXCOLUMNS 100
#define MAXPLAYERS 6

extern int playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
extern int playerPoints[MAXPLAYERS];
extern char phase[10];
extern char map[MAXROWS][MAXCOLUMNS];

extern void readMap(const char *nameOfFile);
extern void printMap(char map[MAXROWS][MAXCOLUMNS]);
extern int penguinsOnBoard(char map[MAXROWS][MAXCOLUMNS]);
extern void outputMap(char *fileName);
extern void printScores(void);
