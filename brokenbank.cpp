#include "brokenbank.h"

Bank::Bank(int initCoins) {
    coins = initCoins;
}

bool Bank::changeCoins(int change) {

    //Specifially long winded to try and break it
    int curCoins = coins;
    int newCoins = curCoins + change;
    if(newCoins < 0) {
        printf("Not enough money, only %i in bank, tried to change by %i\n", coins, change);
        return false;
    }else{
        coins = newCoins;
        printf("Changed value in bank, Currently %i, previously %i\n", newCoins, curCoins);
        return true;
    }

}

int Bank::getCoins() {
    return coins;
}
