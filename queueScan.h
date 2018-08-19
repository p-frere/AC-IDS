//
// Created by pea on 19/08/18.
//

#ifndef AIDS_QUEUESCAN_H
#define AIDS_QUEUESCAN_H

#endif //AIDS_QUEUESCAN_H
#include<stdio.h>
#include<stdlib.h> // for exit()
#include "sts_queue.h"

struct packet{
    int protocolNo;
    int sourceIP;
};

int createQueue();
int pushQueue(int* ptr);
struct packet * popQueue();
int destoryQueue();