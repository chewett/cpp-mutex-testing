#include "chopstick.h"

Chopstick::Chopstick(int id) {
    chopId = id;
    owner = -1;
}

void Chopstick::pickUp(int personId) {
    pthread_mutex_lock(&mut);
    printf("p: %i c:%i picking up\n", personId, chopId);
    if(owner != -1) {
        printf("p:%i c:%i MAJOR ISSUES, ALREADY OWNED\n",personId, chopId);
    }

    owner = personId;
}

void Chopstick::putDown() {
    printf("p:%i c:%i putting down\n", owner, chopId);
    owner = -1;
    pthread_mutex_unlock(&mut);
}

