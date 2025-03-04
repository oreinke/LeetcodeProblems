class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sub = 0;
        int ops = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > sub) {
                ops++;
                sub += nums[i] - sub;
            }
        }
        return ops;
    }
};