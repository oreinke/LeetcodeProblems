class Solution {
public:
    bool valid (string str, unordered_set<string> &strs, unordered_map<string, bool> &dp) {
        if (dp.find(str) == dp.end()) {
            bool found = false;
            if (strs.count(str)) found = true;
            
            for (int i = 1; i < str.length() && !found; ++i) {    
                if (strs.count(str.substr(0, i)) && valid(str.substr(i), strs, dp)) {
                    found = true;
                }
            }
            dp[str] = found;
        }
        return dp[str];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, bool> dp;
        unordered_set<string> strs;
        unordered_set<string> res;

        for (string w : words) strs.insert(w);

        for (string w : strs) {
            bool found = false;
            for (int i = 1; i < w.length() && !found; ++i) {    
                if (strs.count(w.substr(0, i)) && valid(w.substr(i), strs, dp)) {
                    found = true;
                }
            }
            if (found) res.insert(w);       
        }
        
        vector<string> resArr;
        for (string str : res) resArr.push_back(str);

        return resArr;
    }
};