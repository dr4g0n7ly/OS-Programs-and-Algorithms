#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct process {
    int id,arrival_t,burst_t,waiting_t,tat;
};

struct process a[10];
int queue[100];
int front =-1;
int rear=-1;

void insert(int n) {
    if(front==-1)
        front=0;
    rear=rear+1;
    queue[rear]=n;
}

int delete() {
    int n;
    n=queue[front];
    front=front+1;
    return n;
}

int main() {
    int n,timeq,p,time=0;
    int temp[10],exists[10]={0};
    float total_waiting_t,total_turn_at,avg_wt,avg_tat;
    printf("enter the no of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        printf("\nEnter the arrival time: ");
        scanf("%d",&a[i].arrival_t);
        printf("Enter the burst time: ");
        scanf("%d",&a[i].burst_t);
        a[i].id=i;
        temp[i]=a[i].burst_t;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&timeq);
    insert(0);
    exists[0]=1;
    while(front<=rear) {
        p=delete();
        if(a[p].burst_t>=timeq) {
            a[p].burst_t=a[p].burst_t-timeq;
            time=time+timeq;
        }
        for(int i=0;i<n;i++) {
            if(exists[i]==0 && a[i].arrival_t<=time) {
                insert(i);
                exists[i]=1;
            }
        }
        if(a[p].burst_t==0) {
            a[p].tat=time-a[p].arrival_t;
            a[p].waiting_t=a[p].tat-temp[p];
            total_turn_at=total_turn_at+a[p].tat;
            total_waiting_t=total_waiting_t+a[p].waiting_t;
        }
        else {
            insert(p);
        }
    }
    avg_tat=total_turn_at/n;
    avg_wt=total_waiting_t/n;
    printf("ID\tWT\tTAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",a[i].id,a[i].waiting_t,a[i].tat);
    }
    printf("Average waiting time of the processes is : %f\n",avg_wt);
    printf("Average turn around time of the processes is : %f\n",avg_tat);
    printf("\n\n");
    return 0;
}
