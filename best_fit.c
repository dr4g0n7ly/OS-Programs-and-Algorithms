#include<stdio.h>
#include<math.h>
int main () {
    int fragment[20], block_size[20], process_size[20], i, j, block_number, process_number, temp, lowest =10000;
    static int flag[20], allocated[20];
    printf ("Enter the number of blocks:");
    scanf ("%d", &block_number);
    printf ("Enter the number of processes:");
    scanf ("%d", &process_number);
    printf ("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= block_number; i++) {
       printf ("Block no.%d:", i);
       scanf ("%d", &block_size[i]);
    }
    printf ("\nEnter the size of the processes :-\n");
    for (i = 1; i <= process_number; i++) {
        printf ("Process no.%d:", i);
        scanf ("%d", &process_size[i]);
    }
    
    for (i = 1; i <= process_number; i++) {
        for (j = 1; j <= block_number; j++) {
	        if (flag[j] != 1) {
	            temp = block_size[j] - process_size[i];
	            if (temp >= 0)
		            if (lowest > temp) {
		                allocated[i] = j;
		                lowest = temp;
		            }
	        }
	    }
        fragment[i] = lowest;
        flag[allocated[i]] = 1;
        lowest = 10000;
    }
	printf ("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tWasted_size");
    for (i = 1; i<=process_number ; i++) {
    	if (allocated[i] != 0) 
       		printf ("\n\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", i, process_size[i], allocated[i],block_size[allocated[i]],fragment[i]);
       	
       	else if (allocated[i] == 0)
       		printf ("\n\t%d\t\t%d\tNot Allocated\t\t-\t\t\t-", i, process_size[i]);
    }
    
    
    for (i=1; i<=block_number; i++) {
    	if (flag[i] != 1)
    		printf("\nNot Allocated\t\t-\t\t%d\t\t%d\t\t\t%d", i,block_size[i], block_size[i]);
	}

    printf("\n\n");
    return 0;
}
