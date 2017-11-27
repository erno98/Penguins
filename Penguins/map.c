//
//  map.c
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#include "map.h"

char s[100];
int c, playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
int firstLetter = 1;
int maxNumberOfPlayers = 6;
char phase[10];
int playerPoints[6] = {0, 0, 0, 0, 0, 0};
// verticalIndex = row
int verticalIndex = 0, horizontalIndex = -1;

void readZeroRow(char *rowString){
    char score[3];
    char *stringBeforePlayerScore, *playerScore;
    int i;
    playerTurn = (int)rowString[0]-'0';
    stringBeforePlayerScore = strchr(rowString, ' ');
    
    for(i=5; i>=0; i--){
        playerScore = strrchr(stringBeforePlayerScore, ' ');
        stringBeforePlayerScore = strchr(stringBeforePlayerScore, ' ');
        printf("Before Player Score: %s", stringBeforePlayerScore);
        printf("Player Score: %s", playerScore);
        playerPoints[i] = atoi(playerScore);
    }
    
    
}

void readMap(const char *nameOfFile) {
    FILE *file;
    file = fopen(nameOfFile, "r");
    if (file == NULL) {
        perror("Error");
    }
    if (file) {
        int i;
        for (i=0; i<4; i++){
            if ((fgets(s, sizeof(s), file)) != NULL) {
                switch (i) {
                    case 0:
                        readZeroRow(s);
                        break;
                    case 1:
                        numberOfPlayers = (int)s[0]-'0';
                        break;
                    case 2:
                        maxNumberOfPenguinsPerPlayer = (int)s[0]-'0';
                        break;
                    case 3:
                        if (strcmp(s, "placement\n") == 0){ strcpy(phase, "placement"); }
                        else { strcpy(phase, "movement");}
                        break;
                }
            }
        }
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
        }
        fclose(file);
    }
}
