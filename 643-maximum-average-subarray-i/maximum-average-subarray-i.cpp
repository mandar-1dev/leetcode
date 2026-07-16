class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];

        long long mx = sum;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            if (sum > mx)
                mx = sum;
        }

        return (double)mx / k;
    }
};


//New Window Sum = Previous Window Sum + New Element - Old Element

// [1,12,-5,-6]      sum = 2
//[12,-5,-6,50]     sum = 2 + 50 - 1 = 51
//[-5,-6,50,3]      sum = 51 + 3 - 12 = 42