class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0,maxSum=INT_MIN;
        int currMin=0,minSum=INT_MAX;
        int total=0;
        for(int num:nums){
            currMax=max(num,currMax+num);
            maxSum=max(currMax,maxSum);

            currMin=min(num,currMin+num);
            minSum=min(currMin,minSum);
            
            total+=num;

            

        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,total-minSum);
    }
};