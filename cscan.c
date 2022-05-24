#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j, head, dir, numReq, size, initial, total = 0;
	int nums[100]
	
	printf("Enter the number of Tracks\n");
        scanf("%d", &numReq);
        printf("Enter initial head position\n");
        scanf("%d", &initial);
        printf("Enter total disk size\n");
        scanf("%d", &size);
        printf("Enter the head movement direction, 1 for up and 0 for n down\n");
        scanf("%d", &dir);
        printf("Enter the requests sequence\n");
        for (i = 0 ; i < numReq ; i++)
        {
                scanf("%d", &nums[i]);
        }

	for (i = 0 ; i < numReq ; i++)
        {
                for (j = 0 ; j < numReq-i-1 ; j++)
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

	int index;

        for (i = 0 ; i < numReq ; i++)
        {
                if (initial < nums[i])
                {
                        index = i;
                        break;
                }
        }
	
	if (dir == 1)
        {
                for (i = index ; i < numReq ; i++)
                {
                        {
                                total = total + abs(nums[i]-initial);
                                initial = nums[i];
                        }
                }
                total = total + abs(size-nums[i-1]-1);
		total = total + abs(size-1-0);
		initial = 0;

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
		total = total + abs(nums[i+1]-0);
		total = total + abs(size-1-0);
		initial = size-1;
		
		for (i = numReq-1 ; i >= index ; i--)
		{
			total = total + abs(nums[i]-initial);
			initial = nums[i];
		}
	}
	printf("Total movement is %d", total);
	return 0;
}
