class Solution {
public:
    int reverse(int x) {
        long long z = 0;

        while (x != 0) {
            int y = x % 10;
            z = z * 10 + y;

            if (z > INT_MAX || z < INT_MIN)
                return 0;

            x /= 10;
        }

        return (int)z;
    }
};