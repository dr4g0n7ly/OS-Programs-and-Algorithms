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

   //starting queue with mid value
   queue[q_top] = arr[n/2 - 1];
   q_top++;

   //sorting array
   for(int i = 0; i < n; i++) {
      for(int j = 1; j < n; j++) {
         if(arr[j-1] > arr[j]) {
            int p = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = p;
         }
      }
   }

   //finding position of starting cylinder in sorted array
   int pos;
   for(int i = 0; i < n; i++) {
      if(arr[i] == queue[q_top - 1]) {
         pos = i;
         break;
      }
   }

   //enqueuing positions larger than starting value
   for(int i = pos + 1; i < n; i++) {
      queue[q_top] = arr[i];
      q_top++;
   }

   //enqueuing positions smaller than starting value
   for(int i = pos - 1; i >= 0; i--) {
      queue[q_top] = arr[i];
      q_top++;
   }

   //printing the queue
   printf("\n queue: ");
   for(int i = 0; i < n; i++) {
      printf("%d ", queue[i]);
   }

   //calculating total seek distance
   int total_seek_distance = (arr[n-1] - queue[0]) + (arr[n-1] - queue[q_top - 1]);
   printf("\nTotal seek distance: %d", total_seek_distance);

   return 0;
}


/*


7
82
170
43
140
24
16
190

*/