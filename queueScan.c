//
// Created by pea on 19/08/18.
//

#include "queueScan.h"

//needs value from create
StsHeader* handle = 0;

int createQueue() {
    // Create queue
    //creates the queue at a memory adress
    StsHeader *handle = StsQueue.create();
    return 0;
}

int pushQueue(int* ptr) {
    //push to queue, passes queue and adress of item
    StsQueue.push(handle, ptr);
    return 0;
}

// Print stuff from queue, returns a (void?) pointer to content
struct packet * popQueue() {
    struct packet *packet_ptr;
    if ( (packet_ptr = StsQueue.pop(handle)) != NULL) {
        return packet_ptr;
    } else {
        return NULL;
    }
}

 // Kill queue
int destoryQueue() {
     StsQueue.destroy(handle);
     return 0;
}
