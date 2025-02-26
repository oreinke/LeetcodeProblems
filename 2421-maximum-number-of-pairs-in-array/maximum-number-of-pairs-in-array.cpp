class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res (2, 0);
        unordered_map<int, int> rem;
        for (int num : nums) {
            if (rem[num] == 1) {
                rem[num] = 0;
                res[0]++;
                res[1]--;
            }
            else {
                rem[num] = 1;
                res[1]++;
            }
        }
        return res;
    }
};