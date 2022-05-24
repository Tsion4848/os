#include "main.h"
/**
 * scan - this is the algorithm to get the total time
 * it takes to move
 */

void scan()
{
	int i, j, head, dir, numReq, size, initial, total = 0;
	int nums[100];
	int index;

	input();
        sort();

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
                total = total + abs(nums[i+1] - 0);
                initial = 0;

                for (i = index ; i < numReq ; i++)
                {
                        total = total + abs(nums[i]-initial);
                        initial = nums[i];
                }
        }
        printf("Total movement is %d", total);
}
