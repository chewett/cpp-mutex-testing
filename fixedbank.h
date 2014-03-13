#include <cstdio>
#include "pthread.h"

#ifndef FIXEDBANK_H_
#define FIXEDBANK_H_

class FixedBank {

    private:
        int coins;
        pthread_mutex_t mut;

    public:
        FixedBank(int);
        bool changeCoins(int);
        int getCoins();

};
#endif
