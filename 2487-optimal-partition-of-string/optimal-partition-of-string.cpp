class Solution {
public:
    int partitionString(string s) {
        vector<bool> seen (26, false);
        int cnt = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (seen[s[i] - 'a']) {
                cnt++;
                for (int j = 0; j < 26; ++j) seen[j] = false;
                seen[s[i] - 'a'] = true;
            }
            else {
                seen[s[i] - 'a'] = true;
            }
        }
        return cnt;
    }
};