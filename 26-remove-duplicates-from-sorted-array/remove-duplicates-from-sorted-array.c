int removeDuplicates(int* nums, int numsSize) {
    int shift = 0;
    int i;


    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1 - shift])
            shift++;
        else
        {
            nums[i - shift] = nums[i];
        }
    }

    return numsSize - shift;
}