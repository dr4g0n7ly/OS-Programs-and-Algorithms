#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){

   //initialization
   int n;
   printf("Enter number of cylinders: ");
   scanf("%d",&n);

   int arr[n];

   for(int i = 0; i < n; i++) {
      printf("Enter cylinder: ");
      scanf("%d",&arr[i]);
   }

   int queue[n];
   int q_top = 0;

   //starting queue with middle cylinder
   queue[q_top] = arr[n/2 - 1];
   q_top++;

   int total_seek_distance = 0;

   while(q_top != n) {

      int min = n+1;
      printf("\nyay\n");

      for(int i = 0; i < n; i++) {

         //checking if cylinder has already been completed
         int check = 0;
         for(int j = 0; j <= q_top; j++) {
            if(queue[j] == arr[i]) {
               check = 1;
            }
         }

         //finding minimum seek
         if(check == 0) {
            if(abs(queue[q_top - 1] - arr[i]) < abs(queue[q_top - 1] - arr[min])) {
               min = i;
            }
            printf("%d %d\n", check, abs(queue[q_top - 1] - arr[i]));
         }
         else {
            printf("%d -\n",check);
         }

      }

      printf("\n");

      //updating total seek distance
      total_seek_distance += abs(queue[q_top - 1] - arr[min]);

      //updating queue
      queue[q_top] = arr[min];
      q_top++;
   }

   //printing the queue
   for(int i = 0; i < n; i++) {
      printf("%d ", queue[i]);
   }

   //printing total seek distance
   printf("\nTotal seek distance: %d", total_seek_distance);

   return 0;
}


/*

6
122
83
45
178
64
190

*/
