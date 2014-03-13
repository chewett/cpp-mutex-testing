#include <cstdio>
#include "brokenbank.h"


int main(void) {
    std::printf("Testing working\n");

    Bank b(10);
    Bank b2(50);
    printf("Coins in bank: %i\n", b.getCoins());

    return 0;
}
