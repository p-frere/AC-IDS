#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>

#define clear() printf("\033[H\033[J")
#define consoleGoto(x,y) printf("\033[%d;%dH", (x), (y))
#define consoleGotoX(x) printf("\033[%dC", (x)); 

int consolePrint(char* string){
    consoleGotoX(15);
    printf("%s\n", string);
    return 4;
}

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
    consolePrint("║ 0. Start Scan & Detection        ║");
    consolePrint("║ 1. Test attack commands          ║");
    consolePrint("║ 2. Log files                     ║");
    consolePrint("║ 3. Quit                          ║");
    consolePrint("╚══════════════════════════════════╝");

    switch (menu()){
        case 0:
            printf("Starting scan...\n");
            break;
        case 1:
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

