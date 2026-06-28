class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>z;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    z.push_back(i);
                    z.push_back(j);
                }
            }
        }
        return z;
    }
};