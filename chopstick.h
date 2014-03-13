#include <cstdio>
#include "pthread.h"

#ifndef CHOPSTICK_H_
#define CHOPSTICK_H_

class Chopstick {

    private:
        pthread_mutex_t mut;
        int owner;
        int chopId;

    public:
        Chopstick(int chopId);
        void pickUp(int);
        void putDown();
};
#endif
