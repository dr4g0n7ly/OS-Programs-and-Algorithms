#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct process {
    int waitTime;
    int arrival_t;
    int burst_t,tat,priority;
};

struct process proc[10];

int main() {
    int n,temp[10],t,count=0,short_p;
    float total_wt=0,total_tat,avg_wt,avg_tat;
    printf("Enter the no of processes: ");
    scanf("%d",&n);

     for(int i=0;i<n;i++) {
         printf("\nEnter arrival time: \t");
         scanf("%d",&proc[i].arrival_t);
         printf("Enter burst time:\t");
         scanf("%d",&proc[i].burst_t);
         printf("Enter priority:      \t");
         scanf("%d",&proc[i].priority);
         temp[i]=proc[i].burst_t;
     }

    proc[9].priority=10000;
    for(t=0;count!=n;t++) {
        short_p=9;
        for(int i=0;i<n;i++) {
            if(proc[short_p].priority > proc[i].priority && proc[i].arrival_t <= t && proc[i].burst_t > 0) {
                short_p=i;
            }
        }
        proc[short_p].burst_t= proc[short_p].burst_t - 1;

        if(proc[short_p].burst_t == 0) {
            count++;
            proc[short_p].waitTime= t + 1 - proc[short_p].arrival_t - temp[short_p];
            proc[short_p].tat= t + 1 - proc[short_p].tat;
            total_wt= total_wt + proc[short_p].waitTime;
            total_tat+=proc[short_p].tat;
        }
    }

    printf("ID WT TAT \n");
    for(int i=0;i<n;i++) {
        printf("%d %d\t%d\n",i+1, proc[i].waitTime, proc[i].tat);
    }
    avg_wt=total_wt/n;
    avg_tat=total_tat/n;
    printf("Avg waiting time of the process is %f\n",avg_wt);
    printf("Avg turn around time of the process is %f\n",avg_tat);
    printf("\n\n");
    return 0;
}
