#include <cstdio>
#include "pthread.h"
#include "brokenbank.h"

#define TRANS_NO 10

Bank b(1000);

void* transaction(void* args) {
    int value = *(int *)args;
    b.changeCoins(value);
    pthread_exit(NULL);
}

int main(void) {
    std::printf("Testing working\n");

    int values[TRANS_NO] = {-500, 1000, -1500, 300, -2000, -5000, 1000, 1500, 2000, -1000};
    pthread_t threads[TRANS_NO];
    
    for(int i = 0; i<TRANS_NO; i++) {
        (void)pthread_create(&threads[i], NULL, transaction, &values[i]);
    }

    pthread_exit(NULL);

    return 0;
}
