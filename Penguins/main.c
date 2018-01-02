//
//  main.c
//  Penguins
//
//
//


#include "main.h"

int main(int argc, const char * argv[]) {
    //readMap("beforeGameStarts.txt");
    readMap("movement1.txt");
    printMap(map);
    if (phase[0] == 'p') { // placement
        placement();
    }
    //initMovement();
    //printf("Player %d wins with %d points.\n", who_win(playerPoints)+1, playerPoints[who_win(playerPoints)]);
    //printScores();
    outputMap("output.txt");
    return 0;
}
