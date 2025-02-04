class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int start = 0;
        bool found = false;
        while (prev < start && !found) {
            prev = start;
            bool bad = false;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[(start + i) % n] > nums[(i + start+ 1) % n]) {
                    bad = true;
                    start = (i + start + 1) % n;
                    break;
                }
                
            }
            if (!bad) {
                found = true;
            }
        }
        return found;
    }
};