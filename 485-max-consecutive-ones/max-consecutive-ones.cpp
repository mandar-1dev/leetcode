class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxSum=0,currSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currSum++;
               
            }
            else{
                maxSum=max(currSum,maxSum);
                currSum=0;
            }
        }
        return max(maxSum,currSum);
    }
};