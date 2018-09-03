#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>
#include "portScan.h"
#include "watchFile.h"
#include "consoleUtilities.h"

//Returns menu selection
int menu(){   
    char *p, s[100];
    int num;
    printf("Enter a menu selection: \n");
    while (fgets(s, sizeof(s), stdin)) {
        num = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }
    return num;
}

int main(){
    //Title  Screen
    clear();
    printf("\n\n");
    consolePrint(" ▄▄▄·  ▄▄· ▪  ·▄▄▄▄  .▄▄ ·");
    consolePrint("▐█ ▀█ ▐█ ▌▪██ ██▪ ██ ▐█ ▀.");
    consolePrint("▄█▀▀█ ██ ▄▄▐█·▐█· ▐█▌▄▀▀▀█▄");
    consolePrint("▐█ ▪▐▌▐███▌▐█▌██. ██ ▐█▄▪▐█");
    consolePrint(" ▀  ▀ ·▀▀▀ ▀▀▀▀▀▀▀▀•  ▀▀▀▀");
    consolePrint(" A Crude Intrusion Detection System");
    printf("\n");

    consolePrint("╔══════════════════════════════════╗");
    consolePrint("║ 0. Network Threat Detection      ║");
    consolePrint("║ 1. File Modification Detection   ║");
    consolePrint("║ 2. Log files                     ║");
    consolePrint("║ 3. Quit                          ║");
    consolePrint("╚══════════════════════════════════╝");

    switch (menu()){
        case 0:
            portScan();
            break;
        case 1:
            prepareWatch();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Quitting...\n");
            break;
    }
}

