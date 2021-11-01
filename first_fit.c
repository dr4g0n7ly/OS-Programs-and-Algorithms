#include<stdio.h>
int main()
{
	int block_size[10], process_size[10], block_number, process_number, temp[10], allocated[10], i, j;
	for(i = 0; i < 10; i++)
	{
		temp[i] = 0;
		allocated[i] = -1;
	}
	printf("Enter no. of blocks: ");
	scanf("%d", &block_number);
	printf("Enter no. of processes: ");
	scanf("%d", &process_number);
	printf("Enter size of each block: \n");
	for(i = 0; i < block_number; i++)
	{
	    printf("Block no.%d: \t",i+1);
		scanf("%d", &block_size[i]);
	}
	printf("\nEnter size of each process: \n");
	for(i = 0; i < process_number; i++)
	{
	    printf("Process no.%d: \t",i+1);
		scanf("%d", &process_size[i]);
	}
	for(i = 0; i < process_number; i++)       
		for(j = 0; j < block_number; j++)
			if(temp[j] == 0 && block_size[j] >= process_size[i])
			{
				allocated[j] = i;
				temp[j] = 1;
				break;
			}
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize of process\t\tWasted memory");
	for(i = 0; i < block_number; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, block_size[i]);
		if(temp[i] == 1)
			printf("%d\t\t\t%d\t\t\t%d",allocated[i]+1,process_size[allocated[i]], block_size[i]-process_size[allocated[i]]);
		else
			printf("Not allocated\t\t\t-\t\t\t-");
	}
	printf("\n\n");
	return 0;
}
