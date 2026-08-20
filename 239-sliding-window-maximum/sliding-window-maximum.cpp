class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        ans.reserve(n - k + 1);

        int* q = new int[n]; // no zero-initialization
        int head = 0, tail = 0;

        // first window
        for (int i = 0; i < k; i++) {
            while (head < tail && nums[q[tail - 1]] <= nums[i]) {
                tail--;
            }
            q[tail++] = i;
        }

        ans.push_back(nums[q[head]]);

        // remaining windows
        for (int i = k; i < n; i++) {
            // remove expired index
            if (q[head] <= i - k) {
                head++;
            }

            // remove useless smaller/equal values
            while (head < tail && nums[q[tail - 1]] <= nums[i]) {
                tail--;
            }

            q[tail++] = i;
            ans.push_back(nums[q[head]]);
        }

        delete[] q;
        return ans;
    }
};