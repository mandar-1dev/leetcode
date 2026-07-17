class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = prefix % k;

            if (firstIndex.count(rem)) {
                if (i - firstIndex[rem] > 1)
                    return true;
            } else {
                firstIndex[rem] = i;
            }
        }

        return false;
    }
};