//
// Created by pea on 28/08/18.
//

#ifndef ACIDS_CONSOLEUTILITIES_H
#define ACIDS_CONSOLEUTILITIES_H

#endif //ACIDS_CONSOLEUTILITIES_H

#define clear() printf("\033[H\033[J")
#define consoleGoto(x,y) printf("\033[%d;%dH", (x), (y))
#define consoleGotoX(x) printf("\033[%dC", (x));

int consolePrint(char* string);