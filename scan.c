#include "main.h"
int main()
{
    int i, j, dir, numReq, size, initial, total = 0;
    int nums[100];

//inserting from file
    FILE *file = fopen("C:\\Users\\hp\\Desktop\\input.txt", "r");
    int fnum[100];

    int t = 0;
    int num;
    while (fscanf(file, "%d", &num) > 0)
    {
        fnum[t] = num;
        t++;
    }
    fclose(file);

    numReq = fnum[0];
    initial = fnum[1];
    size = fnum[2];
    dir = fnum[3];

    // printf("%d\n%d\n%d\n%d\n", numReq, initial, size, dir);

    for (i = 0; i < numReq; i++)
    {
        nums[i] = fnum[i + 4];
    }

    printf("the requests are\n");
    for (i = 0; i < numReq; i++)
    {
        printf("%d\n", nums[i]);
    }

// sort
    for (i = 0; i < numReq; i++)
    {
        for (j = 0; j < numReq - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp;
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int index;

    for (i = 0; i < numReq; i++)
    {
        if (initial < nums[i])
        {
            index = i;
            break;
        }
    }
    if (dir == 1)
    {
        for (i = index; i < numReq; i++)
        {
            {
                total = total + abs(nums[i] - initial);
                initial = nums[i];
            }
        }

        for (i = index - 1; i >= 0; i--)
        {
            total = total + abs(nums[i] - initial);
            initial = nums[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total = total + abs(nums[i] - initial);
            initial = nums[i];
        }

        for (i = index; i < numReq; i++)
        {
            total = total + abs(nums[i] - initial);
            initial = nums[i];
        }
    }

    printf("Total movement is %d", total);

    FILE *ptr = fopen("C:\\Users\\hp\\Desktop\\scan.txt", "w");
    fprintf(ptr, "Total movement is:  %d", total);
    fclose(ptr);

    return 0;
}
