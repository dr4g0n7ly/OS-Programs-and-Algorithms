#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *routine() {
    printf("Thread test\n");
    sleep(3);
    printf("Ending\n");
}

int main(){

    pthread_t p1, p2;
    pthread_create(&p1, NULL, &routine, NULL);
    pthread_create(&p2, NULL, &routine, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}

/*

INSTRUCTIONS

gcc -pthread -o out basics_of_pthread.c
./out

*/