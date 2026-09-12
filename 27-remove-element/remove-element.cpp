class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;

        for (int a : nums) {
            if (a != val) {
                nums[count] = a;
                count++;
            }
        }

        return count;
    }
};