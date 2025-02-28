class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> cnt;
        for (int num : nums) {
            sum += num;
            cnt[num]++;
        }
        
        int best = -2e9;
        bool found = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[sum - nums[i] * 2] > 1 || ((sum - nums[i] * 2) != nums[i] && (cnt[sum - nums[i] * 2] > 0))) {
                if (sum - nums[i] * 2 > best || !found) {
                    found = true;
                    best = sum - nums[i] * 2;
                }
            }
        }

        return best;
    }
};