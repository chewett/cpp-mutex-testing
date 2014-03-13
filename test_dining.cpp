#include <cstdio>
#include <cstdlib>
#include "pthread.h"
#include "unistd.h"
#include "chopstick.h"

Chopstick chop[] = {Chopstick(0), Chopstick(1), Chopstick(2), Chopstick(3), Chopstick(4)};


void* person(void* args) {
    int value = *(int*)(&args);
    while(true) {
        printf("p:%i picking up\n", value);
        chop[value + 1 % 5].pickUp(value);
        chop[value + 4 % 5].pickUp(value);
        printf("p:%i im eating, number\n", value);
        sleep(1000);
        printf("p:%i putting down\n", value);
        chop[value + 1 % 5].putDown();
        chop[value + 4 % 5].putDown();
        printf("p:%i thinking\n", value);
        sleep(1500);
    }

    pthread_exit(NULL);
}

int main(void) {
    std::printf("Testing working\n");

    pthread_t threads[5];
    
    for(int i = 0; i<5; i++) {
        (void)pthread_create(&threads[i], NULL, person, (void*)i);
    }

    pthread_exit(NULL);

    return 0;
}
