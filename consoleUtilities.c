        //
// Created by pea on 28/08/18.
//

#include <stdio.h>
#include "consoleUtilities.h"

int consolePrint(char* string){
    consoleGotoX(15);
    printf("%s\n", string);
    return 4;
}