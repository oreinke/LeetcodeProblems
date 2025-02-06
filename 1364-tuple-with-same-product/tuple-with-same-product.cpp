
class Solution {
public:
    


    int tupleSameProduct(vector<int>& nums) {

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