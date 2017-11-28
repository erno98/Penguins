//
//  main.c
//  Penguins
//
//
//

#include <stdio.h>
#include "map.h"


int main(int argc, const char * argv[]) {
    //readMap("beforeGameStarts.txt");
    //readMap("midGame1.txt");
    //readMap("midGame2.txt");
    readMap("movement1.txt");
    printMap(map);
    outputMap("output.txt");
    printf("Player 1 Score: %d\n", playerPoints[0]);
    return 0;
}
