void jumpRecursion(int* nums, long* numJumps, long numsSize, int index, long jumps)
{
    long i;

    if (index >= numsSize)
    {
        return;
    }

    if (numJumps[index] == -1 || numJumps[index] > jumps)
    {
        numJumps[index] = jumps;

        for (i = nums[index]; i > 0; i--)
        {
            jumpRecursion(nums, numJumps, numsSize, index + i, jumps + 1);
        }
    }
}

int jump(int* nums, int numsSize) {
    int i;
    long* numJumps = malloc(sizeof(long) * numsSize);

    for (i = 0; i < numsSize; i++)
    {
        numJumps[i] = -1;
    }

    jumpRecursion(nums, numJumps, numsSize, 0, 0);

    return numJumps[numsSize - 1];
}

