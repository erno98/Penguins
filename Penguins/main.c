//
//  main.c
//  Penguins
//
//
//

#include <stdio.h>
#include "map.h"
#include "placement.h"


int main(int argc, const char * argv[]) {
    readMap("movement1.txt");
    printMap(map);
    outputMap("output.txt");
    placement();
    return 0;
}
