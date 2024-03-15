int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int pad = 0;

    while ((i + pad) < numsSize)
    {
        if (nums[i + pad] == val)
        {
            pad++;
        }
        else
        {
            nums[i] = nums[i + pad];
            i++;
        }
    }
    return i;
}