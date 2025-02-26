class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int longest = 0;
        unordered_set<string> bad;
        for (string f : forbidden) {
            if (f.size() > word.size()) continue;
            longest = max(longest, (int)f.size());
            bad.insert(f);
        }

        int left = 0, best = 0;
        for (int right = 0; right < word.length(); ++right) {
            // can optimize to constraint of longest
            for (int j = right; j >= left && right - j + 1 <= longest; --j) {
                if (bad.count(word.substr(j, right - j + 1))) {
                    left = j + 1;
                    
                }
                
            }
            if (right - left + 1 > best) {
                best = right - left +  1;
                //printf("%d, %d\n", left, right);
            }

        }

        return best;
    }
};