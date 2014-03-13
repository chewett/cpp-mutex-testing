#ifndef BANK_H_
#define BANK_H_

class Bank {

    private:
        int coins;

    public:
        Bank(int);
        bool changeCoins(int);
        int getCoins();

};
#endif
