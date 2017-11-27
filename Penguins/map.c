//
//  map.c
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#include "map.h"

void readMap(const char *nameOfFile) {
    int c, playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
    int firstLetter = 1;
    int maxNumberOfPlayers = 6;
    char phase[10];
    int playerPoints[6] = {0, 0, 0, 0, 0, 0};
    // verticalIndex = row
    int verticalIndex = 0, horizontalIndex = -1;
    
    FILE *file;
    file = fopen(nameOfFile, "r");
    if (file == NULL) {
        perror("Error");
    }
    if (file) {
        while ((c = getc(file)) != EOF){
            putchar(c);
            horizontalIndex += 1;
            if (c == '\n'){
                verticalIndex++;
                horizontalIndex = 0;
            }
            if (c == ' '){
                // do nothing
            }
            if (c == '\0'){
                printf("Terminate");
            }
            switch (verticalIndex) {
                case 0:
                    if (horizontalIndex == 0) {
                        playerTurn = (int)c-'0';
                    }
                    if (0 < horizontalIndex <= maxNumberOfPlayers) {
                        playerPoints[horizontalIndex] = (int)c-'0';
                    }
                    break;
                case 1:
                    numberOfPlayers = (int)c-'0';
                    break;
                case 2:
                    maxNumberOfPenguinsPerPlayer = (int)c-'0';
                    break;
                case 3:
                    if (c == 'p' && firstLetter) {
                        strcpy(phase, "placement");
                        firstLetter = 0;
                    } else if (c == 'm' && firstLetter) {
                        strcpy(phase, "movement");
                        firstLetter = 0;
                    }
                    break;
                default:
                    break;
            }
        }
        fclose(file);
    }
}
