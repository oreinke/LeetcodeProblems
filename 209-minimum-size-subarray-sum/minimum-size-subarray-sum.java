class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int min = Integer.MAX_VALUE;
        int j = 0;
        int runningTotal = nums[0];
        for (int i = 0; i < nums.length; i++)
        {
            if (i > 0)
                runningTotal -= nums[i - 1];

            if (runningTotal >= target)
            {
                while (j > i)
                {
                    if (runningTotal - nums[j] >= target)
                    {
                        runningTotal -= nums[j];
                        j--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (j - i + 1 < min)
                {
                    
                    min = j - i + 1;
                }
                if (min == 1)
                {
                    return 1;
                }
            }
            else
            {
                while (j < nums.length - 1)
                {
                    if (runningTotal < target)
                    {
                        j++;
                        runningTotal += nums[j];
                    }
                    else
                    {
                        break;
                    }
                }
                if (runningTotal >= target && j - i + 1 < min)
                    min = j - i + 1;

            }
        }
        if (min == Integer.MAX_VALUE)
            min = 0;
        return min;
    }
}