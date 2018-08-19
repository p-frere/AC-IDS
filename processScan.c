#include<stdio.h>
#include<stdlib.h> // for exit()
#include<sts_queue.h>
 
 struct packet
 {
    char* protocol;
 };
 

int processScan() {
  // Create queue
  StsHeader *handle = StsQueue.create();

  // Print stuff from queue
//    mem = StsQueue.pop(handle)
    

  // Kill queue
//  StsQueue.destroy(handle);

  return 0;
}

//https://github.com/petercrona/StsQueue
