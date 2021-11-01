#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *factorial() {
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int fact = 1;
    for(int i=1;i<n+1;i++) {
        fact *= i;
    }
    printf("factorial: %d\n",fact);
}

int main(){

    pthread_t p1;
    pthread_create(&p1, NULL, &factorial, NULL);
    pthread_join(p1, NULL);
    return 0;
}

/*

INSTRUCTIONS

gcc -pthread -o out factorial.c
./out

*/