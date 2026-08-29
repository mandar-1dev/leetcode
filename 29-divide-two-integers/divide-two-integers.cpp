class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Keep doubling divisor
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest possible multiple
            a -= temp;
            ans += multiple;
        }

        // Determine sign
        if ((dividend < 0) != (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};