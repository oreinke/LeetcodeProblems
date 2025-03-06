class Solution {
public:
    bool valid (int k, vector<int>& piles, int h) {
        if (k < 1) return false;
        for (int i = 0; i < piles.size() && h >= 0; ++i) {
            h -= piles[i] / k;
            if (piles[i] % k) h--;
        }
        if (h < 0) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = 0;
        sort(piles.rbegin(), piles.rend());
        high = piles[0];
        while (low < high) {
            int mid = (high + low) / 2 +  (((high + low) % 2) ? 1 : 0);
            // cout << low << " " << high << endl;
            // fflush(stdout);
            if (valid(mid, piles, h)) {
                if (!valid(mid - 1, piles, h)) return mid;
                high = mid;
            }
            else {
                low = mid;
            }
        }
        return low;
    }
};