typedef unsigned long long ull;

class Solution {
public:
    
    ull factorial (int n, map<ull, ull> &fact) {
        if (fact.find(n) != fact.end()) return fact[n];
        else return factorial(n - 1, fact) * n;
    }

    int tupleSameProduct(vector<int>& nums) {
        map<ull, ull> fact;
        fact[1] = 1;
        fact[0] = 1;
        map<int, int> products;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                products[nums[i] * nums[j]]++;
            }
        }

        long long cnt = 0;
        for (auto [x, y] : products) {
            if (y > 1) {
                cnt += y * (y - 1) / 2;
            }
        }
        return cnt * 8;
    }
};