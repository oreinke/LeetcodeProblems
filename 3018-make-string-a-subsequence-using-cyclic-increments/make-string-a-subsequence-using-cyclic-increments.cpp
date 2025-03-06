class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2i = 0;
        for (int i = 0; i < str1.length() && str2i < str2.length(); ++i) {
            int curChar2 = (str2[str2i] - 'a');
            int curChar1 = (str1[i] - 'a');
            if (curChar1 == curChar2 || ((curChar1 + 1) % 26) == curChar2) {
                str2i++;
            }
        }
        if (str2i < str2.length()) return false;
        return true;
    }
};