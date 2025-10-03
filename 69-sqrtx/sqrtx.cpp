class Solution {
public:
    int mySqrt(int x) {
        double hi = x, lo = 0;
        while (abs(hi - lo) > 1e-6) {
            double mid = lo + (hi - lo) / 2;
            if (mid * mid < x) 
                lo = mid;
            else 
                hi = mid;
        }
        return (int)hi;
    }
};