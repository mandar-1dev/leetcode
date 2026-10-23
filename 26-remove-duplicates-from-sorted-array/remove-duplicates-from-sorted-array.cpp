
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int curr = nums[0];
        int j = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != curr) {
                nums[j] = nums[i];
                curr = nums[i];
                j++;
            }
        }

        return j;
    }
};
