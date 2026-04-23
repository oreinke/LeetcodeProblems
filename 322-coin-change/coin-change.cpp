class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        vector<long long> dp (amount + 1, 1e18);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins)
                if (c <= i) dp[i] = min(dp[i], 1 + dp[i - c]);
        }

        if (dp[amount] == 1e18) return -1;
        return dp[amount];

    }
};