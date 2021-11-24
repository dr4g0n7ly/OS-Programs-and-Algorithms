#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct page {
   int data;
   int age;
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
      seg[i].age = 100;
   }
   
   int hits = 0;

   for(int i = 0; i < m; i++) {

      //checking if page is in page segmentation
      int flag = 0;
      for(int j = 0; j < n; j++) {

         //if hit
         if(seg[j].data == arr[i]) {
            flag = 1;
            seg[j].age = 0;
            hits++;
         }

         seg[j].age++;
      }

      //if miss
      if(flag == 0) {

         //finding lru page  
         int lru = 0;
         for(int j = 1; j < n; j++) {
            if(seg[lru].age < seg[j].age) {
               lru = j;
            }
         }

         //replacing lru page with new page
         seg[lru].data = arr[i];
         seg[lru].age = 0;

      }

      //printing page segmentation after each iteration
      printf("\npage reference: %d",arr[i]);
      printf("\tpage segmentation: ");
      for(int j = 0; j< n; j++) {
         if(seg[j].age > m+1) {
            printf("_ ");
         }
         else {
            printf("%d ",seg[j].data);
         }
      }
   }

   //printing page faults
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