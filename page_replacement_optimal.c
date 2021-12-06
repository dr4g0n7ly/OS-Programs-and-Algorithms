#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct page {
   int data;
   int next_pos;
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
      seg[i].next_pos = 100;
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

         // //finding nex occurance of each page in the segmentation
         // for(int j = 0; j < n; j++) {
         //    seg[j].next_pos = m + 1;
         //    for(int k = i; k < m; i++) {
         //       if(seg[j].data == arr[k]) {
         //          seg[j].next_pos = k;
         //       }
         //    }
         // }

         //finding maximum next position 
         int max_next_pos = 0;
         for(int j = 1; j < n; j++) {
            if(seg[max_next_pos].next_pos < seg[j].next_pos) {
               max_next_pos = j;
            }
         }

         //replacinng first added page with new page
         seg[max_next_pos].data = arr[i];
         int pos = m + 1;
         for(int j = i + 1; j < m; j++) {
            if(seg[max_next_pos].data == arr[j]) {
               pos = j;
            }
         }
         seg[max_next_pos].next_pos = i;

      }

      //printing page segmentation after each iteration
      printf("\npage reference: %d",arr[i]);
      printf("\tpage segmentation: ");
      for(int j = 0; j< n; j++) {
         if(seg[j].next_pos > m) {
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

/*
4
13
7
0
1
2
0
3
0
4
2
3
0
3
2

*/