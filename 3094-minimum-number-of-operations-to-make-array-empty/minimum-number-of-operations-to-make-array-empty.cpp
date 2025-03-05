class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) cnt[num]++;

        int total = 0;
        for (auto [x, y] : cnt) {
            if (y < 2) return -1;
            if (y % 2 == 1) {
                y -= 3;
                total++;
            }

            int num2s = y / 2;
            num2s -= num2s / 3;
            total += num2s;
        }
        return total;
    }
};