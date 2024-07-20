class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        int[] newArray = new int[nums.length];

        for (int i = 0; i < nums.length; i++)
        {
            newArray[i] = nums[(i - k < 0) ? nums.length + i - k : i - k];
        }

        for (int i = 0; i < nums.length; i++)
            nums[i] = newArray[i];
    }
}