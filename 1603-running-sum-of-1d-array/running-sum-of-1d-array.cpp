class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>arr;
        int sum=0;
        for(int val:nums){
            sum+=val;
            arr.push_back(sum);
        };
        return arr;
    }
};