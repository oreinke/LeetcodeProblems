class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int best = 1;
        for (int i = 0;i < n - 1; ++i) {
            int len = 1;
            for (int j = i; j < n - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    len++;
                }
                else {
                    break;
                }
            }
            best = max(best, len);
        }

        for (int i = 0;i < n - 1; ++i) {
            int len = 1;
            for (int j = i; j < n - 1; ++j) {
                if (nums[j] < nums[j + 1]) {
                    len++;
                }
                else {
                    break;
                }
            }
            best = max(best, len);
        }
        return best;
    }
};