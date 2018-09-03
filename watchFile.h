//
// Created by pea on 27/08/18.
//

#ifndef ACIDS_WATCHFILE_H
#define ACIDS_WATCHFILE_H

#endif //ACIDS_WATCHFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "detected.h"

int watchFile();
int prepareWatch();
