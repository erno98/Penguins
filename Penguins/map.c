//
//  map.c
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#include "map.h"

int MaxRows = 100;
int MaxColumns = 100;
int playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
int maxNumberOfPlayers = 6;
char phase[10];
int playerPoints[6] = {0};
char map[100][100];

char *substring (char *string, int start, int end);
void readZeroRow(char *rowString);

void readMap(const char *nameOfFile) {
    FILE *file;
    file = fopen(nameOfFile, "r");
    if (file == NULL) {
        perror("Error");
    }
    if (file) {
        int c, i, j = 0, k = -1;
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
        
        while ((c = getc(file)) != EOF){
            k += 1;
            if (c == '\n'){
                j += 1;
                k = 0;
                c = getc(file); // skip \n
            }
            if (c == '\0'){
                printf("Terminate");
            }
            map[j][k] = c;
        }
        fclose(file);
    }
}

void readZeroRow(char *rowString){
    playerTurn = (int)rowString[0]-'0';
    
    int score[maxNumberOfPlayers+2];
    int length = (int)strlen(rowString);
    int scoreIndex = 0;
    int i;
    
    for (i=1; i<length; i++) {
        if (rowString[i] == ' ' || rowString[i] == '\n'){
            score[scoreIndex] = i;
            scoreIndex++;
        }
    }
    
    for(i=0; i<maxNumberOfPlayers; i++){
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

void printMap(char map[MaxRows][MaxColumns]) {
    int i, j;
    for (i=0; i<MaxRows; i++){
        for (j=0; j<MaxColumns; j++){
            if (map[i][j] == '\0'){
                j = 0;
                break;
            }
            printf("%c", map[i][j]);
        }
        if (map[i][j] == '\0'){
            break;
        }
        printf("\n");
    }
};

void printMapToFile(FILE *f) {
    int i, j;
    for (i=0; i<MaxRows; i++){
        for (j=0; j<MaxColumns; j++){
            if (map[i][j] == '\0'){
                j = 0;
                break;
            }
            fprintf(f, "%c", map[i][j]);
        }
        if (map[i][j] == '\0'){
            break;
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
    fprintf(f, "%d ", playerTurn+1);
    for (i=0; i<maxNumberOfPlayers; i++) {
        if (i == maxNumberOfPlayers-1){
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
