#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t pid = fork();
    printf("This is process with PID: %d\n", getpid());
    if(pid == 0) {
        printf("This is child with PID %d\n", getpid());
    }
    else if(pid>0) {
        printf("This is the parent with PID %d\n", getpid());
    }
    return 0;
}