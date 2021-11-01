#include<stdio.h>
#include<math.h>
int main () {
    int i, j, block_number, process_number, f, temp=0;
    int block_size[20];
    int flag[20], allocated[20];
    printf ("Enter the number of blocks: ");
    scanf ("%d", &block_number);

    for (i=0;i<block_number;i++)
    	allocated[i] = 0;
    
	printf ("Enter the number of processes : ");
    scanf ("%d", &process_number);
    int process_size[process_number], wasted_memory[process_number];
    
	printf ("\n\nEnter the size of the blocks :-\n");
    for (i=1; i<=block_number; i++) {
       printf ("Block number %d : ", i);
       scanf ("%d", &block_size[i]);
    }
    
    printf ("\n\nEnter the size of the processes :-\n");
    for (i=1; i<=process_number; i++) {
        printf ("Process number %d : ", i);
        scanf ("%d", &process_size[i]);
    }
    
	for (i = 1; i <= process_number; i++) {
        for (j = 1; j <= block_number; j++) {
	        if (flag[j] != 1) {
	            f = block_size[j] - process_size[i];
	            if (f >= 0)
		            if(temp < f) {
                        allocated[i] = j;
                        temp = f;
					}
	        }
	    }
        wasted_memory[i] = temp;
        flag[allocated[i]] = 1;
        temp = 0;
    }
    
    printf ("\n\nProcess Number\tProcess Size\tHole Number\tMemory Hole Size\tWasted Memory");
    for (i = 1; i<=process_number ; i++) {
    	if (allocated[i] != 0) 
       		printf ("\n\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", i, process_size[i], allocated[i], block_size[allocated[i]],wasted_memory[i]);
       	
       	else if (allocated[i] == 0)
       		printf ("\n\t%d\t\t%d\tNot Allocated\t\t-\t\t\t-", i, process_size[i]);
    }
    
    
    for (i=1; i<=block_number; i++) {
    	if (flag[i] != 1)
    		printf("\nNot Allocated\t\t-\t\t%d\t\t%d\t\t\t%d", i, block_size[i], block_size[i]);
	}

    printf("\n\n");
	return 0;
}
