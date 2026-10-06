class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int num = left; num <= right; num++) {
            int n = num;
            bool valid = true;

            while (n > 0) {
                int digit = n % 10;

                // Number contains 0
                if (digit == 0 || num % digit != 0) {
                    valid = false;
                    break;
                }

                n /= 10;
            }

            if (valid) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};