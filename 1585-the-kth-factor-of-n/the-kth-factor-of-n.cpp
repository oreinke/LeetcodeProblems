class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors1;
        vector<int> factors2;
        
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                factors1.push_back(i);
                if (n / i != i) factors2.push_back(n / i);
            }
        }

        if (factors1.size() + factors2.size() < k) return -1;
        if (factors1.size() >= k) return factors1[k - 1];
        return factors2[factors2.size() - (k - factors1.size())];
        
    }
};