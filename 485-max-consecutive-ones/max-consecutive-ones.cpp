class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currSum=0,maxSum=0;   
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currSum++;

            }
            else{
                maxSum=max(maxSum,currSum);
                currSum=0;
            }
        } 
        return max(maxSum,currSum);
    }
};