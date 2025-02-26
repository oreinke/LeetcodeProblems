class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int big = nums[0], bigI = 0, small = nums[0], smallI = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < small) {
                small = nums[i];
                smallI = i;
            }

            if (nums[i] >= big) {
                big = nums[i];
                bigI = i;
            }
        }
        int res = 0;
        if (bigI < smallI) res -= 1;
        res += smallI;
        res += nums.size() - 1 - bigI;
        return res;
    }
};