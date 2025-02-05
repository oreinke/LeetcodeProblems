class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ind1 = -1;
        int ind2 = -1;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]){
                if (ind1 == -1) {
                    ind1 = i;
                }
                else if (ind2 == -1) {
                    ind2 = i;
                }
                else {
                    return false;
                }
            }
        }

        
        if (ind1 == -1 && ind2 == -1) return true;
        if (ind2 == -1) return false;

        if (s1[ind1] == s2[ind2] && s1[ind2] == s2[ind1]) return true;
        return false;
      
    }
};