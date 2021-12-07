#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front = -1;
int rear = -1;

struct process {
    int name;
    int a_time;
    int b_time;
    int w_time;
    int t_time;
};

struct process queue[10];

void enqueue(int name, int b_time) {
    if(front==-1 && rear==-1) {
        front = 0;
        rear = 0;
        queue[rear].name = name;
        queue[rear].b_time = b_time;
    }
    else {
        rear++;
        queue[rear].name = name;
        queue[rear].b_time = b_time;
    }
    queue[rear].a_time = 0; 
}

void timing() {
    queue[0].w_time = 0;
    queue[0].t_time = queue[0].b_time;
    for(int i=1;i<rear+1;i++) {
        queue[i].w_time = queue[i-1].w_time + queue[i-1].b_time;
        queue[i].t_time = queue[i].w_time + queue[i].b_time - queue[i].a_time;
    }
}

void q_sort() {
    for (int i = 0; i < rear; i++)  {  
        for (int j = 0; j < rear-i; j++) {
            if (queue[j].b_time > queue[j+1].b_time) {
                struct process temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }
}

void display() {
    q_sort();
    timing();
    if(front==-1 && rear==-1) {
        printf("Queue is empty");
    }
    else {
        printf("\nFCFS:\n");
        printf("process:\tburst time:\twaiting time:\tturn-around time:\n");
        for(int i=front;i<rear+1;i++) {
            printf("p%d\t\t%d\t\t%d\t\t%d\n", queue[i].name, queue[i].b_time, queue[i].w_time, queue[i].t_time);
        }
        printf("\n");
    }
}

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
  
    for(int i=0;i<n;i++) {
        int p;
        int b;
        printf("Enter process number: ");
        scanf("%d",&p);
        printf("Enter process burst time: ");
        scanf("%d",&b);
        enqueue(p,b);
    }

    display();
    
}

/*

5
1
4
2
5
3
2
4
6
5
3


*/
