#include <cstdio>
#include <cstdlib>
#include "unistd.h"
#include "chopstick.h"

Chopstick chop[] = {Chopstick(0), Chopstick(1), Chopstick(2), Chopstick(3), Chopstick(4)};


void pickUp(int stick, int person) {
    chop[stick].pickUp(person);
    printf("{'p' : '%i', 'c' : '%i', 'type': 'up'}\n", person, stick);
}

void putDown(int stick, int person) {
    printf("{'p' : '%i', 'c' : '%i', 'type' : 'down'}\n", person, stick);
    chop[stick].putDown();
}


void* person(void* args) {
    int value = *(int*)(&args);
    int times = 0;
    while(times < 6) {
        times++;
        if(value == 0) {

        //printf("p:%i picking up\n", value);
        pickUp((value) % 5, value);
        pickUp((value + 4) % 5, value);
        printf("{'p' : '%i', 'eat': True}\n", value);
        sleep(0);
        //printf("p:%i start putting down\n", value);
        putDown((value) % 5, value);
        putDown((value + 4) % 5, value);
        printf("{'p' : '%i', 'think' : True}\n", value);
        sleep(0);
        }else{
            pickUp((value+ 4) % 5, value);
            pickUp((value) % 5, value);
            printf("{'p' : '%i', 'eat': True}\n", value);
            sleep(1);
            //printf("p:%i start putting down\n", value);
            putDown((value + 4) % 5, value);
            putDown((value) % 5, value);
            printf("{'p' : '%i', 'think' : True}\n", value);
            sleep(1.5);
        }

    }

    pthread_exit(NULL);
}

int main(void) {
    printf("Testing working\n");

    pthread_t threads[5];
    for(int i = 0; i<5; i++) {
        (void)pthread_create(&threads[i], NULL, person, (void*)i);
    }

    pthread_exit(NULL);

    return 0;
}
