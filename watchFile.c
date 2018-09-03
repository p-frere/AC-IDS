//
// Created by pea on 27/08/18.
//

#include "watchFile.h"

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )


int watchFile()
{

    int length, i = 0;
    int fileDescriptor;
    int watchDescriptor;
    char buffer[BUF_LEN];

    fileDescriptor = inotify_init();

    if ( fileDescriptor < 0 ) {
        perror( "inotify_init" );
    }

    watchDescriptor = inotify_add_watch( fileDescriptor, "/home/pea/Documents/temp",
                            IN_MODIFY | IN_CREATE | IN_DELETE );
    length = read( fileDescriptor, buffer, BUF_LEN );

    if ( length < 0 ) {
        perror( "read" );
    }

    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
        if ( event->len ) {
            if ( event->mask & IN_CREATE ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was created.\n", event->name );
                }
                else {
                    printf( "The file %s was created.\n", event->name );
                }
            }
            else if ( event->mask & IN_DELETE ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was deleted.\n", event->name );
                }
                else {
                    printf( "The file %s was deleted.\n", event->name );
                }
            }
            else if ( event->mask & IN_MODIFY ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was modified.\n", event->name );
                }
                else {
                    printf( "The file %s was modified.\n", event->name );
                }
            }
        }
        i += EVENT_SIZE + event->len;
    }

    ( void ) inotify_rm_watch( fileDescriptor, watchDescriptor );
    ( void ) close( fileDescriptor );

    detected("file system was changed");
    //exit( 0 );
}

int prepareWatch(){
    consolePrint("Which folder do you want to monitor? \nEnter an absolute address");

    char* name[100];
    scanf ("%[^\n]%*c", name);
    printf("%s\n",name);
    consolePrint("... Now Monitoring ...");
       watchFile();
}
