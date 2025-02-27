class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pre (n), candles, res(queries.size(), 0);

        pre[0] = 0;
        if (s[0] == '|') {
            candles.push_back(0);
        }
        else {
            pre[0]++;
        }
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1];
            if (s[i] == '*') {
                pre[i]++;
            }
            else {
                candles.push_back(i);
            }
        }
        if (!candles.empty()){
            for (int i = 0; i < queries.size(); ++i) {
                int l = queries[i][0];
                int r = queries[i][1];
                auto lCandle = lower_bound(candles.begin(), candles.end(), l);
                auto rCandle = upper_bound(candles.begin(), candles.end(), r) - 1;
                if (rCandle - lCandle > 0) {
                    res[i] = pre[*rCandle] - pre[*lCandle];
                }
            }
        }
        
        return res;
    }
};