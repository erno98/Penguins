//
//  map.c
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#include "map.h"

int playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
char phase[10];
int playerPoints[MAXPLAYERS] = {0};
char **map;
int mapRows = 1;
int mapColumns = 1;

char *substring (char *string, int start, int end);
void readZeroRow(char *rowString);
int isPenguinCharacter(char c);

//TODO: Adjust what to do based on read input

void readMap(const char *nameOfFile) {
    FILE *file;
    file = fopen(nameOfFile, "r");
    if (file == NULL) {
        perror("Error");
    }
    if (file) {
        int c, i, k = -1;
        char s[100];
        
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
        int penguinsOnBoard = 0;
        while ((c = getc(file)) != EOF){
            k++;
            if (c == '\n'){
                if(mapRows == 1){
                    mapColumns = k + 1;
                }
                mapRows++;
                map = (char **) realloc(map, (sizeof(char *) * mapRows)); // realloc next row;
                k=0;
                c = getc(file); // skip \n
            }
            int currentRow = mapRows-1;
            
            if (currentRow == 0 && mapColumns == 1 && k == 0) {
                map = (char **) malloc(sizeof(char *) * mapRows); // malloc first row;
                map[currentRow] = (char *)malloc(sizeof(char) * (k+1)); //malloc first value;
            }
            else if (currentRow == 0) {
                map[currentRow] = (char *)realloc(map[currentRow], (sizeof(char) * k+1)); //realloc kth value;
                mapColumns = k+1;
                
            } else if (currentRow > 0 && k == 0){
                map[currentRow] = (char *)calloc(sizeof(char), mapColumns); //malloc places for all columns;
            }
            
            if (currentRow % 2 == 1 && k == 0) {
                
                map[currentRow][k] = ' ';
                k++;
            }
            map[currentRow][k] = c;
            
            if (isPenguinCharacter(c)){ penguinsOnBoard++; };
        }
        
        if (penguinsOnBoard == (maxNumberOfPenguinsPerPlayer*numberOfPlayers)) {
            strcpy(phase, "movement");
        }
        fclose(file);
    }
}

int isPenguinCharacter(char c){
    int i;
    for (i = 0; i < numberOfPlayers; i++) {
        if (c == 'a'+i || c == 'A'+i || c == 'U'+i){
            return 1;
        }
    }
    
    return 0;
};

void readZeroRow(char *rowString){
    playerTurn = (int)rowString[0]-'0';
    
    int score[MAXPLAYERS+2];
    int length = (int)strlen(rowString);
    int scoreIndex = 0;
    int i;
    
    for (i=1; i<length; i++) {
        if (rowString[i] == ' ' || rowString[i] == '\n'){
            score[scoreIndex] = i;
            scoreIndex++;
        }
    }
    
    for(i=0; i<MAXPLAYERS; i++){
        playerPoints[i] = atoi(substring(rowString, score[i], score[i+1]));
    };
}

char *substring (char *string, int start, int end){
    char *pointer;
    int length = end-start;
    int c;
    pointer = malloc(length+1);
    
    if (pointer == NULL){
        printf("Unable to allocate memory");
        exit(1);
    }
    
    for (c=0; c<length; c++){
        *(pointer+c) = *(string+start);
        string++;
    }
    
    *(pointer+c) = '\0';
    
    return pointer;
}

void printMap(char **map) {
    int i = 0, j = 0;
    for (i=0; i<mapColumns; i++){
        if (i == 0) {
            printf("     %d  ", i);
        }
        else {
            printf("  %d  ", i);
        }
    }
    printf("\n");
    for (i=0; i<mapRows; i++){
        if (map[i][0]){
            printf("%c: ",'A'+i);
        } else { return; }
        
        for (j=0; j<mapColumns; j++){
            printf("[ %c ]", map[i][j]);
        }
        printf("\n");
    }
    
};

void printMapToFile(FILE *f) {
    int i, j;
    for (i=0; i<mapRows; i++){
        for (j=0; j<mapColumns; j++){
            if (i % 2 == 1 && j == 0){ j++; };
            fprintf(f, "%c", map[i][j]);
        }
        fprintf(f, "\n");
    }
};

void outputMap(char *fileName) {
    int i;
    FILE *f = fopen(fileName, "w");
    if (f == NULL){
        printf("File does not exist. Creating File");
        f = fopen(fileName, "wb");
    }
    fprintf(f, "%d ", ((playerTurn+1) % numberOfPlayers));
    for (i=0; i<MAXPLAYERS; i++) {
        if (i == MAXPLAYERS-1){
            fprintf(f, "%d\n", playerPoints[i]);
        }
        else {
            fprintf(f, "%d ", playerPoints[i]);
        }
    }
    fprintf(f, "%d\n", numberOfPlayers);
    fprintf(f, "%d\n", maxNumberOfPenguinsPerPlayer);
    fprintf(f, "%s\n", phase);
    
    printMapToFile(f);
    
    fclose(f);
}

int penguinsOnBoard(char **map){
    int i, j;
    int penguins = 0;
    for (i=0; i<mapRows; i++){
        for (j=0; j<mapColumns; j++){
            int number = convertToInt(map[i][j], '0');
            if (0 < number && number <= 9) {
                penguins += convertToInt(map[i][j], '0');
            }
        }
    }
    return penguins;
}


void printScores(){
    int i;
    for(i=0; i<numberOfPlayers; i++){
        printf("Player %d has %d points.\n", i+1, playerPoints[i]);
    }
}
