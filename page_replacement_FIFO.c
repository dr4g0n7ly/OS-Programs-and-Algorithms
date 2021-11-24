#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct page {
   int data;
   int pos;
};

int main(){

   //initialization

   int n;
   printf("Enter number of page frames: ");
   scanf("%d",&n);

   int m;
   printf("Enter number of page references: ");
   scanf("%d",&m);

   int arr[m];
   for(int i = 0; i < m; i++) {
      printf("Enter page reference: ");
      scanf("%d",&arr[i]);
   }

   struct page seg[n];
   for(int i = 0; i < n; i++) {
      seg[i].data = -1;
      seg[i].pos = -1;
   }
   
   int hits = 0;

   //traversing through each page reference
   for(int i = 0; i < m; i++) {

      int flag = 0;
      for(int j = 0; j < n; j++) {

         //if hit
         if(seg[j].data == arr[i]) {
            flag = 1;
            hits++;
         }
      }


      //if miss
      if(flag == 0) {

         //finding the page that was added first
         int min_pos = 0;
         for(int j = 1; j < n; j++) {
            if(seg[min_pos].pos > seg[j].pos) {
               min_pos = j;
            }
         }

         //replacinng first added page with new page
         seg[min_pos].data = arr[i];
         seg[min_pos].pos = i;

      }

      //printing page segmentation after each iteration
      printf("\npage reference: %d",arr[i]);
      printf("\tpage segmentation: ");
      for(int j = 0; j< n; j++) {
         if(seg[j].pos == -1) {
            printf("_ ");
         }
         else {
            printf("%d ",seg[j].data);
         }
      }
   }

   //printing number of page faults
   int page_faults = m - hits;
   printf("\n\npage faults: %d",page_faults);
   
   return 0;
}


// 3
// 7
// 1
// 3
// 0
// 3
// 5
// 6
// 3