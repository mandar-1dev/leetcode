class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int pivot = nums[right];
            int index = left;

            for (int i = left; i < right; i++) {
                if (nums[i] < pivot) {
                    swap(nums[i], nums[index]);
                    index++;
                }
            }

            swap(nums[index], nums[right]);

            if (index == target)
                return nums[index];

            if (index < target)
                left = index + 1;
            else
                right = index - 1;
        }

        return -1;
    }
};