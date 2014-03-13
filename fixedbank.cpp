#include "fixedbank.h"

FixedBank::FixedBank(int initCoins) {
    coins = initCoins;
}

bool FixedBank::changeCoins(int change) {

    pthread_mutex_lock(&mut);
    //Specifially long winded to try and break it
    int curCoins = coins;
    int newCoins = curCoins + change;
    if(newCoins < 0) {
        printf("Not enough money, only %i in bank, tried to change by %i\n", coins, change);
        pthread_mutex_unlock(&mut);
        return false;
    }else{
        coins = newCoins;
        printf("Changed value in bank, Currently %i, previously %i\n", newCoins, curCoins);
        pthread_mutex_unlock(&mut);
        return true;
    }

}

int FixedBank::getCoins() {
    pthread_mutex_lock(&mut);
    return coins;
    pthread_mutex_unlock(&mut);
}
