class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2)
            return false;

        // Check for two consecutive multiples of k
        for (int i = 1; i < n; i++) {
            if (nums[i] % k == 0 && nums[i - 1] % k == 0)
                return true;
        }

        vector<int> prefixRemainders;

        for (int num : nums) {
            if (num % k == 0)
                continue;

            int rem = num % k;

            if (prefixRemainders.empty())
                prefixRemainders.push_back(rem);
            else
                prefixRemainders.push_back(
                    (prefixRemainders.back() + rem) % k
                );

            if (prefixRemainders.back() == 0)
                return true;
        }

        sort(prefixRemainders.begin(), prefixRemainders.end());

        for (int i = 1; i < prefixRemainders.size(); i++) {
            if (prefixRemainders[i] == prefixRemainders[i - 1])
                return true;
        }

        return false;
    }
};