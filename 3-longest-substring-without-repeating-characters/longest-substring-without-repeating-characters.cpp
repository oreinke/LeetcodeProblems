class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int best = 1;
        int left = 0, right = 0;
        int cntBad = 0;
        unordered_map<char, int> freq;
        freq[s[0]]++;
        while (right < s.length()) {
            if (cntBad == 0) {
                if (right - left + 1 > best) {
                    best = right - left + 1;
                    // printf("left: %d, right: %d\n", left, right);
                }
                right++;
                if (right != s.length()) {
                    freq[s[right]]++;
                    if (freq[s[right]] > 1) {
                        cntBad++;
                    }
                }              
            }
            else {
                freq[s[left]]--;
                if (freq[s[left]] == 1) cntBad--;
                left++;
            }
        }
        return best;
    }
};