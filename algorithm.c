#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, j, head, dir, numReq, size, initial, total = 0;
int nums[100];

void input()
{
	printf("Enter the number of Tracks\n");
	scanf("%d", &numReq);
	printf("Enter initial head position\n");
	scanf("%d", initial);
	printf("Enter total disk size\n");
	scanf("%d", &size);
	printf("Enter the head movement direction, 1 for up and 0 for n down\n");
	scanf("%d", &dir);
	printf("Enter the requests sequence\n");
	for (i = 0 ; i < numReq ; i++)
	{
		scanf("%d", &nums[i]);
	}
}

void sort()
{
	for (i = 0 ; i < numReq ; i++)
	{
		for (j = 0 ; j < i-1 ; j++)
		{
			if (nums[j] > nums[j+1])
			{
				int temp;
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}

void sort();

void scan()
{
	int index;
	for (i = 0 ; i < numReq ; i++)
	{
		if (initial < nums[i])
		{
			index = i;
			break;
		}
	}

	sort();

	if (dir == 1){
		for (i = index ; i < numReq ; i++)
		{
			{
				total = total + abs(nums[i]-initial);
				initial = nums[i];
			}
		}
		total = total + abs(size-nums[i-1]-1);
		initial = size - 1;
		
		for (i = index-1 ; i >= 0 ; i--)
		{
			total = total + abs(nums[i]-initial);
			initial = nums[i];
		}
	}
	else
	{
		for (i = index-1 ; i>=0 ; i--)
		{
			total = total + abs(nums[i]-initial);
			initial = nums[i];
		}
		total = total + abs(nums[i+1] - nums[i]);
		initial = nums[i+1];

		for (i = index ; i < numReq ; i++)
		{
			total = total + abs(nums[i]-initial);
			initial = nums[i];
		}
	}
	printf("Total movement is %d", total);
}
	
void input();
void scan();

int main()
{
	int choice;

	printf("Insert your choice\n");
	scanf("%d", choice);

	switch(choice)
	{
		case 1: printf("1: INPUT\n");
			input();
			break;
		case 2: printf("2:SCAN\n");
			scan();
			break;
		default: printf("Invalid input");
	}
	return 0;
}







