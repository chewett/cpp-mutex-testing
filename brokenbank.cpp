#include "brokenbank.h"

Bank::Bank(int initCoins) {
    coins = initCoins;
}

bool Bank::changeCoins(int change) {

    //Specifially long winded to try and break it
    int curCoins = coins;
    int newCoins = curCoins + change;
    if(newCoins < 0) {
        return false;
    }else{
        coins = newCoins;
        return true;
    }

}

int Bank::getCoins() {
    return coins;
}
