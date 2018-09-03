//
// Created by pea on 27/08/18.
//


#include "detected.h"
#define KRED  "\x1B[31m"

int detected(char* msg){
    printf("%s ", KRED);

    consolePrint(" ·▄▄▄▄  ▄▄▄ .▄▄▄▄▄▄▄▄ . ▄▄· ▄▄▄▄▄▄▄▄ .·▄▄▄▄");
    consolePrint(" ██▪ ██ ▀▄.▀·•██  ▀▄.▀·▐█ ▌▪•██  ▀▄.▀·██▪ ██");
    consolePrint(" ▐█· ▐█▌▐▀▀▪▄ ▐█.▪▐▀▀▪▄██ ▄▄ ▐█.▪▐▀▀▪▄▐█· ▐█▌");
    consolePrint(" ██. ██ ▐█▄▄▌ ▐█▌·▐█▄▄▌▐███▌ ▐█▌·▐█▄▄▌██. ██");
    consolePrint(" ▀▀▀▀▀•  ▀▀▀  ▀▀▀  ▀▀▀ ·▀▀▀  ▀▀▀  ▀▀▀ ▀▀▀▀▀•");

    consolePrint("Detection Message:");
    consolePrint(msg);
    consolePrint("\nPress any number to return to the main menu...");

    int num;
    char *p, s[100];
    while (fgets(s, sizeof(s), stdin)) {
        num = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            consolePrint("Please enter an integer: ");
        } else break;
    }

    //call menu u (no loop pls)
}

