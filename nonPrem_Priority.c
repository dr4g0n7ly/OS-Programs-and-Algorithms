#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     int execution_t[20], arrival_t[10], n, temp, priority[10], st[10], ft[10], waiting_t[10], ta[10];
     int t=0,total_wait=0,totta=0;
     float awt,ata;
     int proc_name[10];
     printf("Enter the number of process:");
     scanf("%d",&n);

     for(int i=0;i<n;i++) {
         printf("\nEnter process name:\t");
         scanf("%d",&proc_name[i]);
         printf("Enter arrival time: \t");
         scanf("%d",&arrival_t[i]);
         printf("Enter execution time:\t");
         scanf("%d",&execution_t[i]);
         printf("Enter priority:      \t");
         scanf("%d",&priority[i]);
     }

    printf("\n");

     for(int i=0;i<n;i++) {
         for(int j=0;j<n;j++) {
             if(priority[i] < priority[j]) {
                 temp=priority[i];
                 priority[i]=priority[j];
                 priority[j]=temp;
                 temp=arrival_t[i];
                 arrival_t[i]=arrival_t[j];
                 arrival_t[j]=temp;
                 temp=execution_t[i];
                 execution_t[i]=execution_t[j];
                 execution_t[j]=temp;
                 t=proc_name[i];
                 proc_name[i]=proc_name[j];
                 proc_name[j]=t;
             }
         }
     }

     for(int i=0;i<n;i++) {
         if(i==0) {
             st[i]=arrival_t[i];
             waiting_t[i]= arrival_t[i] - arrival_t[i];
             ft[i]= st[i] + execution_t[i];
             ta[i]= ft[i] - arrival_t[i];
         }
         else {
             st[i]=ft[i-1];
             waiting_t[i]= st[i] - arrival_t[i];
             ft[i]= st[i] + execution_t[i];
             ta[i]= ft[i] - arrival_t[i];
         }
         total_wait+=waiting_t[i];
         totta+=ta[i];
     }
     awt= (float)total_wait / n;
     ata=(float)totta/n;
     printf("\nPname\tarrival time\texecution time\tpriority\twaiting time\ttime\n");
     for(int i=0;i<n;i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc_name[i], arrival_t[i], execution_t[i], priority[i], waiting_t[i], ta[i]);
     printf("\nAverage waiting time is : %f",awt);
     printf("\nAverage turnaround time is: %f",ata);
     printf("\n");
     printf("\n");
    return 0;   
}
