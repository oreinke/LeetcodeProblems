class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> freq (26, 0);
        for (char c : s) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());

        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result += freq[i] * ((i / 9) + 1);
        }

        return result;
    }
};