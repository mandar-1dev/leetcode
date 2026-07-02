class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m == x / m)
                return (m + 1 > x / (m + 1)) ? m : m + 1;

            if (m < x / m)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};