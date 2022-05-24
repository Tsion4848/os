#include "main.h"
/**
 * sort - sorts the given numbers
 */

void sort()
{
	int i, j, head, dir, numReq, size, initial, total = 0;
	int nums[100];

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
}
