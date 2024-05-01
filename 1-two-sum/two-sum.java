class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> curNums = new HashMap<Integer, Integer>();
        int[] result = new int[2];

        curNums.put(nums[0], 0);
        for (int i = 1; i < nums.length; i++)
        {
            if (curNums.containsKey(target - nums[i]))
            {
                result[0] = curNums.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            else
            {
                curNums.put(nums[i], i);
            }
        }

        result[0] = -1;
        result[1] = -1;
        return result;
    }
}