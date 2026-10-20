
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int x : nums) {
            int complement = k - x;

            if (freq[complement] > 0) {
                count++;
                freq[complement]--;
            } else {
                freq[x]++;
            }
        }

        return count;
    }
};
