#include <cstdio>
#include <cstdlib>
#include "pthread.h"
#include "unistd.h"
#include "chopstick.h"

Chopstick chop[] = {Chopstick(0), Chopstick(1), Chopstick(2), Chopstick(3), Chopstick(4)};

pthread_mutex_t sticks[5];

void pickUp(int stick, int person) {
    pthread_mutex_lock(&sticks[stick]);
    printf("p:%i c:%i picking\n", person, stick);
}

void putDown(int stick, int person) {
    printf("p:%i c:%i dropping\n", person, stick);
    pthread_mutex_unlock(&sticks[stick]);
}


void* person(void* args) {
    int value = *(int*)(&args);
    while(true) {
        printf("p:%i picking up\n", value);
        pickUp((value + 1) % 5, value);
        pickUp((value + 4) % 5, value);
        printf("p:%i im eating, number\n", value);
        sleep(1);
        printf("p:%i start putting down\n", value);
        putDown((value + 1) % 5, value);
        putDown((value + 4) % 5, value);
        printf("p:%i thinking\n", value);
        sleep(1.5);
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
