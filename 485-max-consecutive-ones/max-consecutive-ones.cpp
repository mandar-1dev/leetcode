class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_sum=0,curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr_sum++;
            }
            else{
                max_sum=max(curr_sum,max_sum);
                curr_sum=0;
            }
        }
        return max(max_sum,curr_sum);
    }
};