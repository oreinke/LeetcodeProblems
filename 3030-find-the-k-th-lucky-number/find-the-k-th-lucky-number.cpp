class Solution {
public:
    string kthLuckyNumber(int k) {
        string result = "";
        while (k > 0) {
            int n = 2;
            int remainder = 0;
            while (k > n) {
                k -= n;
                remainder += n;
                n *= 2;
            }
            n /= 2;
            remainder += k;
            if (k > n) {
                result += "7";
                remainder -= n;
            }
            else {
                result += "4";
            }
            remainder -= n;
            k = remainder;
        }

        return result;
    }
};